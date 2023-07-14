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

:::{note}
I use an [anaconda](https://www.anaconda.com/) environment (unoriginally called `nikola`) to build my site, which means that nikola's files are stored in `/path/to/anaconda/envs/nikola/lib/python3.XX/sites-packages/nikola`, where `XX` is the environment's python version (10 in my case). This is useful whenever I need to inspect some source file to understand what's going on under the hood, or look at how things are implemented (mostly in template files).

In the following, paths starting with `NIKOLA` are relative to the foregoing nikola's source dir, while paths starting with `/` are relative to the website's source root folder.
:::

# Templates

The theme you are using may lack a template file for a specific page. In my case, `listing.tmpl` was missing. Therefore I copied the `NIKOLA/data/themes/base/templates/listing.tmpl` file over to `/themes/my_theme/templates` and edited it to make its structure similar to my theme's other `tmpl` files.

# Math support

With Nikola you can enable math support for a specific page by adding `has_math: true` to its metadata. However, if you use long equations and want to support devices with small screens, remember to add `"HTML-CSS": { linebreaks: { automatic: true } },` to MathJax's config in `conf.py`. **Nota Bene:** As of now (July 2023), automatic line breaks [are not supported in MathJax 3](https://docs.mathjax.org/en/latest/output/linebreaks.html).
