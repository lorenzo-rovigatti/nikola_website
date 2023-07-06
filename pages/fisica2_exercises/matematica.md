<!--
.. title: Esercizi di matematica
.. slug: fisica2-esercizi-matematica
.. date: 2023-07-03 17:41:10 UTC+02:00
.. tags: 
.. category: didattica
.. link: 
.. description: 
.. type: text
.. has_math: true
-->

# Esercizi di ripasso

* Quanto vale l'angolo compreso tra $\vec{v} = 3 \hat{x} + 3 \hat{y}$ e $\vec{w} = 2\hat{x} + \hat{y}$?
  * Risposta: $18.49^\circ$, cioè $0.32$ rad
* Quanto vale il modulo del vettore $\vec{v} = \hat{x} + 4 \hat{y} - 2\sqrt{2} \hat{z}$? E qual è l'espressione di $\hat{v}$? 
  * Risposte: $5$ e $\hat{v} = \frac{1}{5} \hat{x} + \frac{4}{5} \hat{y} - \frac{2\sqrt{2}}{5} \hat{z}$
* Un vettore $\vec{v} = v_x \hat{x} + v_y \hat{y}$ di modulo $4$ giace sul piano $(x, y)$ e forma un angolo di $\pi/3$ con l'asse $x$. Quali sono le sue componenti?
  * Risposta: definendo $v$ il modulo si trova $v_x = v \cos(\theta) = 2.00$, $v_y = v \sin(\theta) = 3.46$
* Dati due punti $A = (1, 2, 0)$ e $B = (6, 3, 0)$, determinare 
  * il vettore che congiunge $A$ a $B$
    * $\vec{v} = (6, 3, 0) - (1, 2, 0) = (5, 1, 0)$;
  * la distanza tra $A$ e $B$
    * questa sarà il modulo del vettore, $v = \sqrt{26}$;
  * il versore che punta da $A$ a $B$
    * il versore è definito come $\vec{v} / v = \frac{1}{\sqrt{26}}(5, 1, 0)$
  * il versore che punta da $B$ ad $A$
    * questo versore è uguale a quello sopra cambiato di segno. Perché?
* Dati due vettori $\vec{a} = (2, 3, 0)$ e $\vec{b} = (-2, h, 0)$, quanto deve valere $h$ affinché i vettori risultino perpendicolari? E affinché risultino (anti)paralleli (non fate i conti, delinate solamente la strategia da utilizzare, per esempio disegnando i due vettori)?
	* Risposte: imponendo $\vec{a} \cdot \vec{b} = -4 + 3h + 0 = 0$ si trova $h = 4/3$. La seconda risposta è un po' più complicata, ma si affronta considerando che la condizione di parallelismo si può scrivere come $\cos\theta = \frac{\vec{a} \cdot \vec{b}}{ab} = \pm 1$. Se disegniamo i due vettori vedremo che l'unica possibilità che abbiamo è di imporre $\cos{\theta} = -1$, che si ottiene solo se $h = -3$, cioè quando $\vec{a} = -\vec{b}$!
* Un aereo percorre 100 Km in direzione nord, per poi virare e percorrere 150 Km in direzione nord $30^\circ$ est ed infine percorrere 300 Km in direzione est. Calcolare lo spostamento risultante in modulo, direzione e verso. 
  * Risposta: il primo vettore (omettendo le unità di misura per comodità, ma è tutto misurato in Km) vale $\vec{s}_1 = (0, 100)$, $\vec{s}_2 = (75, 75 \sqrt{3})$ e $\vec{s}_3 = (300, 0)$. Il vettore spostamento totale è quindi $\vec{s}_t = (375, 100 + 75 \sqrt{3}) = (375, 229.9)$, e il suo modulo vale $s = \sqrt{375^2 + 229.9^2} = 439.86$ Km. Per quanto riguarda la direzione, il vettore forma un angolo $\alpha$ con l'asse $x$ che è dato da $s \cos\alpha = s_x$ e quindi $\alpha = \arccos\left(\frac{s_x}{s}\right) = 0.55 \, {\rm rad} = 31.5^\circ$.
* Un giocatore di golf in tre colpi riesce a gettare la sua palla nella buca. Il primo tiro sposta la palla di 12 m a nord, il secondo di 6 m a sud–est (cioè con un angolo $-\pi/4 = -45^\circ$) ed il terzo tiro di 3 m a sud–ovest (cioè con un angolo $-3\pi/4 = -135^\circ$). Quale spostamento è necessario per mandare la palla nella buca al primo colpo?
  * Ragionando come sopra otteniamo $s \simeq 6$ m e $\alpha = 1.21 \, {\rm rad} = 69.4^\circ$.
