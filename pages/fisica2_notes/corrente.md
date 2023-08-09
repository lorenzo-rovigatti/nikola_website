<!--
.. title: Corrente elettrica
.. slug: corrente
.. date: 2023-07-03 17:41:10 UTC+02:00
.. tags: 
.. category: didattica
.. link: 
.. description: 
.. type: text
.. has_math: true
-->

```{contents} Indice
:depth: 2
:backlinks: none
```

# La corrente elettrica

<small>MNV: paragrafo 5.1</small>

Consideriamo i conduttori solidi. In questi materiali gli elettroni sono le uniche cariche libere e si muovono in uno spazio delimitato dal reticolo cristallino composto dagli ioni (atomi senza uno o più elettroni). Il numero di elettroni liberi è *molto grande* (fino a $\approx 1$ elettrone per atomo). La densità di elettroni, infatti, vale solitamente $n \approx 10^{28}\\, \mathrm{elettroni} / $m$^3$. Se ricordiamo quanto vale una carica elementare ($e = 1.609 \times 10^{-19}$ C), vediamo come la quantità di carica "mobile" all'interno di un conduttore è enorme, dell'ordine di $10^9$ C!

* In assenza di campo il "mare" di elettroni liberi si muove in maniera disordinata, e la velocità (vettoriale!) media dei portatori di carica è quindi nulla. 
* In presenza di un campo elettrico (o, equivalentemente, di una differenza di potenziale) gli elettroni tenderanno ad avere una velocità media diversa da zero ed orientata lungo il campo. Prendiamo, ad esempio, due conduttori posti ad una d.d.p. $\Delta V \ne 0$. Se li colleghiamo (ad esempio con un sottile filo conduttore) gli elettroni si muoveranno dalla regione dove il potenziale è più basso a quella dove è più alto, finché non si ristabilisce l'equilibrio elettrostatico ($\Delta V = 0$). Questo flusso di cariche (dovuto ad una differenza di potenziale o, equivalentemente, alla presenza di un campo elettrico) è chiamato *corrente elettrica*.

Stabilire un flusso di corrente che non si esaurisca dopo poco tempo richiede un dispositivo capace di mantenere una differenza di potenziale (più o meno) costante ai due capi del conduttore. Questo dispositivo, che chiamiamo *generatore di tensione* o di potenziale o di forza elettromotrice, fa sì che si crei un flusso di elettroni stabile all'interno del conduttore che non si trova in equilibrio elettrostatico, ma in uno stato *stazionario* di equilibrio dinamico. Il primo dispositivo di questo genere fu la *pila di Volta*, che utilizza l'energia chimica per generare una differenza di potenziale tra due elettrodi (zinco e rame nella pila originaria). Nella pila di Volta due metalli sono immersi in una soluzione elettrolitica. Tra i due metalli e la soluzione si instaura un equilibrio elettrochimico per cui si genera una d.d.p. $\Delta V_1$ tra il conduttore $1$ e la soluzione e una d.d.p $\Delta V_2$ tra il conduttore $2$ e la soluzione. Se i conduttori sono scelti accuratamente, tra i due elettrodi si avrà $\Delta V_1 \neq \Delta V_2$ e quindi $\Delta V_{1,2} = \Delta V_1 - \Delta V_2\neq 0$. Questa d.d.p., chiamata *forza elettromotrice*, è (più o meno) costante e fa sì che ci sia passaggio di corrente tra gli elettrodi qualora questi vengano collegati.

I generatori di tensione (che siano pile o altri dispositivi) vengono comunemente indicati con uno di questi simboli:

<img src="../../images/fisica2/generatore.png" width="400">

## Modello classico della conduzione elettrica
<small>MNV: paragrafi 5.4 e 5.2 (in questo ordine)</small>

Senza prendere in considerazione effetti quantistici, consideriamo un conduttore solido come un "mare" di elettroni immersi in un reticolo di ioni. Il moto di ogni elettrone, che può essere modellizzato come rettilineo uniforme con velocità *molto* alta, $v \approx 10^6 $ m/s,  viene interrotto di frequente dagli urti con gli ioni, che (con ottima approssimazione) ne randomizzano la direzione. La distanza percorsa tra un urto ed un altro è chiamato *cammino libero medio* $l$. Poiché la velocità è essenzialmente costante, il tempo che intercorre tra due urti vale:

$$
\tau = \frac{l}{v}
$$

Senza campo elettrico, la media delle velocità degli elettroni vale $\frac{1}{N}\sum_i \vec{v}_i = 0$, perché non c'è passaggio netto di corrente. Se però il conduttore viene immerso in una regione di spazio in cui è presente un campo $\vec{E}$, ciascun elettrone avverte una forza $-e\vec{E}$, e quindi viene accelerato di $-e\vec{E}/m$. Se appena dopo un urto la velocità di un elettrone vale $\vec{v}_i^{(i)}$, poco prima dell'urto seguente (prima cioè che la velocità venga nuovamente randomizzata) si avrà:

$$
\vec{v}_i^{(f)} = \vec{v}_i^{(i)} - \frac{e\vec{E}}{m} \tau
$$

Dove il fatto che $\tau$ non cambi per effetto del campo verrà giustificato a posteriori notando che le velocità in gioco (quella "naturale" degli elettroni e quella dovuta al campo) differiscono di molti ordini di grandezza. Se facciamo una media tra tutti gli elettroni, troviamo che la velocità non è più nulla ma ha valore finito che dipende dal campo e dalle proprietà degli elettroni:

$$
\vec{v}_d = \frac{1}{N}\sum_i \vec{v}_i^{(f)} = \frac{1}{N}\sum_i \vec{v}_i^{(i)} - \frac{e\vec{E}}{m} \tau = - \frac{e\vec{E}}{m} \tau
$$

Dove $\vec{v}_d$ è detta *velocità di deriva*. **Nota Bene:** La media delle velocità iniziali viene nulla perché si ha, come vedremo fra poco, $v_d \ll v$, e quindi la distribuzione delle velocità per effetto degli urti resta casuale, indipendentemente da $\vec{E}$. In altre parole, l'effetto del campo viene "resettato" dopo ogni urto.

$\vec{v}_d$ è detta velocità di deriva perché è, in media, l'unica componente della velocità non nulla. Il suo effetto netto è quello di muovere gli elettroni lungo la direzione del campo. Stimiamo l'ordine di grandezza di $v_d$ sapendo che $l \sim 4 \times 10^{-8}$ m, $v = 10^6$ m/s, $e = -1.603 \times 10^{-19}$ C, $m = 9.1 \times 10^{-31}$ Kg e un campo elettrico tipico all'interno di un conduttore è dell'ordine di $10^{-2}$ V/m, quindi:

$$
v_d \approx 10^{-4}\\, \mathrm{m / s} = 10^{-10} v
$$

Il che dimostra (giustificando a posteriori le relazioni derivate sopra) come $v_d \ll v$.

Il moto dei portatori di carica (in questo caso elettroni) ha velocità media diversa da zero e quindi dà luogo ad una corrente elettrica. Data una superficie all'interno del conduttore, l'intensità media di questa corrente elettrica è definita come la quantità di carica $\Delta q$ che passa attraverso la superficie in un intervallo di tempo $\Delta t$:

$$
i_m = \frac{\Delta q}{\Delta t}
$$

L'intensità di corrente *istantanea* è definita formalmente come il limite di $i_m$ per intervalli di tempo molto piccoli:

$$
i = \lim_{\Delta t \to 0} \frac{\Delta q}{\Delta t} = \frac{dq}{dt}
$$

La corrente si misura in Ampere (A, che indica quanti Coulomb per secondo passano attraverso una data superficie).

Per mettere in relazione $i$ e $v_d$ prendiamo una superficie infinitesima all'interno del conduttore, $d\Sigma$, e calcoliamo la quantità di carica per unità di tempo che ci passa attraverso quando nel conduttore è presente un campo $\vec{E}$ che genera una velocità di deriva $\vec{v}_d \parallel \vec{E}$. Poiché, in generale, la normale $\hat{n}$ di $d\Sigma$ non è parallela ad $\vec{E}$ ma forma con esso un angolo $\theta$, mentre  la velocità di deriva è costante, gli elettroni che attraversano $d\Sigma$ in un tempo $dt$ sono quelli contenuti nel cilindro obliquo di basi pari a $d\Sigma$ ed altezza pari a $v_d dt$. Disegnandolo si vede subito come il volume di questo solido sia

$$
d\tau = v_d\cos{\theta} d\Sigma dt
$$

Moltiplicando questo valore per il numero medio di elettroni per unità di volume, cioè la densità numerica di elettroni che abbiamo chiamato $n$, si ottiene il numero di elettroni contenuti in $d\tau$ e che quindi passano attraverso $d\Sigma$. Poiché ogni elettrone ha carica $-e$ si trova

$$
dq = -n e v_d\cos{\theta} d\Sigma dt
$$

e quindi

$$
di = \frac{dq}{dt} = -n e v_d\cos{\theta} d\Sigma
$$

è l'intensità di corrente che passa attraverso $d\Sigma$. Se definiamo la *densità di corrente* come

$$
\vec{j} = -n e \vec{v}_d
$$

la corrente attraverso $d\Sigma$ si può riscrivere come

$$
di = \vec{j} \cdot \hat{n} d\Sigma
$$

Data una superficie finita $\Sigma$, l'intensità di corrente che passa attraverso di essa vale

$$
i = \int_{\Sigma} \vec{j} \cdot \hat{n} d\Sigma.
$$

Che possiamo interpretare matematicamente come il flusso di $\vec{j}$ attraverso $\Sigma$. Se prendiamo una superficie ortogonale alla densità di corrente, si ottiene la relazione $i = j\Sigma$, e quindi

$$
j = \frac{i}{\Sigma}
$$

da cui discende il nome di $\vec{j}$, che infatti può essere definita come l'intensità di corrente che passa attraverso l'unità di superficie ortogonale alla direzione del moto delle cariche. 

Nel ricavare $\vec{j}$ abbiamo considerato portatori di carica negativi. In questo caso, se sostituiamo la relazione che lega $\vec{j}$ ad $\vec{E}$ ricavata precedentemente troviamo

$$
\vec{j} = -n e \vec{v}_d = \frac{ne^2\vec{E}}{m} \tau
$$

La densità di corrente ed il campo sono quindi proporzionali. Questa relazione è nota come *legge di Ohm della conduttività elettrica*. Poiché $e^2 \tau / m$ è definito positivo, $\vec{j}$ ha sempre lo stesso verso del campo. Inoltre, la dipendenza dalla carica dei portatori è data dal termine $e^2$, e quindi lo stesso identico risultato è valido anche qualora i portatori fossero positivi. Il fatto che $\vec{j}$ ed $\vec{E}$ siano sempre concordi implica che non sia possibile misurare il segno dei portatori di carica eseguendo misure macroscopiche di corrente: gli effetti macroscopici di una data differenza di potenziale non dipendono dal segno della carica dei portatori. **Nota Bene:** data questa premessa, il verso della corrente (che si considera scorrere dal polo positivo, a potenziale maggiore, a quello negativo, a potenziale minore) è solamente una *convenzione*.

## Corrente elettrica stazionaria

Data una porzione di conduttore, la condizione di *stazionarietà* si ha quando la carica media di ogni sua parte è costante nel tempo. Se prendiamo un volume all'interno del conduttore (che comprenda anche le pareti laterali attraverso le quali non passa corrente), questo sarà delimitato da due superfici $\Sigma_1$ e $\Sigma_2$ qualunque, una attraverso la quale la corrente *entra*, l'altra attraverso la quale la corrente *esce*. La condizione di stazionarietà implica che la quantità di carica che entra deve essere uguale a quelle che ne esce, e quindi si deve avere

$$
i_1 = i_2
$$

**Nota Bene:** questa condizione non implica per forza che la corrente debba essere costante nel tempo.

Se $\Sigma_1$ e $\Sigma_2$ sono entrambe ortogonali a $\vec{j}$, troviamo la relazione $j_1 \Sigma_1 = j_2 \Sigma_2$, cioè

$$
\frac{j_1}{j_2} = \frac{\Sigma_2}{\Sigma_1}
$$

In un sistema stazionario, più il conduttore è stretto più la densità di corrente sarà grande! Pensate a quel che succede quando restringiamo il tubo della pompa per innaffiare...

# Legge di Ohm
<small>MNV: paragrafo 5.3</small>

Abbiamo visto come la densità di corrente sia proporzionale al campo elettrico. La costante di proporzionalità si indica solitamente con $\sigma$ e si chiama *conduttività elettrica*. Nel modello microscopico che abbiamo utilizzato si trova

$$
\sigma = \frac{ne^2\tau}{m}.
$$

Vediamo che in questa relazione entrano solo quantità relative ai portatori di carica ($e$ ed $m$), ed allo specifico materiale ($n$ e $\tau$). Poiché, come abbiamo visto, $\vec{j} \parallel \vec{E}$, $\sigma$ è una quantità positiva (come si trova anche dalla relazione precedente). La legge di Ohm si può anche invertire, e spesso si scrive nella forma

$$
\vec{E} = \rho \vec{j}
$$

dove $\rho = 1 / \sigma$ è detta *resistività del conduttore*. La resistività (come anche, ovviamente, la conduttività) dipende non solo dal materiale considerato ma anche dai parametri fisici esterni come la temperatura. Per molti materiali (specialmente metallici) la resistività aumenta con l'aumentare della temperatura, ma esistono anche materiali (come il carbonio o alcune semiconduttori) o leghe metalliche (il nichelcromo, per esempio) di resistività quasi costante o addirittura decrescente con la temperatura.

Consideriamo un conduttore di forma cilindrica di sezione $\Sigma$ e lunghezza $h$ e i cui estremi sono posti ad una differenza di potenziale $\Delta V = V_a - V_b$. Poiché $\vec{E}$ e $\vec{j}$ sono concordi e la sezione del conduttore è costante possiamo scrivere

$$
E = \rho j = \frac{\rho}{\Sigma} i
$$

Calcoliamo ora la differenza di potenziale tra gli estremi del cilindro:

$$
\Delta V = \int_a^b \vec{E}\cdot d\vec{s} = \int_a^b i\frac{\rho}{\Sigma} dh = \frac{\rho h}{\Sigma} i
$$

Definendo *resistenza del conduttore* la quantità $R = \frac{\rho h}{\Sigma}$ riscriviamo la relazione come

$$
\Delta V = R i
$$

che è nota come *legge di Ohm per i conduttori metallici*. Questo risultato si generalizza al caso di sezione variabile, per il quale si ha

$$
\Delta V = \int_a^b \vec{E}\cdot d\vec{s} = \int_a^b i\frac{\rho}{\Sigma(h)} dh = R i
$$

perché $i$ è costante ovunque (condizione di stazionarietà) e abbiamo definito

$$
R = \int_a^b \rho \frac{dh}{\Sigma(h)}
$$

L'inverso della resistenza è detta *conduttanza*.

La resistenza del conduttore è quindi funzione non solo del materiale (e delle condizioni esterne come temperatura e pressione, che cambiano $\rho$), ma anche delle sue proprietà geometriche. La resistenza si misura in *ohm*, $\Omega = \mathrm{V} / \mathrm{A}$. Le unità di misura delle altre quantità introdotte in questo paragrafo si esprimono a partire dagli ohm (resistività, $\Omega$m; conduttività, $\Omega^{-1}$m$^{-1}$; conduttanza, $\Omega^{-1}$). 

## Potenza ed effetto Joule

Una carica in presenza di un campo elettrostatico accelera. Il lavoro della forza elettrostatica viene tramutato tutto in energia cinetica, che cresce continuamente a spese dell'energia potenziale. Nel caso degli elettroni nei conduttori la velocità di deriva è circa costante, anche in un campo uniforme (che dovrebbe indurre un'accelerazione costante). Dove va a finire il lavoro fatto dal campo elettrico se l'energia cinetica non varia? Viene dissipato in *calore*, che si sviluppa dalla resistenza che il reticolo del conduttore oppone al passaggio degli elettroni. Possiamo calcolare questo lavoro in un conduttore posto ad una d.d.p $\Delta V$:

$$
dW = \Delta V dq = \Delta V i dt
$$

Il lavoro speso nell'unità di tempo si chiama *potenza* (in questo caso *potenza elettrica*):

$$
\mathcal{P} = \frac{dW}{dt} = \Delta V i = R i^2 = \frac{\Delta V^2}{R}
$$

dove le ultime due relazioni sono valide se vale la legge di Ohm. La potenza si esprime in watt (W $=$ J / s). Possiamo quindi scrivere il lavoro compiuto dal campo in un tempo $t$  come

$$
W = \int_0^t \mathcal{P} dt' = \int_0^t R i^2 dt'
$$

Se la corrente è costante nel tempo si ha $W = R i^2 t$. Il lavoro viene assorbito dal conduttore sotto forma di calore, provocando un aumento di temperatura. In generale, quindi, la temperatura di un conduttore percorso da corrente aumenta tanto più quanto l'intensità della corrente è grande. Questo aumento di temperatura, che prende il nome di *effetto Joule*, può persino portare alla fusione del materiale.

Esiste una classe di materiali che hanno resistività così piccola da essere essenzialmente zero: i cosiddetti *superconduttori*. Purtroppo l'effetto di superconduttività si osserva solo a temperature molto basse, e quindi le applicazioni di questi materiali sono limitate (ma comunque importanti: risonanze magnetiche, acceleratori di particelle).

# Resistori
<small>MNV: paragrafo 5.5</small>

Nei circuiti normali, la resistenza dei fili di collegamento con cui i diversi elementi vengono connessi è spesso trascurabile (un filo di rame di lunghezza $1$ cm e diametro $1$ mm ha $R \sim 2 \cdot 10^{-4}\\, \Omega$). Nelle applicazioni reali, come vedremo, è però necessario avere a disposizione anche elementi caratterizzati da valori della resistenza determinati. Questi elementi sono detti *resistori* (più spesso chiamati *resistenze*) e sono indicati col simbolo:

<img src="../../images/fisica2/resistore.png" width="200" />

Ogni resistore è caratterizzato da due valori:

1. la sua resistenza $R$
2. la massima potenza che può dissipare senza essere danneggiato irreparabilmente

Come i condensatori, anche i resistori possono essere connessi sia in serie che in parallelo.

## Resistori in serie

Ora che abbiamo introdotto il concetto di corrente possiamo definire meglio cos'è un collegamento in serie: due elementi circuitali sono in serie se sono attraversati dalla *stessa corrente*. **Nota Bene:** in questo contesto "stessa corrente" non vuol dire "stesso valore di corrente", ma che tutte le cariche che passano attraverso uno degli elementi attraversano anche l'altro.

Nel caso dei resistori, consideriamone due in serie (di resistenza $R_1$ ed $R_2$) ed applichiamo la legge di Ohm ad entrambi, tenendo conto che la corrente che scorre al loro interno è la stessa:

$$
\begin{align}
\Delta V_1 & = R_1 i\\\\
\Delta V_2 & = R_2 i
\end{align}
$$

Quindi la differenza di potenziali ai capi del resistore *equivalente* vale

$$
\Delta V = \Delta V_1 + \Delta V_2 = (R_1 + R_2) i
$$

Questo stesso ragionamento si generalizza al caso di $N$ resistori: la resistenza equivalente di resistori in serie è la somma delle singole resistenze.

## Resistori in parallelo

Elementi connessi in parallelo hanno la stessa differenza di potenziale $\Delta V$, ma sono attraversati da correnti diverse. D'altro canto, la condizione di stazionarietà implica che la somma di queste correnti sia la stessa da entrambi i lati della connessione.

Facciamo il caso di due resistori $R_1$ ed $R_2$, per cui si ha:

\begin{align}
\Delta V & = R_1 i_1\\\\
\Delta V & = R_2 i_2
\end{align}

Imponendo $i = i_1 + i_2$ (cioè la condizione di stazionarietà appena discussa) si ottiene

$$
i = \left( \frac{1}{R_1} + \frac{1}{R_2} \right) \Delta V
$$

La stessa relazione si ottiene considerando un sistema di $N$ resistori in parallelo: la resistenza equivalente di resistori in parallelo è l'inverso della somma delle singole resistenze inverse.

# Forza elettromotrice
<small>MNV: paragrafo 5.6</small>

La legge di Ohm può essere scritta come integrale del campo:

$$
\Delta V = V_A - V_B = \int_A^B \vec{E} \cdot d\vec{s} = Ri
$$

Esteso a tutto il circuito, l'integrale vale:

$$
\oint \vec{E} \cdot d\vec{s} = R_Ti
$$

dove $R_T$ è la resistenza totale. Il fatto che la circuitazione del campo non sia nulla implica che $\vec{E}$ non può avere natura unicamente elettrostatica. Sicuramente avrà una componente elettrostatica data dall'accumulo di carica sui poli del generatore, il cui integrale lungo tutto il circuito è nullo. Questo campo $\vec{E}\_{\rm el}$ è sempre diretto dal polo positivo a quello negativo. All'interno del generatore deve quindi essere presente un meccanismo *non elettrostatico*, che chiamiamo campo elettromotore $\vec{E}\_{\rm em}$, che sposta le cariche dal polo negativo a quello positivo. La circuitazione di questo campo è chiamata *forza elettromotrice*:

$$
\mathcal{E} = \oint \vec{E}\_{\rm em} \cdot d\vec{s} = \int_A^B \vec{E}\_{\rm em} \cdot d\vec{s}
$$

**Nota Bene:** nonostante il nome possa confondere, la forza elettromotrice **non** è una forza, ma ha le stesse unità di misura di un potenziale (perché?).

Il meccanismo che genera il campo elettromotore dipende dal generatore, e può essere di natura diversa (chimica, meccanica, elettromagnetica, *etc.*). Oltre che da $\mathcal{E}$, il generatore è anche caratterizzato da una resistenza interna $R_i$. Un generatore realistico può quindi essere schematizzato come un generatore "ideale" in serie ad una resistenza $R_i$. Applicando la legge di Ohm ad un circuito di resistenza $R$ collegato ad un generatore del genere si ottiene

$$
\mathcal{E} = (R + R_i) i
$$

e quindi 

$$
R i = \mathcal{E} - R_i i
$$

che è la differenza di potenziale ai capi del generatore. Proviamo a disegnare l'andamento del potenziale lungo un semplice circuito composto da un generatore e una resistenza. Partiamo dal polo negativo (il cui potenziale poniamo convenzionalmente a 0). Muovendoci verso il polo positivo *all'interno del generatore*, il potenziale aumenta di $\mathcal{E}$. Ancora all'interno del generatore la corrente oltrepassa la resistenza interna, e quindi il potenziale diminuisce di $R_i i$. Resta costante nel filo (la cui resistenza consideriamo trascurabile) che collega il generatore al resistore. Oltrepassando il resistore il potenziale diminuisce di un ulteriore $R i$, tornando a 0 sul polo negativo del generatore.

Interpretiamo questo grafico considerando che l'andamento rispecchia l'energia potenziale di una carica positiva che si muove lungo il circuito ($\Delta U_e = q\Delta V$). La quantità $q\mathcal{E}$ è quindi il lavoro fornito dal generatore ad una carica $q$, che l'acquista nella forma di energia potenziale. Questa energia, a sua volta, viene dissipata nelle due resistenze (interna ed esterna). Possiamo trovare la potenza dissipata sulle due resistenze esplicitando il bilancio energetico tramite la legge di Ohm moltiplicata per il fattore $dq = i dt$:

$$
\mathcal{E} i dt = R i^2 dt + R_i i^2 dt
$$

Da cui si vede che la potenza ha anch'essa due contributi:

$$
\mathcal{P} = R i^2 + R_i i^2
$$

# Circuito RC

<small>MNV: paragrafo 5.7</small>

Consideriamo due esempi di circuiti con correnti variabili. In entrambi i casi vediamo che la presenza del resistore fa sì che parte dell'energia venga irreversibilmente persa per effetto Joule.

## Carica di un condensatore

Consideriamo un circuito composto da un generatore di forza elettromotrice $\mathcal{E}$, una resistenza $R$ ed un condensatore $C$. La resistenza interna del generatore può essere considerata trascurabile (o inclusa in $R$). Il circuito è inizialmente aperto. Al tempo $t = 0$ il collegamento viene chiuso. Come variano nel tempo la corrente $i(t)$, le d.d.p. ai capi degli elementi del circuito, $\Delta V_R(t)$ e $\Delta V_C(t)$, e la carica immagazzinata sul condensatore $q(t)$?

Consideriamo il sistema stazionario: la corrente che scorre nel circuito varia nel tempo, ma ad un dato istante $t$ l'intensità di corrente è la stessa ovunque. In un istante generico $t$ si deve quindi avere 

\begin{align}
\Delta V_C(t) & = \frac{q(t)}{C}\\\\
\Delta V_R(t) & = R i(t) = R \frac{dq}{dt}\\\\
\mathcal{E} & = \Delta V_C(t) + \Delta V_R(t)
\end{align}

Si ha quindi

$$
R \frac{dq}{dt} = \mathcal{E} - \frac{q}{C}
$$

Questa è, dal punto di vista matematico, un'equazione differenziale, cioè un'equazione in cui "l'incognita" è una funzione piuttosto che un numero (in questo caso la funzione $q(t)$). Le equazioni differenziali di questo tipo sono facilmente risolvibili per *separazione di variabili*. Riscriviamo l'equazione mettendo in un membro tutto ciò che dipende dall'argomento della funzione ($t$) e nell'altro tutto ciò che è legato alla funzione:

$$
\frac{dq}{C\mathcal{E} - q} = \frac{dt}{RC}
$$

Integriamo entrambi i membri da $0$ a $t$ imponendo la condizione iniziale $q(0) = 0$:

$$
\int_0^q \frac{dq'}{C\mathcal{E} - q'} = -\left( \log{(C\mathcal{E} - q)} - \log{(C\mathcal{E})} \right) = -\log{\left( \frac{C\mathcal{E} - q}{C\mathcal{E}} \right) }
$$

$$
\int_0^t \frac{dt'}{RC} = \frac{t}{RC}
$$

Spostando il segno $-$ dal membro di sinistra a quello di destra ed esponenziandoli entrambi si ottiene

$$
C\mathcal{E} - q = C\mathcal{E}e^{-\frac{t}{RC}}
$$

Da cui si ricava:

$$
q(t) = C\mathcal{E} \left( 1 - e^{-\frac{t}{RC}} \right)
$$

Sostituendo questa relazione nelle precedenti troviamo:

$$
\begin{align}
i(t) &= \frac{\mathcal{E}}{R}e^{-\frac{t}{RC}}\\\\
\Delta V_C & = \mathcal{E} \left( 1 - e^{-\frac{t}{RC}} \right)\\\\
\Delta V_R & = \mathcal{E} e^{-\frac{t}{RC}}
\end{align}
$$

Tutte le quantità variano in maniera esponenziale, con il tempo caratteristico dato dal prodotto $RC$ (che infatti si misura in secondi). Tutte le quantità finali sono quindi raggiunte *asintoticamente* (ma dal punto di vista pratico questo avviene quando $t \gtrsim 5 RC$). Se variamo i componenti in maniera che questo prodotto rimanga invariato, la dipendenza dal tempo di tutte le quantità rimane costante. Cambiano però i valori finali (che dipendono da $\mathcal{E}$ e da $C$ o $R$, mai da entrambi). L'interpretazione di questi risultati è semplice: la corrente è massima all'inizio, quando la carica è nulla. Mano a mano che il condensatore si carica la corrente diminuisce, la d.d.p. ai capi del condensatore aumenta (con $q$), mentre quella ai capi del resistore diminuisce.

Se chiamiamo $q_f = \mathcal{E}C$ il valore di carica asintotico, il lavoro compiuto dal generatore per caricare il condensatore vale:

$$
W_g = \int_0^{q_f} \mathcal{E} dq = \mathcal{E} q_f = \mathcal{E}^2 C
$$

D'altro canto, l'energia elettrostatica immagazzinata dal condensatore è:

$$
\frac{1}{2} q_f \mathcal{E} = \frac{1}{2} \mathcal{E}^2 C
$$

cioè metà dell'energia spesa dal generatore. Il resto viene dissipato sulla resistenza. La potenza totale erogata, quindi, viene consumata sulla resistenza per effetto Joule e per aumentare l'energia elettrostatica del condensatore, caricandolo. Utilizzando le relazioni ottenute precedentemente si può trovare che, ad ogni istante, vale la relazione:

$$
\mathcal{P}_g = \mathcal{P}_R + \mathcal{P}_C
$$

## Scarica di un condensatore

Consideriamo un circuito aperto formato da un condensatore $C$, inizialmente carico con carica $q_0$, e da una resistenza $R$. Calcoliamo come variano nel tempo le quantità introdotte nel paragrafo precedente se il circuito viene chiuso.

Le espressioni per la d.d.p. ai capi dei due elementi sono le stesse del caso precedente:

$$
\Delta V_R = R i(t) = R \frac{dq}{dt}
$$

$$
\Delta V_C = \frac{q(t)}{C}
$$

anche se in questo caso non è presente alcun generatore, quindi

$$
\Delta V_R + \Delta V_C = R \frac{dq}{dt} + \frac{q(t)}{C} = 0
$$

che è di nuovo un'equazione differenziale risolvibile per separazione di variabili:

$$
\frac{dq}{q} = -\frac{dt}{RC}
$$

che integriamo di nuovo da 0 a $t$, con condizione iniziale $q(0) = q_0$, ottenendo

$$
\begin{align}
q(t) & = q_0 e^{-\frac{t}{RC}}\\\\
i(t) & = -\frac{q_0}{RC} e^{-\frac{t}{RC}}\\\\
\Delta V_C & = \frac{q_0}{C} e^{-\frac{t}{RC}}\\\\
\Delta V_R & = -\frac{q_0}{C} e^{-\frac{t}{RC}}
\end{align}
$$

**Nota Bene:** la corrente ha segno negativo, perché la carica sta *diminuendo*, quindi $dq/dt < 0$.
La dipendenza temporale è identica a prima, essendo caratterizzata unicamente dal prodotto $RC$. In questo caso si parte da una condizione di carica massima del condensatore, che ha inizialmente energia $U_e = \frac{q_0^2}{2 C}$. Alla fine del processo (cioè per $t \to \infty$) la carica è nulla e quindi $U_e = 0$. Dove è finita l'energia? Calcoliamo la potenza istantanea dissipata sul resistore:

$$
\mathcal{P}_R(t) = R i^2 = \frac{q_0^2}{RC^2} e^{-2\frac{t}{RC}}
$$

L'energia totale dissipata in un tempo $t$ è l'integrale della potenza da $0$ a $t$, che per $t \to \infty$ vale

$$
W_R = \int_0^\infty \frac{q_0^2}{RC^2} e^{-2\frac{t'}{RC}} dt' = \frac{q_0^2}{2 C}
$$

# Reti elettriche

<small>MNV: paragrafo 5.9</small>

Un circuito può essere composto da molti elementi che possono essere collegati, a due a due, in serie o in parallelo. Definiamo:

* nodo della rete: un punto in cui tre o più fili/elementi si uniscono;
* ramo della rete: una porzione di circuito che collega due nodi. In generale, i rami possono contenere elementi di diverso tipo (generatori, condensatori, resistori, motori, *etc.*);
* maglia della rete: una parte del circuito che forma un percorso chiuso. È composta da un numero quasiasi di rami (ognuno però incluso non più di una volta). I rami e i nodi di una maglia sono, in generale, condivisi con altre maglie.

## Prima legge di Kirchhoff

In virtù del principio di conservazione della carica, possiamo generalizzare il principio di stazionarietà ad un nodo da cui escano $N$ rami, ognuno dei quali percorso da una corrente $i_k$:

$$
\sum_{k = 0}^N i_k = 0
$$

anche detta *prima legge di Kirchhoff*. Quando si applica questa legge bisogna fare attenzione al verso delle correnti, che va preso con segno diverso a seconda che queste siano entranti o uscenti.

## Seconda legge di Kirchhoff

In base alle definizioni del paragrafo precedente, in ogni ramo di un circuito scorre una corrente $i_k$. Questa corrente può essere sia positiva che negativa, a seconda del verso in cui scorre. Su un ramo generico, che connette i nodi $A$ e $B$, vale la *legge generalizzata di Ohm*:

$$
V_A - V_B + \mathcal{E}_r + \Delta V_r^{(C )} = R_r i_k
$$

dove il primo termine è la differenza di potenziale tra i due nodi, il secondo è la somma delle forze elettromotrici presenti lungo il ramo, il terzo è dato dalle d.d.p. di elementi che non sono né resistori né generatori (come i condensatori), e $R_r$ è la resistenza totale del ramo. Se consideriamo ora una *maglia* della rete, possiamo sommare le leggi di Ohm generalizzate per ognuno dei rami che la compongono. Per farlo è necessario prima di tutto fissare, per convenzione, il verso con cui si percorre la maglia (ad esempio: orario o antiorario). In questo modo la somma delle d.d.p. lungo la maglia si annulla e quindi si ottiene:

$$
\sum_k \mathcal{E}_k + \sum_k \Delta V_k^{(C )} = \sum_k R_k i_k
$$

dove le somme sono estese a tutti i rami $k$ della maglia. Se sono presenti solo generatori e resistori, la relazione precedente si riduce a:

$$
\sum_k \mathcal{E}_k = \sum_k R_k i_k.
$$

Questa equazione è chiamata *seconda legge di Kirchhoff*. Per applicare questa legge bisogna prima di tutto, come detto, fissare un verso di percorrenza. Dato un verso, la forza elettromotrice di generatori che sono orientati in maniera tale da avere prima il morsetto negativo e poi quello positivo danno contributo positivo (e viceversa). Similmente, correnti parallele al verso scelto sono positive (e viceversa). 

Per reti elettrici generiche bisogna scrivere un'equazione per ogni maglia (applicando la seconda legge di Kirchoff) e un'equazione per ogni nodo (applicando la prima legge di Kirchoff). Per trovare le correnti (o le quantità incognite) bisogna quindi risolvere il sistema di equazioni risultante.

## Un esempio

Calcoliamo le correnti che scorrono nel circuito in figura

<img src="../../images/fisica2/esempio_kirchhoff.png">

Scegliamo arbitrariamente i versi delle correnti in maniera tale che nelle due maglie (1 e 2) si vada dal polo positivo a quello negativo di ogni generatore. Applichiamo la prima legge di Kirchhoff nel nodo $A$:

$$
i_1 + i_2 = i_3.
$$

Per le due maglie, invece, vale

\begin{align}
V_1 & = i_1 R_1 + i_3 R_3\\\\
V_2 & = i_2 R_2 + i_3 R_3
\end{align}

Le equazioni si risolvono sostituendo la prima nelle ultime due e poi isolando le due correnti. Nello specifico caso in esame si trova $i_1 = -0.143$ A, $i_2 = 0.429$ A e $i_3 = 0.286$ A. Il fatto che $i_1$ sia negativa significa che il suo verso è contrario a quello che abbiamo scelto per applicare le leggi di Kirchoff.

