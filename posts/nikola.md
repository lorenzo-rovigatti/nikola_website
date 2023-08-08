<!--
.. title: Nikola tips
.. slug: nikola
.. date: 2023-07-02 21:41:48 UTC+02:00
.. tags: nikola, tips
.. category: development
.. link: 
.. description: 
.. type: text
-->

```{contents} Table of Contents
:depth: 2
:backlinks: none
```

:::{note}
I use an [anaconda](https://www.anaconda.com/) environment (unoriginally called `nikola`) to build my site, which means that nikola's files are stored in `/path/to/anaconda/envs/nikola/lib/python3.XX/sites-packages/nikola`, where `XX` is the environment's python version (10 in my case). This is useful whenever I need to inspect some source file to understand what's going on under the hood, or look at how things are implemented (mostly in template files).

In the following, paths starting with `NIKOLA` are relative to the foregoing nikola's source dir, while paths starting with `/` are relative to the website's source root folder.
:::

# Templates

The theme you are using may lack a template file for a specific page. In my case, `listing.tmpl` was missing. Therefore I copied the `NIKOLA/data/themes/base/templates/listing.tmpl` file over to `/themes/my_theme/templates` and edited it to make its structure similar to my theme's other `tmpl` files.

# Math support

With Nikola you can enable math support for a specific page by adding `has_math: true` to its metadata. However, if you use long equations and want to support devices with small screens, remember to add `"HTML-CSS": { linebreaks: { automatic: true } },` to MathJax's config in `conf.py`. 

:::{warning}
As of now (July 2023), automatic line breaks [are not supported in MathJax 3](https://docs.mathjax.org/en/latest/output/linebreaks.html).
:::

# Images

By default Nikola creates thumbnails for each image you put into the `images` folder (or subfolders). If you don't need thumbnails and want to save compiling time and disk space you can put everything in `files/images` instead. This has the benefit of keeping all the paths valid, since in either case images will be placed in `/images/path/to/image.jpg`.

# Relative links

I wrote a javascript function that takes paths to data files stored in a given folder as arguments. As always, paths can be relative to the current page or absolute. If one chooses the former approach, if the page is moved somewhere else the links may break, which is why I tend to prefer absolute links. Often the best of way of specifying absolute links on a website is to have something like `/path/to/dest`. 

As far as I understand, nikola translates all absolute links specified in this way to relative links, so that these links work regardless of the root URL (*i.e.* if the website is browsed locally, if it's deployed on a first-level domain or as a subfolder). Unfortunately, nikola doesn't do the same to paths specified not in link (*e.g.* in javascript code, as in my case). As a result, I needed a way of translating these absolute paths to relative paths. In order to do so I tried to use [template-based shortcodes](https://getnikola.com/extending.html#template-based-shortcodes) and put the following code in the `/shortcodes/rel_url.tmpl` path:

```
${rel_link(post.permalink(), dst)} 
```

This shortcode calls nikola's [rel_link](https://docs.getnikola.com/en/latest/nikola.html#nikola.nikola.Nikola.rel_link) method, passing it the current post's permalink and the destination path specified by the user, and can be used like this in a page or post:

```javascript
let my_path = '{{% rel_url dst=/my_file/file.dat %}}';
```

Unfortunately, the snippet above will result in something like this:

```javascript
let my_path = '../../my_file/file.dat
';
```

since, as far as I understand, nikola adds a trailing new line to the output of template-based shortcodes. A workaround would be to surround the shortcode's code with single (or double) quotes, making the plugin less general and more prone to subtle bugs.

The solution I found was to add a "proper" plugin, since nikola apparently uses its output *verbatim*, without adding newlines or other whitespace. In order to do so I simply created a `/plugins/rel_url` folder and added these two files in it:

`rel_url.plugin`
```
[Core]
Name = rel_url
Module = rel_url

[Nikola]
PluginCategory = Shortcode

[Documentation]
Author = Lorenzo Rovigatti
Version = 0.1
Website = https://www.roma1.infn.it/~rovigatl/
Description = Generate a relative URL
```

`rel_url.py`
```python
from nikola.plugin_categories import ShortcodePlugin

class RelUrlShortcodePlugin(ShortcodePlugin):
    """Return a relative URL."""
    
    name = "rel_url"

    def handler(self, dst, site=None, data=None, lang=None, post=None):
        link = site.rel_link(post.permalink(), dst)
        
        return link, []
```
