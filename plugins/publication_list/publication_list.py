# -*- coding: utf-8 -*-

# Copyright © 2016-2017 Hong Xu <hong@topbug.net>.

# Permission is hereby granted, free of charge, to any
# person obtaining a copy of this software and associated
# documentation files (the "Software"), to deal in the
# Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the
# Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice
# shall be included in all copies or substantial portions of
# the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
# OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
# OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
# SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

import os
import sys

from docutils import nodes
from docutils.parsers.rst import Directive, directives

from nikola.plugin_categories import RestExtension
from nikola.utils import get_logger, STDERR_HANDLER

from pybtex.database import BibliographyData, Entry
from pybtex.database.input.bibtex import Parser
from pybtex.markup import LaTeXParser
from pybtex.style.formatting.unsrt import Style as UnsrtStyle
from pybtex.style.template import href, tag, FieldIsMissing


LOGGER = get_logger('scan_posts', STDERR_HANDLER)

class Style(UnsrtStyle):
    """The style for publication listing. It hyperlinks the title to the detail page if user sets it and abbreviate names.
    """

    def __init__(self, detail_page_url):
        super().__init__(abbreviate_names=True)
        self.detail_page_url = detail_page_url

    def format_title(self, e, which_field, as_sentence=True):
        "Override the UnsrtStyle format_title(), so we have the title hyperlinked."

        title = tag('strong')[super().format_title(e, which_field, as_sentence)]

        if self.detail_page_url:
            url = '/'.join((self.detail_page_url, e.label + '.html'))
            return href[url, title]
        else:
            return title


class Plugin(RestExtension):

    name = "publication_list"

    def set_site(self, site):
        self.site = site
        directives.register_directive('publication_list', PublicationList)
        PublicationList.site = self.site
        PublicationList.output_folder = self.site.config['OUTPUT_FOLDER']
        return super(Plugin, self).set_site(site)


class PublicationList(Directive):
    """
    Directive to list publications.
    """
    has_content = False
    required_arguments = 1
    optional_arguments = sys.maxsize
    option_spec = {
        'bibtex_dir': directives.unchanged,
        'detail_page_dir': directives.unchanged,
        'highlight_author': directives.unchanged,
        'style': directives.unchanged
    }
    
    def _toggle_visibility(self, link_name, target_name):
        return '''
        [<a href="javascript:void(0)" onclick="
        (function(link, target) {{
            var target_dom = document.getElementById(target);
            if (target_dom.style.display === 'none') {{
                target_dom.style.display = 'block';
                link.innerHTML = '{}&#x25B2;'
            }} 
            else {{
                target_dom.style.display = 'none';
                link.innerHTML = '{}&#x25BC;'
            }}
        }})(this, '{}');">{}&#x25BC;</a>]
        '''.format(link_name, link_name, target_name, link_name)
        
    def _preprocess_bibtex(self, fn):
        # copied from https://stackoverflow.com/questions/66614694/how-to-change-the-same-keys-related-to-different-articles-in-bibtex
        from nanoid import generate
        import re
        from tempfile import mkstemp
        
        with open(fn, encoding="utf-8") as r_file:
            bibtex = r_file.read()
        pattern = r"@([\w\W]+?){([\w\W0-9_\-]+?),"
        def callback(matchobj):
            return f"@{matchobj.group(1)}{{Rovigatti-{generate(size=8)},"
                                        
        descriptor, path = mkstemp()
        with open(path, "w", encoding="utf-8") as w_file:
            w_file.write(re.sub(pattern, callback, bibtex))
            
        return path

    def run(self):

        bibtex_dir = self.options.get('bibtex_dir', 'bibtex')
        detail_page_dir = self.options.get('detail_page_dir', 'papers')
        highlight_authors = self.options.get('highlight_author', None)
        if highlight_authors:
            highlight_authors = [author.strip().replace(' ', '&nbsp;') for author in highlight_authors.split(';')]
            
        style = Style(self.site.config['BASE_URL'] + detail_page_dir if detail_page_dir else None)
        self.state.document.settings.record_dependencies.add(*self.arguments)

        all_entries = []
        labels = set()
        for a in self.arguments:
            parser = Parser()
            preprocessed_file = self._preprocess_bibtex(a)
            entries = parser.parse_file(preprocessed_file).entries
            for item in entries.items():
                if item[0] in labels:  # duplicated entries
                    LOGGER.warning(
                        ("publication_list: BibTeX entries with duplicated labels are found. "
                         "Only the first occurrence will be used."))
                    continue
                labels.add(item[0])
                all_entries.append(item)
        # Sort the publication entries by year reversed
        data = sorted(all_entries, key=lambda e: e[1].fields['year'], reverse=True)

        cur_year = None
        years = []
        html = ""

        if bibtex_dir:  # create the bibtex dir if the option is set
            try:
                os.makedirs(os.path.sep.join((self.output_folder, bibtex_dir)))
            except OSError:  # probably because the dir already exists
                pass

        if detail_page_dir:  # create the detail page dir if the option is set
            try:
                os.makedirs(os.path.sep.join((self.output_folder, detail_page_dir)))
            except OSError:  # probably because the dir already exists
                pass

        for label, entry in data:
            # print a year title when year changes
            if entry.fields['year'] != cur_year:
                if cur_year is not None:  # not first year group
                    html += '</ul>'
                cur_year = entry.fields['year']
                years.append(cur_year)
                html += '<h2 id="{}">{}<a href="javascript:scroll_to_year_list()">&uarr;</a></h2>\n<ul>'.format(cur_year, cur_year)

            entry.label = label  # Pass label to the style.
            # delete some fields we do not want to show
            for to_del in ["note", "url"]:
                if to_del in entry.fields:
                    del entry.fields[to_del]
            
            try:
                formatted = list(style.format_entries((entry,)))[0]
            except FieldIsMissing as e:
                entry.fields[e.field_name] = ""
                formatted = list(style.format_entries((entry,)))[0]
            pub_html = formatted.text.render_as('html')
            
            if highlight_authors:
                for highlight_author in highlight_authors:
                    with open("/tmp/prova", "w") as f:
                        print("'" + highlight_author + "'", file=f)
                    pub_html = pub_html.replace(highlight_author, '<strong>{}</strong>'.format(highlight_author), 1)
                    
            html += '<li class="publication" style="padding-bottom: 1em;">' + pub_html

            extra_links = ""

            if 'fulltext' in entry.fields:  # the link to the full text, usually a link to the pdf file
                extra_links += '[<a href="{}">full text</a>] '.format(entry.fields['fulltext'])

            bibtex_fields = dict(entry.fields)
            # Collect and remove custom links (fields starting with "customlink")
            custom_links = dict()
            for key, value in bibtex_fields.items():
                if key.startswith('customlink'):
                    custom_links[key[len('customlink'):]] = value
            # custom fields (custom links)
            for key, value in custom_links.items():
                extra_links += '[<a href="{}">{}</a>] '.format(value, key)

            # Remove some fields for the publicly available BibTeX file since they are mostly only
            # used by this plugin.
            for field_to_remove in ('abstract', 'fulltext'):
                if field_to_remove in bibtex_fields:
                    del bibtex_fields[field_to_remove]
            # Prepare for the bib file. Note detail_page_dir may need bib_data later.
            bibtex_entry = Entry(entry.type, bibtex_fields, entry.persons)
            bib_data = BibliographyData(dict({label: bibtex_entry}))
            bib_string = bib_data.to_string('bibtex')
            extra_links += self._toggle_visibility('BibTeX', 'bibtex-' + label)
            if bibtex_dir:  # write bib files to bibtex_dir for downloading
                bib_link = '{}/{}.bib'.format(bibtex_dir, label)
                bib_data.to_file('/'.join([self.output_folder, bib_link]), 'bibtex')

            if extra_links or detail_page_dir or 'abstract' in entry.fields:
                html += '<br>'

            # Add the abstract link.
            if 'abstract' in entry.fields:
                html += self._toggle_visibility('abstract', 'abstract-' + label)

            display_none = '<div id="{}" style="display:none"><pre>{}</pre></div>'
            bibtex_display = display_none.format(
                'bibtex-' + label, bib_string)

            abstract_text = str(
                LaTeXParser(entry.fields['abstract']).parse()) if 'abstract' in entry.fields else ''
            if detail_page_dir:  # render the details page of a paper
                page_url = '/'.join((detail_page_dir, label + '.html'))
                html += '[<a href="{}">details</a>] '.format(
                    self.site.config['BASE_URL'] + page_url)
                context = {
                    'title': str(LaTeXParser(entry.fields['title']).parse()),
                    'abstract': abstract_text,
                    'bibtex': bib_data.to_string('bibtex'),
                    'bibtex_link': '/' + bib_link if bibtex_dir else '',
                    'default_lang': self.site.config['DEFAULT_LANG'],
                    'label': label,
                    'lang': self.site.config['DEFAULT_LANG'],
                    'permalink': self.site.config['SITE_URL'] + page_url,
                    'reference': pub_html,
                    'extra_links': extra_links + bibtex_display
                }

                if 'fulltext' in entry.fields:
                    context['pdf'] = entry.fields['fulltext']

                self.site.render_template(
                    'publication.tmpl',
                    os.path.sep.join((self.output_folder, detail_page_dir, label + '.html')),
                    context,
                )

            html += extra_links

            # Add the hidden abstract and bibtex.
            if 'abstract' in entry.fields:
                html += '''
                <div id="{}" class="publication-abstract" style="display:none">
                <blockquote>{}</blockquote></div>
                '''.format('abstract-' + label, abstract_text)
            html += bibtex_display
            html += '</li>'

        if len(data) != 0:  # publication list is nonempty
            html += '</ul>'
            
        # create a list of years that can be used to jump around the page more easily
        year_list = '<ul id="publication-year-list">\n'
        year_list += "\n".join(['<li><a href="#{}">{}</a></li>'.format(year, year) for year in years]) + '\n'
        year_list += '</ul>\n'

        final_html = '<div id="publication-list">\n'
        final_html += year_list
        final_html += html
        final_html += '</div>'

        return [nodes.raw('', final_html, format='html'), ]
