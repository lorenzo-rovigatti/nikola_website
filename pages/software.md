<!--
.. title: Software
.. slug: software
.. date: 2024-04-03 18:25:27 UTC+02:00
.. tags:
.. category:
.. link:
.. description:
.. type: text
-->

Here is a list of open-source software I have developed (by my own or in collaboration with other people) that could be useful to other researchers:

* [oxDNA](https://github.com/lorenzo-rovigatti/oxDNA): is a molecular simulation code that is mostly used to run simulations of the [oxDNA/oxRNA coarse-grained models](https://dna.physics.ox.ac.uk/index.php/Main_Page), although it supports many other models. It can run on single CPU cores or single GPUs. More details can be found {{% doi 10.21105/joss.04693 text="here" %}}.
* [cogli2](https://sourceforge.net/projects/cogli1/) is a a simple tool to visualise configurations of coarse-grained simulations. It is straightforward to use and it is designed to facilitate the making of publication-ready figures.
* [PatchyParticles](https://github.com/lorenzo-rovigatti/PatchyParticles) is a code for perfoming Monte Carlo simulations of hard particles decorated with four patches modelled through the Kern-Frenkel pair interaction potential. It was originally developed to accompany a {{% doi 10.1140/epje/i2018-11667-x text="review paper" %}}.
* [tacoxDNA](https://github.com/lorenzo-rovigatti/tacoxDNA) is a collection of tools to generate oxDNA configurations starting from other formats, as described {{% doi 10.1002/jcc.26029 text="here" %}}.
* [pyrla](https://github.com/lorenzo-rovigatti/pyrla) is a Python script that launches parallel processes executing different commands. Its most common use case is to build a hierarchy of directories (*e.g.* `Temperature_T/Pressure_P`, for several values of `P` and `T`), and then launch a (possibly different) command in each one.
* [baggianalysis](https://github.com/lorenzo-rovigatti/baggianalysis) is a library aimed at simplifying the analysis of particle-based simulations. It makes it easy to parse, convert and analyse trajectories generated by simulation codes in an agnostic way. It is written in C++ and comes with Python bindings.
