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

DNA-based materials represent a growing field of nanotechnology and material science, taking advantage of the natural properties of deoxyribonucleic acid (DNA) to create highly controlled, programmable structures at the nanoscale. The core concept that makes these materials appealing is the possibility of leveraging the specificity of base pairing in DNA - adenine (A) with thymine (T), and guanine (G) with cytosine (C) - to produce precise, predictable and complex self-assembling systems.

These DNA-based materials are not only unique in their programmability, but also biocompatible, biodegradable, and able to operate under physiological conditions, making them ideal for numerous applications. The opportunities range from drug delivery and biomedical applications to use in optics, electronics, and the creation of self-assembled nanodevices.

## DNA nanostars

A DNA nanostar is a multi-branched DNA structure that is synthesized using the principles of DNA self-assembly. The branches of these nanostars are formed from double-stranded DNA, and they all converge at a central point, creating a star-like structure. The tips of the branches can be functionalised (for instance with single-stranded sticky ends) to endow the nanostars with the ability of forming inter-star bonds. DNA nanostars can range from a simple three-arm structure to more complex multi-branched systems.

The unique geometrical properties of DNA nanostars, combined with the programmability of DNA, can be exploited for a wide range of applications, from biosensing and drug delivery to nanoelectronics and plasmonics. Moreover, DNA nanostars' size, shape, and functionality can be precisely controlled, making them a versatile tool in nanotechnology. However, their size does not usually extend beyond a few tens of nanometers, and are in general rather flexible nanostructures. As a result, the class of materials they can assemble into is somewhat limited.

Use the buttons below to load configurations of different DNA nanostars in [oxView](https://sulcgroup.github.io/oxdna-viewer/) and use your mouse to zoom in/out or look around.

<fieldset id="nanostars" class="oxview-buttons">
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/tetramer.top %}}', '{{% rel_url dst=/configurations/tetramer.dat %}}', 'oxview-nanostars', {'Arrows' : false})">A tetramer</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/trimer.top %}}', '{{% rel_url dst=/configurations/trimer.dat %}}', 'oxview-nanostars', {'Arrows' : false})">A trimer</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/trimer_tetramer.top %}}', '{{% rel_url dst=/configurations/trimer_tetramer.dat %}}', 'oxview-nanostars', {'Arrows' : false})">Two bonded nanostars</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/nanostar_fluid.top %}}', '{{% rel_url dst=/configurations/nanostar_fluid.dat %}}', 'oxview-nanostars', {'Box' : true, 'Arrows' : false})">Many bonded nanostars</button>
    <br/>
    <iframe width="100%" height="500" src="https://sulcgroup.github.io/oxdna-viewer/" id="oxview-nanostars" onload="set_buttons_status('nanostars', false)"></iframe>
</fieldset>

## DNA origami

One of the main characters of this field of research is DNA origami, composed by long strands of DNA that are folded into desired shapes using shorter staple strands, resulting in structures that can range from simple 2D shapes to more complex 3D configurations. This technique provides an incredible level of control over the size, shape, and function of the materials being produced. These structures are bigger than nanostars (up to hundreds of nanometers in the case of tubular origami), and their mechanical properties can be tuned very finely.

Use the buttons below to load configurations of different DNA origami [oxView](https://sulcgroup.github.io/oxdna-viewer/) and use your mouse to zoom in/out or look around.

<fieldset id="origami" class="oxview-buttons">
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/smiley.top %}}', '{{% rel_url dst=/configurations/smiley.dat %}}', 'oxview-origami', {'Arrows' : false})">A smiley</button>
    <button disabled onclick="load_oxview_conf('{{% rel_url dst=/configurations/tetrahedron.top %}}', '{{% rel_url dst=/configurations/tetrahedron.dat %}}', 'oxview-origami', {'Arrows' : false})">A tetrahedron</button>
    <iframe disabled width="100%" height="500"  src="https://sulcgroup.github.io/oxdna-viewer/" id="oxview-origami" onload="set_buttons_status('origami', false)"></iframe>
</fieldset>

