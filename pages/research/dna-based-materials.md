<!--
.. title: DNA-based materials
.. slug: dna-based-materials
.. date: 2023-07-26 17:09:01 UTC+02:00
.. tags: 
.. category: research
.. link: 
.. description: 
.. type: text
-->

# Introduction

<div style="float:left">
  <img src="/images/research/DNA_cartoon.png">
</div>

The usual way of looking at {{% wikipedia article=DNA %}}  (deoxyribonucleic acid) is to consider it "just" an instruction manual, a huge recipe book if you will, that tells your body how to make you. This book, the genetic code, which is in essentially every cell of your body, contains chapters (known as genes) that hold the recipes (or instructions) for making everything about you, from your hair color to your height. These instructions are written in a special code made up of just four letters called nucleotides: adenine (A), thymine (T), guanine (G), and cytosine (C). Each nucleotide is composed of a sugar and a phosphate, common to all four, and of a base that is unique to the each type of nucleotide. The DNA that is stored in the cell is composed of two very long molecules (also known as *DNA single strands*) that pair up to create a twisting ladder structure called a double helix. The two strands are held together by hydrogen bonds, which are particular types of attractive bonds that can connect pairs of compatible nucleotides - A with T and C with G - to form a *base pair*. The image on the left, taken from Wikipedia, shows a cartoon of the DNA double helix.

# DNA as a building block

DNA is not only the blueprint for life, but it can also be used as a building material at the nanoscale, as shwon for the first time by the pioneering work of {{% wikipedia article="Nadrian Seeman" text="Ned Seeman" %}}: In the 1980s, Seeman had the brilliant idea to harness DNA's unique properties to create three-dimensional structures at a scale thousands of times smaller than a human hair. Using the natural binding properties of DNA strands, he designed and assembled DNA molecules into specific geometric shapes, effectively creating a new field known as {{% wikipedia article="DNA nanotechnology" %}}. This approach has the potential to revolutionize many fields, from medicine to computing, by enabling the creation of custom-designed, tiny structures that can carry out specific tasks, like delivering drugs directly to cancer cells, or creating super-fast, super-small computer circuits. 

:::{important}
Seeman's vision turned DNA from a passive instruction manual to an active building material, opening up a whole new world of possibilities at the nanoscale.
:::

DNA-based materials represent a growing field of nanotechnology and material science, taking advantage of the natural properties of DNA to create highly controlled, programmable synthetic structures at the nanoscale. The core concept that makes these materials appealing is the possibility of leveraging the specificity of base pairing in DNA to produce precise, predictable and complex self-assembling systems.

These DNA-based materials are not only unique in their programmability, but also biocompatible, biodegradable, and able to operate under physiological conditions, making them ideal for numerous applications. The opportunities range from drug delivery and biomedical applications to use in optics, electronics, and the creation of self-assembled nanodevices.

# DNA nanostars

A DNA nanostar is a multi-branched DNA structure that is synthesized using the principles of DNA self-assembly. The branches of these nanostars are formed from double-stranded DNA, and they all converge at a central point, creating a star-like structure. The tips of the branches can be functionalised (for instance with single-stranded sticky ends) to endow the nanostars with the ability of forming inter-star bonds. DNA nanostars can range from a simple three-arm structure (*i.e.* a trimer) to more complex multi-branched systems.

The unique geometrical properties of DNA nanostars, combined with the programmability of DNA, can be exploited for a wide range of applications, from biosensing and drug delivery to nanoelectronics and plasmonics. Moreover, DNA nanostars' size, shape, and functionality can be precisely controlled, making them a versatile tool in nanotechnology. However, their size does not usually extend beyond a few tens of nanometers, and are in general rather flexible nanostructures. As a result, the class of materials they can assemble into is somewhat limited.

:::{tip}
Use the buttons below to load configurations of different DNA nanostars in [oxView](https://sulcgroup.github.io/oxdna-viewer/) and use your mouse to zoom in/out or look around.
:::

<fieldset id="nanostars" class="oxview-buttons">
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/tetramer.top %}}', '{{% rel_url dst=/configurations/tetramer.dat %}}', 'oxview-nanostars', {'Arrows' : false})">A tetramer</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/trimer.top %}}', '{{% rel_url dst=/configurations/trimer.dat %}}', 'oxview-nanostars', {'Arrows' : false})">A trimer</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/trimer_tetramer.top %}}', '{{% rel_url dst=/configurations/trimer_tetramer.dat %}}', 'oxview-nanostars', {'Arrows' : false})">Two bonded nanostars</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/nanostar_fluid.top %}}', '{{% rel_url dst=/configurations/nanostar_fluid.dat %}}', 'oxview-nanostars', {'Box' : true, 'Arrows' : false})">Many bonded nanostars</button>
    <br/>
    <iframe width="100%" height="500" src="https://sulcgroup.github.io/oxdna-viewer/" id="oxview-nanostars" onload="set_buttons_status('nanostars', false)"></iframe>
</fieldset>

# DNA origami

One of the main characters of this field of research is {{% wikipedia article="DNA origami" %}},  composed by long strands of DNA that are folded into desired shapes using short strands, resulting in structures that can range from simple 2D shapes to more complex 3D configurations. This technique, introduced by [P. W. K. Rothemund in 2006](https://doi.org/10.1038/nature04586), provides an incredible level of control over the size (up to hundreds of nanometers in some cases), shape, mechanics and function of the structures produced.

The short movie below shows the basic idea of DNA origami: the desired structure (here a smiley face) is formed by a long strand, also known as the *scaffold* - usually of a viral origin, here depicted in red - held in place by short *staple* strands, which appear one after the other in the second part of the movie.

<video controls>
    <source src="/movies/origami.webm" type="video/webm">
</video>

:::{tip}
Use the buttons below to load configurations of different DNA origami in [oxView](https://sulcgroup.github.io/oxdna-viewer/) and use your mouse to zoom in/out or look around. Additional details about the leaf-spring engine can be found [here](https://www.biorxiv.org/content/10.1101/2021.12.22.473833v1).
:::

<fieldset id="origami" class="oxview-buttons">
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/smiley.top %}}', '{{% rel_url dst=/configurations/smiley.dat %}}', 'oxview-origami', {'Arrows' : false})">A smiley</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/tetrahedron.top %}}', '{{% rel_url dst=/configurations/tetrahedron.dat %}}', 'oxview-origami', {'Arrows' : false})">A tetrahedron</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/leaf_spring.top %}}', '{{% rel_url dst=/configurations/leaf_spring.dat %}}', 'oxview-origami', {'Arrows' : false})">A leaf-spring engine</button>
    <iframe disabled width="100%" height="500"  src="https://sulcgroup.github.io/oxdna-viewer/" id="oxview-origami" onload="set_buttons_status('origami', false)"></iframe>
</fieldset>

