<!--
.. title: Esercizi sulle onde elettromagnetiche
.. slug: fisica2-esercizi-onde
.. date: 2023-07-03 17:41:10 UTC+02:00
.. tags: 
.. category: didattica
.. link: 
.. description: 
.. type: text
.. has_math: true
-->

[Esercizio 63](#esercizio-63) -- [Esercizio 64](#esercizio-64)

# Esercizio 63

Si consideri un esperimento di Young effettuato con luce arancione di lunghezza d’onda $\lambda_1 = 610$ nm. Il sistema di frange di interferenza prodotte in esso è caratterizzato da una distanza tra massimi consecutivi pari a $p = 0.47$ mm. Si assuma che la distanza tra schermo e fenditure sia pari a $L = 77$ cm.

1. Calcolare la distanza $d$ tra le due fenditure.
2. Determinare la lunghezza d’onda $\lambda_2$ per la quale lo stesso dispositivo produce un sistema di frange d’interferenza avente spaziatura $p_2 = 0.91$ mm.
3. Determinare la spaziatura delle frange $p_a$ che la stessa luce arancione del primo punto genererebbe qualora il dispositivo venisse immerso in acqua (indice di rifrazione $n_a = 1.33$).
3. Qual è la densità di frange nell'ultimo caso?

## Soluzione

1. Nell'esperimento di Young la distanza tra i centri di due massimi consecutivi (anche detta **passo**) è $p = \frac{\lambda L}{d}$ e quindi
$$
d = \frac{\lambda L}{p} = 1 \, {\rm mm}
$$
2. Usando la stessa formula del punto precedente troviamo
$$
\lambda_2 = \frac{p d}{L} = 1.18 \, {\rm \mu m} = 1180 \, {\rm nm}
$$
3. Un'onda che passa in un mezzo avente indice di rifrazione diverso da uno subisce un cambiamento di lunghezza d'onda, che in questo caso diventa $\lambda_a = \frac{\lambda_1}{n_a}$. Utilizzando la relazione precedente troviamo quindi
$$
p_a = \frac{\lambda_a L}{d} = \frac{\lambda_1 L}{n_a d} = \frac{p}{n} = 0.28 \, {\rm mm}
$$

4. La densità di frange non è altro che il numero di frange per unità di lunghezza, cioè l'inverso della spaziatura:
$$
D = \frac{1}{p_a} = 3.5 \, {\rm mm}^{-1} = 35 \, {\rm cm}^{-1}
$$

# Esercizio 64

Su una lastra di materiale è praticata una fenditura di larghezza $a$, che viene illuminata con luce di lunghezza d’onda $\lambda_1 = 350$ nm e $\lambda_2 = 450$ nm che incide perpendicolarmente alla fenditura. Su uno schermo posto a distanza $L = 6$ m (molto maggiore delle dimensioni della fenditura stessa), si osserva che la distanza spaziale tra i minimi di diffrazione del secondo ordine delle due componenti della luce è pari a $\Delta x = 6$ cm.

1. Determinare la larghezza $a$ della fenditura;
2. Calcolare l'intensità relativa delle due onde in direzione normale allo schermo sapendo che l’intensità relativa delle due onde nella direzione $\theta = \pi / 5$ è pari a $I_1(\pi / 5) / I_2(\pi/5) = 0.06$.

## Soluzione

1. In generale la posizione dei minimi di diffrazione si ha per quegli angoli $\theta$ per cui vale
$$
\sin\theta = m\frac{\lambda}{a}
$$
dove $m$ è un qualunque intero diverso da 0. Se $L \gg x$ possiamo considerare approssimare $\sin \theta \approx \tan \theta \approx x / L$, quindila distanza *angolare* tra due minimi vale
$$
\Delta \sin\theta \approx 2 \frac{\lambda_2 - \lambda_1}{a} = \frac{\Delta x}{L}
$$
poiché consideriamo i minimi del secondo ordine ($m = 2$). Dalla relazione precedente possiamo ricavare la larghezza della fenditura:
$$
a = \frac{2 (\lambda_2 - \lambda_1) L}{\Delta x} = 20 \, {\rm \mu m}
$$
3. In generale l'intensità della figura di diffrazione è data da
$$
I(\theta) = I(0) \left( \frac{\sin \left(  \frac{\pi a \sin \theta}{\lambda} \right)}{\frac{\pi a \sin \theta}{\lambda}} \right)^2
$$
e quindi il rapporto tra le intensità per $\theta = \theta_p = \pi / 5$ è
$$
\frac{I_1(\pi/5)}{I_2(\pi/5)} = \frac{I_1(0)}{I_2(0)} \frac{\sin^2 \left(  \frac{\pi a \sin \theta_p}{\lambda_1} \right)}{\sin^2 \left(  \frac{\pi a \sin \theta_p}{\lambda_2} \right)} \frac{\lambda_2^2}{\lambda_1^2}
$$
e quindi l'intensità relativa delle due componenti quando $\theta = 0$ vale
$$
\frac{I_1(0)}{I_2(0)} = \frac{I_1(\pi/5)}{I_2(\pi/5)} \frac{\sin^2 \left(  \frac{\pi a \sin \theta_p}{\lambda_2} \right)}{\sin^2 \left(  \frac{\pi a \sin \theta_p}{\lambda_1} \right)} \frac{\lambda_1^2}{\lambda_2^2} = 0.015.
$$
