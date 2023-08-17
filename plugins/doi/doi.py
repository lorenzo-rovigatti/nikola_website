# -*- coding: utf-8 -*-

# Copyright © 2023 Lorenzo Rovigatti.

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

from nikola.plugin_categories import ShortcodePlugin
from nikola.utils import req_missing

try:
    from crossref.restful import Works
except ImportError:
    Works = None

class DoiShortcodePlugin(ShortcodePlugin):
    """Return an HTML element containing the author list, title and publication year associated to a given DOI that can be styled as a tooltip"""
    
    name = "doi"
    
    def _error(self, msg):
        self.logger.error(msg)
        return '<div class="text-error">{}</div>'.format(msg)

    def handler(self, doi, text=None, site=None, data=None, lang=None, post=None):
        if Works is None:
            msg = req_missing(['crossrefapi'], 'use the doi shortcode', optional=True)
            return self._error(msg)
        
        works = Works()
        work = works.doi(doi)
        
        if text is None:
            text = doi
        
        if work is None:
            return self._error('Cannot find any item associated to "{0}"'.format(doi))
            
        doi_url = work['URL']
        authors = ", ".join([f"{author['given']} {author['family']}" for author in work['author']])
        title = work['title'][0]
        year = work['created']['date-parts'][0][0]

        tooltip = """
        <span class="doi_tooltip"><a href="{0}" target="_blank">{1}</a>
            <span class="doi_text">
                <span class="doi_authors">{2} ({3})</span>. 
                <span class="doi_title">{4}</span>. 
                <a href="{0}" target="_blank">{5}</a>
            </span>
        </span>""".format(doi_url, text, authors, year, title, work['DOI'])
        
        return tooltip, []
