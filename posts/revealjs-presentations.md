<!--
.. title: reveal.js presentations
.. slug: revealjs-presentations
.. date: 2023-08-08 14:12:36 UTC+02:00
.. tags: nikola
.. category: development
.. link: 
.. description: 
.. type: text
-->

```{contents} Table of Contents
:depth: 2
:backlinks: none
```

# The problem

A few years ago I started using [reveal.js](https://revealjs.com/) to prepare my scientific talks and I never looked back since then. Now I use it also for the <a href="link://slug/labcalc">programming class</a> I teach to first-year students!

The only thing I hate about reveal.js is its PDF-exporting features: perhaps it is my fault (although I have [rtfm'd](https://revealjs.com/pdf-export/)), but I never managed to generate a PDF that faithfully reproduced my presentation. And of course PDFs don't support movies (in a portable and reliable manner).

When I decided to use Nikola to build my website I thought that I could maybe find a way of making my presentations available online as HTML pages. I didn't find any resources on the topic online, but I used what I learned about Nikola in those last weeks and I hacked up my own solution, which I'm going to describe here.

# The strategy

The basic idea is to have a custom template page `reveal.tmpl` that 

1. loads the necessary reveal (and possibly custom) javascript and css files required to display the presentation
2. sets up the HTML bits that will contain the markdown/HTML code.

The (markdown/HTML) content of each presentation is then copied in an HTML file containing the special `.. template: reveal.tmpl` metadata overriding the default template file for pages.

# The template file

If you are curious you can look at (and download) the custom template I have written <a href="link://listing/reveal.tmpl">here</a>, which depends on the theme I'm using (a modified version of [bnw](https://themes.getnikola.com/v8/bnw/)) to output the first part of the HTML page. Here I will describe the most important parts of the template.

I decided to use reveal.js version 4.1.2 and load the relevant file through a CDN, but the same procedure should work with any version and/or files stored elsewhere.

We start with loading the CSS files in the `<head>` element:

```html
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/reset.min.css">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/reveal.min.css">
<link rel="stylesheet" href="/assets/css/slides.css">
```

Here `slides.css` is the file containing my custom CSS styles. 

Within the `<body>` element there is the reveal.js HTML boilerplate, where `${post.text()}` will be replaced by each presentation's content:

```html
<div class="reveal">
    <div class="slides">
        <section data-markdown>
            <textarea data-template>
                ${post.text()}
            </textarea>
        </section>
    </div>
</div>
```

Finally, just before `</body>` there is the import and initialisation of reveal.js's javascript machinery:

```html
<script src="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/reveal.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/plugin/notes/notes.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/plugin/markdown/markdown.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/plugin/highlight/highlight.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/plugin/math/math.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/reveal.js/4.1.2/plugin/zoom/zoom.min.js"></script>
<script>
Reveal.initialize({
    hash: true,
    
    math: {
        mathjax: 'https://cdn.jsdelivr.net/gh/mathjax/mathjax@2.7.8/MathJax.js',
        config: 'TeX-AMS_HTML-full',
    },
    
    markdown: {
        smartypants: true
    },
    
    slideNumber: 'c/t',
    showSlideNumber: 'all',

    plugins: [ RevealMarkdown, RevealHighlight, RevealNotes, RevealMath, RevealZoom ]
});
</script>
```

# The presentation page file

Since we use HTML files to store presentations styled with reveal.js, we first need to make sure that HTML pages are enabled in the `conf.py` file. The relevant part of my configuration is as follows:

```python
PAGES = (
    ("pages/*.md", "", "page.tmpl"),
    ("pages/*.rst", "", "page.tmpl"),
    ("pages/*.html", "", "page.tmpl"),
)
```

We then create a new HTML page (with `nikola new_page -f html` for instance) and update its metadata to something like this:

```
<!--
.. title: My fancy seminar
.. slug: fancy_seminar
.. date: 2023-08-08 13:12:44 UTC+02:00
.. tags: 
.. category: seminars
.. link: 
.. description: 
.. type: text
.. template: reveal.tmpl
.. has_math: true
-->
```

where the most important bit is `.. template: reveal.tmpl`, where we override the default template.

The rest of the file should contain the presentation text. Here is an example:

```markdown

# This is a fancy seminar

## by Lorenzo Rovigatti

---

# Introduction

<img src="fancy_image.png">

```
