<!--
.. title: Computational Biophysics
.. slug: comp-bio
.. date: 2024-04-04 10:09:01 UTC+01:00
.. tags: 
.. category: teaching
.. link: 
.. description: 
.. type: text
-->

```{important}
Please enroll [here](https://elearning.uniroma1.it/course/view.php?id=18658) so that I can keep an updated list of students who attend the lectures.
```

As with most computational courses, this course is supposed to have a practical side that should not be overlooked. However, as some of you may have noticed, there will be frontal lessons only. While this may seem contradictory (and in some sense it is), it also means that you are strongly advised to practice on your (or someone else's) computer what you'll hear about (and be shown) during the lectures. Moreover, I will also set up some hands-on (bring-your-own-laptop) lectures to guide you through the most important technical hurdles we will be encountering.

:::{note}
The course will start Thursday September 26th. The lecture schedule is the following:

* Monday 13-15, Aula 3
* Tuesday 12-14, Aula 7
* Thursday 16-18, Aula 8

**Nota Bene:** The reason why there are six hours per week (instead of five) will be explained during the first lesson. However, rest assured that no more than 60 hours will be used.
:::

# Program

Since this is the first year I teach this course, the following outline (as well as the estimated time for each argument) should be seen as tentative:

* Introduction to biophysics (one lesson)
  * Macromolecules
  * Central dogma and its accompanying machinery
* Introducton to computational physics (two lessons)
  * Crash course on Python
  * An example: dynamic programming
* Introduction to proteins (five lessons)
  * Amino acids
  * Van der Waals forces, hydrogen bonds and electrostatic interactions
  * Primary, secondary, ternary and quaternary structures
* Introduction to nucleic acids (four lessons)
  * Nucleotides
  * Hybridisation
  * Secondary and ternary structures
* Folding, design and structure prediction of proteins and nucleic acids (seven lessons)
  * Folding and unfolding
  * The Zimm-Bragg model
  * The Hydrophobic-Polar model
  * Sequence alignment
  * Structure alignment
  * Prediction of DNA/RNA secondary structures
* An introduction to quantum molecular mechanics (one lesson)
  * Density functional theory
  * Car-Parrinello method
* An introduction to molecular dynamics (four lessons)
  * Main algorithms
  * Tricks of the trade
  * Useful observables (radial distribution function, pressure, *etc.*)
  * All-atom force fields
* Coarse-grained models (two lessons)
  * Bottom-up coarse-graining
  * Top-bottom coarse-graining
* Enhanced sampling techniques (three lessons)
  * Umbrella sampling
  * Thermodynamic and Hamiltonian integration
  * Metadynamics

# Prerequisites

1. This is a computational course, and as such it requires some proficiency with (or at least having the right attitude towards) computers. The most important skill you will need is to use a terminal, since most of the computations (running simulations, analysing results, *etc.*) will be launched from there. Linux and macOS come with pre-installed terminals, while Windows does not[^windows_terminal]. However, it is possible to install a very handy ["Windows Subsystem for Linux"](https://learn.microsoft.com/en-us/windows/wsl/) that makes it possible to have a good Linux-like experience within Windows. Install instructions can be found [here](https://learn.microsoft.com/en-us/windows/wsl/install).
2. Knowing to code is important, for several reasons. First of all, implementing algorithms and techniques introduced in class is the best way of understanding how they work and what are their advantages and disadvantages, even though most of research-grade results during one's career will be obtained with production-ready HPC codes written by others. Secondly, reading other people's code can come in very handy (i) to understand what it does and (ii) to extend it to suit your needs. Finally, in computational physics it is common to need to perform custom analyses for which no libraries or codes are available, leaving no other option than writing your own script or program. For the sake of the course, the programming language you are more familiar with is not important, although Python is the *de facto* standard language used to write analysis scripts, while C and C++ (and more rarely FORTRAN) are used to write performance-critical software (or part thereof).
3. By definition, life is an out-of-equilibrium process, since it continuously uses up energy. However, many biophysical processes are in (or close to) equilibrium. Therefore, they can be analysed and understood using the language of thermodynamics and statistical mechanics. You should be familiar with concepts such as free energy, entropy, ensembles, partition function, Boltzmann distribution, as well as with the mathematical tools used to work with these quantities.
4. *Any* knowledge of biology and biochemistry is welcome (and will be useful to its holder). However, I will introduce most of what we need at the beginning, and then some more as the need arises.

[^windows_terminal]: Or at least it does not come with a Unix-like (POSIX) terminal, which is what we will be using.

# Notes

I'm compiling the course's notes, which can be found [here](https://lorenzo-rovigatti.github.io/comp_bio_notes/). Note that this is a super-early, uncomplete version. You are welcome to use them to guide your study, but please

1. Use books and/or original articles whenever they are cited
2. Do not assume that everything it's written is correct. It's probably not.
3. Do not assume that the actual lectures will reflect the full content of the notes.
4. Feedback (of any nature) is very welcome.
