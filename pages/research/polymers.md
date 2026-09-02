<!--
.. title: Polymers and microgels
.. slug: polymers-and-microgels
.. date: 2025-04-10 17:09:01 UTC+02:00
.. tags: 
.. category: research
.. link: 
.. description: 
.. type: text
.. has_math: true
-->

# Introduction

{{% wikipedia article="Polymer" text="Polymers" %}} are among the most common materials around us. They are found in plastic bottles, rubber bands, biological tissues, gels, coatings, and even in the structures that define some of the simplest forms of life. At the most basic level, a polymer is a macromolecule[^macromolecule], *i.e.* a long molecule made of many repeated units, the *monomers*. These units can be linked in many different ways, creating chains, rings, stars, brushes, or large interconnected networks.

This simple idea leads to an enormous range of behavior. A single chain can wiggle and fold, while a dense collection of chains can behave like a fluid, a soft solid, or a gel. The same chemistry can produce materials with very different properties depending on how the chains are connected, how many cross-links there are, and how the environment changes around them.

This is why polymer science is so fascinating: many of the properties we observe at the macroscopic scale are not obvious from the individual molecules alone. A material can look simple at first glance, yet its behavior can be controlled by subtle physical effects due to the interplay between entropy, thermal fluctuations, crowding, and the competition between bonding and excluded volume.

The same ideas also lie at the heart of our group's work on soft materials and colloids. A useful way to think about the field is that we try to connect molecular architecture to macroscopic behavior: how polymer chains are arranged and interact at the nanoscale can determine whether a material flows, gels, jams, or responds to temperature or confinement. A few representative examples can be found in papers on microgel interactions and elasticity, such as {{% doi 10.1038/s41467-018-07332-5 text="Bergman et al. (2018)" %}}, {{% doi 10.1021/acs.macromol.9b00099 text="Rovigatti et al. (2019)" %}}, and {{% doi 10.1103/PhysRevX.10.031012 text="Camerin et al. (2020)" %}}.

# Why polymers are interesting

A polymer is not just a long string. It is a flexible object with a huge number of possible conformations. Depending on temperature, solvent quality, and interactions between monomers, the same polymer can collapse into a compact object, stretch into a coil, or form complicated structures with other molecules.

This flexibility is responsible for many familiar phenomena. For example, the elastic properties of rubber come from the fact that polymer chains can change their conformations when stretched, while the viscosity of a polymer solution depends on how easily chains move past each other. These are not purely chemical effects: they are deeply rooted in physics. This means that many of the properties of polymeric materials can be understood using ideas from statistical mechanics and soft matter physics. In fact, one does not need the full microscopic detail of every atom to predict important behaviors, as much can be captured by coarse-grained models that focus on the essential ingredients: chain connectivity, excluded volume, attraction, and topology.

# From single chains to networks

The real richness of polymer science appears when many chains are connected together. If chains are linked into a network, the material can stop flowing like a liquid and instead resist deformation like a solid. This is the physics of gels and soft solids. A gel is a material that contains a connected network of polymer chains immersed in a solvent. The network can be permanent, as in a chemically cross-linked rubber, or transient, as in systems where bonds form and break over time. These reversible systems are particularly interesting because they can reorganize, relax, and respond to changes in the environment.

This is a central theme of our work: understanding how connectivity, bond lifetime, and architecture determine whether a polymer solution remains fluid-like or forms a percolating network, as well as its macroscopic properties (*i.e.* how it resists mechanical deformation). While we often think of gels as everyday objects (such as toothpaste, or ketchup), and therefore too mundane to be a subject of study, they are surprisingly complex materials that have resisted a thorough physical characterisation for decades. Indeed, a gel may be soft and squishy, but its structure is governed by a multiscale, delicate balance between entropy, interactions, and topology. This is closely related to the study of reversible gels and associative polymer systems, see for instance {{% doi 10.1021/acs.macromol.0c02670 text="Formanek et al. (2021)" %}} and {{% doi 10.1063/5.0279969 text="Tosti Guerra et al. (2025)" %}}.

# Microgels: soft, deformable colloids

<figure>
  <img src="/images/research/microgels.png">
  <figcaption>Snapshots of microgels generated with different numerical protocols and used to run computer simulations. (a) A diamond-lattice microgel, (b) a microgel assembled by pre-formed chains, (c) and (d) microgels built from mixtures of valence-limited particles assembled under two different concentration conditions. Image reproduced from {{% doi  10.1039/c8sm02089b
 text="Rovigatti et al. (2019)" %}}.</figcaption>
</figure>

One important class of materials in this context is that of microgels. A microgel is a colloidal particle made of a cross-linked polymer network, typically with a size ranging from tens of nanometers to a few micrometers (see figure above for examples of computer-generated microgels). Because the network is sparse and flexible, microgels can swell or shrink dramatically when the environment changes.

A paradigmatic example is the thermoresponsive microgel based on poly(N-isopropylacrylamide), usually abbreviated as PNIPAM. This polymer is swollen and relatively large at low temperature, but as temperature increases it collapses and expels solvent. This so-called *volume phase transition* gives microgels a remarkable property: they can change size in response to temperature, pH, salt concentration, or other external conditions.

This tunability makes microgels extremely useful as model systems for soft matter. In many respects, they are ideal building blocks for studying colloidal physics because they are soft, compressible, and deformable, unlike hard spheres. Their effective interactions are not fixed: they depend on size, softness, internal architecture, and crowding.

This is why they are important in fundamental research. Microgels help us understand how soft particles assemble, crystallize, jam, or form arrested phases. They also serve as excellent model systems for phenomena that are difficult to capture with simpler hard-sphere models. In our recent work, this has been explored in studies of microgel structure and swelling across the volume phase transition {{% doi 10.1021/acs.macromol.9b01122 text="(Ninarello et al., 2019)" %}}, effective interactions {{% doi 10.1038/s41467-018-07332-5 text="(Bergman et al., 2018)" %}}, and interfacial dynamics {{% doi 10.1103/PhysRevX.10.031012 text="(Camerin et al., 2020)" %}}.

# What do we study?

Our research sits at the intersection of polymer physics, colloids, and statistical mechanics. The questions we ask are often quite simple to state but difficult to answer:

- How do polymer networks form and rearrange?
- What controls the elastic response of soft materials?
- Why do some systems gel gradually while others undergo abrupt transitions?
- How does the internal structure of a microgel affect its collective behavior?
- Can we predict the effective interactions between soft particles from their microscopic architecture?

These questions are not only interesting in their own right; they are relevant for designing new materials with tailored properties. By understanding the relation between microscopic structure and macroscopic response, one can build better gels, coatings, responsive particles, and soft devices.

## 1. Associative polymers and complex self-assembly

Some polymeric systems do not form permanent networks, but rather assemble through specific, reversible interactions. Associative polymers contain sticky motifs that can bond and unbond under suitable conditions. These systems are important because they lie between ordinary polymers and gels, and they can produce dynamic structures that are easy to reconfigure.

<figure>
  <img src="/images/research/pd_associative_polymers.png">
  <figcaption>(a) The phase diagram of a specific model of associative polymers in the density, $\rho \sigma^3$, and interaction energy, $\beta \epsilon$, plane. Black and red symbols are the coexisting densities of the dilute and concentrated (*i.e.* gas-like and liquid-like) phases. Since this particular phase separation has a purely entropic origin that requires that most bonds are formed, it tends to disappear as the interaction energy $\epsilon$ becomes smaller. (b) Simulation snapshots of systems at selected values of $\beta \epsilon$. Image adapted from {{% doi 10.21468/SciPostPhys.15.4.163 text="Rovigatti et al. (2023)" %}}.</figcaption>
</figure>

This is relevant for biomaterials, soft robotics, and synthetic self-assembly, but it also connects to more fundamental questions about phase behavior and topology. We recently discovered that the pattern of binding sites along a chain can strongly affect whether a system forms a homogeneous fluid, a dense network, or a phase-separated state, even in the absence of any other form of inter-chain attraction. We showed numerically that this is a purely entropic effect (see {{% doi 10.1103/PhysRevLett.129.047801 text="Rovigatti and Sciortino (2022)" %}} and {{% doi 10.21468/SciPostPhys.15.4.163 text="Rovigatti and Sciortino (2023)" %}}, as well as the figure above), that the same effect can be harnessed to drive phase separation in all-DNA associative polymers {{% doi 10.1063/5.0279969 text="(Tosti Guerra et al., 2025)" %}}, and also provided a theoretical justifiction in {{% doi 10.1021/acs.macromol.5c03522 text="Cappa et al. (2026)" %}}.

## 2. Microgels as soft colloids

Another theme is the study of microgels as soft colloidal particles. These objects can be viewed as tiny polymer networks that are large enough to behave like particles, yet soft enough to deform and interpenetrate. Their effective interactions are therefore more complicated than for hard spheres. Their size can change with temperature, and their internal core-corona architecture strongly influences their behavior.

This has implications for phase behavior, interfacial adsorption, and collective dynamics. For instance, microgels at interfaces can flatten, deform, and exhibit unusual dynamical arrest and reentrant behavior. The same particle can behave quite differently depending on whether it sits in bulk solution, at a surface, or in a dense suspension. This has been explored in systems of microgels adsorbed at liquid-liquid interfaces by {{% doi 10.1103/PhysRevX.10.031012 text="Camerin et al. (2020)" %}} and in numerical studies of their effective interactions and elasticity by {{% doi 10.1021/acs.macromol.9b00099 text="Rovigatti et al. (2019)" %}}.

## 3. Mechanical properties and elasticity

A central challenge in soft matter is connecting the microscopic structure of a material to its elasticity. For a polymer network, stiffness is not a universal constant, but it depends on many microscopic details such as cross-link density, strand length, charge distribution, network architecture, *etc*. Although decades of work have provided many insights on how these properties are interconnected, much is still to be said. For instance, in {{% doi 10.1021/acs.macromol.1c00176 text="Sorichetti et al (2021)" %}} and {{% doi 10.1063/5.0134271 text="Sorichetti et al (2023)" %}} we show that even when simulated with very simple (and therefore not particularly realistic) models, polymer networks behave rather differently from what one would expect by applying textbook polymer-physics theories.

A similar complexity appears forfor microgels, where internal heterogeneity and softness make common assumptions such as a simple Hertzian contact model, which treats microgels as classical elastic bodies in the small-deformation regime, often inadequate. Our work explores when such simplified descriptions work and when they fail, and how one can obtain more realistic descriptions of soft particle mechanics. The relation between microgel elasticity and effective interactions is discussed in {{% doi 10.1021/acs.macromol.9b00099 text="Rovigatti et al. (2019)" %}} and {{% doi 10.1021/acs.macromol.9b01122 text="Ninarello et al. (2019)" %}}.

# A simple way to think about the field

A useful way to summarize this area of research is:

- polymers provide the building blocks,
- connectivity and topology determine the structure,
- solvent and temperature control the effective interactions,
- softness gives rise to rich and often surprising collective behavior.

This is why polymer and polymer-based systems are such a fertile ground for physics. They sit at the boundary between physics, biology, chemistry, materials science, and statistical mechanics, and they connect to real-world applications in soft robotics, drug delivery, coatings, emulsions, and responsive materials.

[^macromolecule]: "great number" is a purposely vague qualifier: there is no strict definition for the number of atoms required for a molecule to be called a macromolecule.
