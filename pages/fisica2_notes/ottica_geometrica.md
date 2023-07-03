<!--
.. title: Ottica geometrica
.. slug: ottica-geometrica
.. date: 2023-07-03 17:41:10 UTC+02:00
.. tags: 
.. category: 
.. link: 
.. description: 
.. type: text
.. has_math: true
-->

# Ottica geometrica

La luce ha una doppia natura: ondulatoria e corpuscolare. Per quel che concerne questo corso, noi siamo interessati specificamente a descrivere la luce come un'*onda*. Abbiamo in effetti già visto che gli effetti più interessanti (come rifrazione, interferenza e diffrazione) si possono spiegare considerando la natura ondulatoria della luce, così come si ottiene risolvendo le equazioni di Maxwell. D'altro canto in alcuni contesti è sufficiente utilizzare i concetti di rifrazione e riflessione per comprendere il comportamento della luce. In questi casi si descrive la luce come un insieme di *raggi luminosi* che si possono considerare semirette che escono dalla sorgente ed interagiscono con degli strumenti ottici che incontrano sulla loro strada. In particolare, in questa lezione ci interessa capire come i raggi, che partono da sorgenti di luce, subiscano i fenomeni di rifrazione e di riflessione e formino *immagini*, ad esempio sul fondo del nostro occhio o sul sensore di uno strumento di laboratorio.

Riassumiamo quanto visto su riflessione e rifrazione. Consideriamo un raggio che colpisce una superficie che separa due mezzi di diverso indice di rifrazione $n_1$ ed $n_2$. Si chiama *piano di incidenza* il piano identificato dal raggio incidente su di una superficie e dalla normale alla superficie stessa. Nell'approssimazione di superficie liscia (che è quella che utilizzeremo) i raggi riflessi e rifratti si trovano tutti sul piano di incidenza. I raggi incidente, riflesso e rifratto (o trasmesso) formano con la normale i tre angoli $\theta_i$, $\theta_r$ e $\theta_t$. Abbiamo visto che sussistono le seguenti relazioni tra gli angoli:

$$
\theta_r = \theta_i
$$

$$
\sin \theta_t = \frac{n_1}{n_2} \sin \theta_i
$$

## Definizioni e convenzioni

<small>MNV: paragrafo 12.2</small>

Ecco alcune definizioni necessarie:

* L' *oggetto* è un corpo (puntiforme o meno) che emette (o diffonde) luce
* L'insieme (fascio) dei raggi emessi dall'oggetto interagiscono con l'apparato ottico, venendone deviati. Il fascio di raggi che ne deriva è chiamato *immagine* dell'oggetto.
  * L'immagine è *reale* se i raggi passano effettivamente per essa.
  * L'immagine è *virtuale* se i *prolungamenti* dei raggi passano per essa.
* Un apparato (strumento) ottico è detto *stigmatico* se i raggi che escono da uno stesso punto dell'oggetto si incontrano tutti, dopo aver interagito con lo strumento ottico, in un solo punto. I due punti (uno sull'oggetto, uno sull'immagine) sono detti *coniugati*. In generale la condizione di *stigmatismo* è difficile da ottenere, e di solito è legata a raggi emessi in una direzione (quasi) parallela all'asse dello strumento. Noi cominceremo col considerare solamente questo caso.
* Le superfici catrottiche o *specchi* sono superfici su cui avviene unicamente il fenomeno della riflessione. La legge che lega gli angoli di incidenza e riflessione non dipende dalle proprietà dei due mezzi, quindi raggi di diversa lunghezza d'onda hanno traiettorie identiche.
* Le superfici diottriche o *diottri* sono superfici su cui avviene unicamente il fenomento della rifrazione. Poiché la legge di Snell dipende dagli indici di rifrazione dei mezzi e questi, a loro volta, dipendono dalla lunghezza d'onda della luce incidente, raggi aventi la stessa direzione ma lunghezza d'onda diversa percorreranno, in generale, traiettorie diverse. Il sistema ottico, in queste condizioni, è *astigmatico*. Uno stesso oggetto darà quindi immagini diverse, dando luogo ad un fenomeno noto come *cromatismo*, che si può risolvere utilizzando una successione di superfici diottriche, costruendo quindi uno strumento *acromatico*.

In quel che segue utilizzeremo la geometria per derivare le leggi che determinano le traiettorie di raggi di luce in presenza di superfici diottriche e catrottiche. Per semplificare la descrizione utilizziamo le seguenti definizioni e convenzioni (vedi box giallo alla fine del paragrafo 12.2 dell'MNV):

* la luce incidente proviene da sinistra.
* $V$ indica il punto in cui la superficie (diottrica o catrottica) interseca l'asse di simmetria del sistema.
* $P$ indica la posizione dell'oggetto, $Q$ quella delll'immagine.
* $p$ indica la distanza dell'oggetto da $V$, che prendiamo positiva se $P$ è a sinistra di $V$, negativa altrimenti.
* $q$ indica la distanza dell'immagine da $V$, che prendiamo negativa se $Q$ è a sinistra di $V$, positiva altrimenti (convenzione contraria rispetto a $p$).
* Se abbiamo a che fare con una superficie curva, definiamo $R$ il suo raggio di curvatura. $R$ è positivo se il centro di curvatura si trova a destra di $V$ (superficie convessa), negativo altrimenti (superficie concava).
* Gli angoli che i raggi formano con l'asse di simmetria (asse *ottico*) sono positivi se considerati nel verso antiorario a partire dall'asse se ci troviamo a sinistra di $V$, positivi nel verso orario se ci troviamo a destra di $V$.
* Le distanze (che indicheremo con $y$) dall'asse ottico sono 
  * positive per punti al di sopra dell'asse e negative altrimenti se stiamo considerando l'oggetto
  * negative per punti al di sopra dell'asse e positive altrimenti se stiamo considerando l'immagine

# Specchi

<small>MNV: paragrafo 12.3</small>

## Specchio sferico concavo

Consideriamo uno specchio sferico concavo (cioè una superficie catrottica sferica concava) e un oggetto puntiforme $P$ sull'asse. In queste condizioni $R < 0$ e $p > 0$. Tracciamo un raggio che da $P$ porta allo specchio nel punto $H$ e che, venendo riflesso, colpisce l'asse ottica nel punto $Q$. L'angolo che il raggio forma con l'asse è $\theta$. Se definiamo $O$ il centro di curvatura dello specchio, la normale alla superficie nel punto $H$ è il segmento $OH$. Definiamo $\theta_i$ l'angolo di incidenza (cioè l'angolo formato dai segmenti $PH$ e $OH$), $\theta_r = \theta_i$ l'angolo di riflessione (cioè l'angolo formato dai segmenti $OH$ e $QH$), $\alpha$ l'angolo formato da $OH$ e dall'asse ottico, $\theta'$ l'angolo formato da $QH$ e dall'asse ottico. Ricordando che la somma degli angoli interni di un triangolo ($\pi$) è uguale alla somma di un angolo interno più il suo angolo esterno associato si ricava la nota proprietà dei triangoli per cui l'angolo esterno di un triangolo è uguale alla somma dei due angoli interni non adiacenti. Applicando questa relazione al triangolo $PHO$ si ottiene

$$
\alpha = \theta + \theta_i
$$

mentre per il triangolo $OHQ$ si trova

$$
\theta' = \alpha + \theta_r = \alpha + \theta_i.
$$

Risolvendo per $\theta_i$ e sostituendo troviamo

$$
\theta + \theta' = 2 \alpha.
$$

Questa relazione ha carattere generale. Da questa possiamo ottenere una semplice relazione che leghi $p$, $q$ ed $R$ nell'approssimazione di angoli piccoli, quando cioè vale $\sin \theta \approx \tan \theta \approx \theta$, $\sin \theta' \approx \tan \theta' \approx \theta'$ e $\sin \alpha \approx \tan \alpha \approx \alpha$. Tracciamo il segmento $h$ che unisce perpendicolarmente $H$ all'asse ottico nel punto $H'$, generando così tre triangoli rettangoli aventi $h$ in comune. Poiché gli angoli sono piccoli, $H'$ e $V$ sono molto vicini e quindi $PH' \approx PV$, $OH' \approx OV$ e $QH' \approx QV$, quindi

$$
h \approx PV \tan \theta \approx PV \theta
$$

$$
h \approx QV \tan \theta' \approx QV \theta'
$$

$$
h \approx OV \tan \alpha \approx OV \alpha.
$$

Ricordando le definizioni e convenzioni date prima si trova

$$
PV = p, \quad QV = -q, \quad OV = -R
$$

e quindi

$$
\theta = \frac{h}{p}, \quad \theta' = -\frac{h}{q}, \quad \alpha = -\frac{h}{R}.
$$

Sostituendo queste relazioni nell'equazione che lega gli angoli otteniamo

$$
\frac{1}{p} - \frac{1}{q} = -\frac{2}{R}
$$

che è detta *equazione dello specchio sferico concavo* nell'approssimazione *parassiale*, cioè per angoli piccoli. Poiché in questa equazione non compaiono gli angoli, *tutti* i raggi uscenti da $P$ si incontrano nello stesso punto $Q$, quindi questo tipo di strumento ottico, in questa approssimazione, è *stigmatico*.

Applichiamo ora l'equazione dello specchio per trovare $q$ (la distanza dell'immagine dallo specchio) al variare di $p$ (la distanza dell'oggetto dallo specchio). Quando $P$ è molto lontano $p \to \infty$, i raggi sono essenzialmente paralleli all'asse e si trova

$$
q = R/2 \equiv f,
$$

dove $f$ è detta *distanza focale* dello specchio. I raggi si incontrano tutti in un unico punto $F$ distante $-f$ dal vertice detto *fuoco* dello specchio. Nel caso di uno specchio concavo $R$ è negativo quindi $f < 0$. L'equazione dello specchio concavo si può riscrivere utilizzando $f$:

$$
\frac{1}{p} - \frac{1}{q} = -\frac{1}{f}.
$$

Man mano che $p$ diminuisce (e $P$ si avvicina ad $O$), $q$ aumenta in modulo, diventando via via più negativo e quindi $Q$ si allontana da $V$. Quando $P$ ed $O$ coincidono si ottiene l'equazione

$$
-\frac{1}{q} = -\frac{1}{f} + \frac{1}{2f} = -\frac{1}{2f} = -\frac{1}{R}
$$

che dimostra come oggetto e immagine coincidano. Se l'oggetto si trova alla destra di $O$, $q$ diminuisce di valore (ma aumenta in modulo) finché non prende il valore $-\infty$ quando $P$ è nel fuoco: quando mettiamo l'oggetto nel fuoco di uno specchio sferico concavo, i raggi generati hanno traiettoria parallela all'asse.

Se $P$ viene posto oltre al fuoco $F$ i raggi riflessi divergono e l'immagine sembra provenire da un punto posto alla destra di $V$ ed è cioè *virtuale*. Si trova infatti che se $p$ è minore di $-f$ il valore di $q$ deve essere positivo (come da convenzione).

Quanto detto sopra vale strettamente solo per oggetti posti sull'asse ottico, ma è approssimativamente vero anche per punti vicini (ma non sovrapposti) all'asse. Utilizzando quindi la stessa legge dello specchio è possibile calcolare l'immagine $QQ'$ di un oggetto *esteso* $PP'$. Per farlo è sufficiente tracciare due o più raggi che partono da $P'$ e vedere dove si intersecano. Ad esempio si può tracciare un raggio parallelo all'asse (che si rifletterà sulla superficie e passerà per il fuoco) e un raggio che passi per il centro di curvatura (che verrà riflesso lungo la stessa traiettoria). Se l'immagine è reale $QQ'$ risulta capovolta, se l'immagine è virtuale $QQ'$ risulta dritta. Inoltre, in generale l'immagine avrà una dimensione diversa rispetto all'oggetto. Il rapporto tra le due altezze è detto *ingrandimento trasversale* ed è definito come

$$
I = \frac{y'}{y}
$$

dove $y'$ e $y$ sono, rispettivamente, l'altezza dell'immagine e dell'oggetto. Questo rapporto si può calcolare disegnando i raggi e notando che i triangoli $PP'O$ e $OQQ'$ sono simili e quindi, poiché hanno i lati proporzionali, si ottiene

$$
I = \frac{q - R}{p + R} = -\frac{q}{p},
$$

dove l'ultima relazione si ottiene applicando l'equazione dello specchio concavo. Lo specchio concavo restituisce immagini reali, capovolte e rimpicciolite se $p > -f$ o virtuali, dritte e ingrandite se $P$ è tra $F$ e $V$.

## Specchio sferico convesso

La costruzione geometrica fatta prima può essere estesa al caso di superficie sferica convessa. Se disegniamo il sistema si vede subito come, indipendentemente da $p$, l'immagine che si forma non può essere che virtuale, quindi $q > 0$. In questo caso si trova

$$
2 \alpha = \theta' - \theta
$$

e, nella stessa approssimazione precedente (ma ricordando che in questo caso $R > 0$), si ottiene $\frac{1}{q} - \frac{1}{p} = \frac{2}{R}$ e quindi

$$
\frac{1}{p} - \frac{1}{q} = -\frac{2}{R}
$$

cioè, formalmente, la relazione ottenuta precedentemente. **Nota Bene:** le equazioni sono uguali ma in un caso (specchio concavo) $R < 0$, nell'altro (specchio convesso) $R > 0$.

Quando $p = \infty$, cioè quando i raggi sono paralleli all'asse, si trova che i prolungamenti dei raggi riflessi passano tutti per il punto $F$ distante $R / 2$ dal vertice, anche in questo caso detto *fuoco* dello specchio. La distanza $f = R / 2$ è la distanza focale, come nel caso precedente, e ci permette di riscrivere l'equazione dello specchio:

$$
\frac{1}{p} - \frac{1}{q} = -\frac{1}{f}.
$$

In questo caso $f > 0$ e quindi si nota immediatamente come $q$ sia sempre positiva perché data da una somma di numeri positivi:

$$
\frac{1}{q} = \frac{1}{p} + \frac{1}{f}.
$$

In generale i risultati ottenuti per lo specchio concavo si estendono al caso convesso (oggetti non puntiformi, ingradimento, *ecc*), con la differenza che $f$ e $q$ sono entrambi sempre positivi. In particolare, si trova che l'immagine è sempre virtuale, dritta e rimpicciolita.

Quando $R \to \infty$ uno specchio (concavo o convesso che sia) diventa *piano*. In questo caso si trova $p = q$, l'immagine è quindi sempre virtuale (perché sia $p$ che $q$ sono maggiori di 0) e le dimensioni restano invariate ($I = -1$).

# Diottri

<small>MNV: paragrafo 12.4</small>

Consideriamo ora una superficie diottrica sferica convessa che separi due mezzi con indice di rifrazione diverso (ad esempio aria e vetro). Poniamo che quello a sinistra abbiamo $n_1$ e quello a destra $n_2$, con $n_1 < n_2$. Utilizzando le stesse definizioni e convenzioni di prima troviamo subito 

$$
\theta_i = \theta + \alpha, \quad \alpha = \theta' + \theta_t,
$$

dove $\theta_t$ è ora l'angolo tra la normale al punto di incidenza e il raggio rifratto. Applicando la legge di Snell in approssimazione parassiale troviamo

$$
n_1 \theta_i = n_2 \theta_t.
$$

Sostituendo nella relazione precedente si ottiene

$$
(n_2 - n_1) \alpha = n_1 \theta + n_2 \theta'.
$$

Nella stessa approssimazione di prima possiamo nuovamente scrivere una relazione tra gli angoli e le grandezze in gioco, e notando come $R$, $p$ e $q$ siano tutti positivi si trova

$$
\theta = \frac{h}{p}, \quad \theta' = \frac{h}{q}, \quad \alpha = \frac{h}{R}.
$$

Sostituendo queste relazioni in quella che lega tra di loro gli angoli si trova

$$
\frac{n_1}{p} + \frac{n_2}{q} = \frac{n_2 - n_1}{R}
$$

che è detta equazione del diottro sferico convesso. Nell'approssimazione parassiale, come per il caso degli specchi, vediamo come la relazione che lega $p$, $q$ ed $R$ non dipende dagli angoli, e quindi il diottro sferico è anch'esso stigmatico. 

Applicando la formula si vede come, se $p = \infty$, l'immagine si forma ad una distanza dal vertice $V$ pari a 

$$
q_\infty = \frac{n_2 R}{n_2 - n_1} \equiv f_2.
$$

Il punto distante $f_2$ da $V$ è detto fuoco posteriore del diottro. D'altro canto, se l'immagine si trova all'infinito ($q = \infty$) significa che l'oggetto si trova ad una distanza da $V$ pari a

$$
p_\infty = \frac{n_1 R}{n_2 - n_1} \equiv f_1.
$$

Il punto distante $f_1$ da $V$ è detto fuoco anteriore del diottro. Si trova, come per gli specchi, che i raggi passanti per il centro di curvatura non vengono deviati.

Se l'oggetto è posto in un punto intermedio tra $f_1$ e $V$ si trova che i raggi sono *divergenti* e $q$ prende un valore negativo, cioè l'immagine risulta *virtuale*.

L'equazione trovata per il caso specifico di un diottro sferico convesso vale anche per un diottro sferico concavo, ed in entrambi i casi è valida sia che si passi da un mezzo con indice di rifrazione minore ad uno maggiore che viceversa.

Se l'oggetto non è puntiforme si può ancora una volta definire l'ingrandimento trasversale che, utilizzando la stessa costruzione vista per gli specchi, vale

$$
I = \frac{y'}{y} = \frac{n_1 q}{n_2 p} = \frac{f_1}{p - f_1} = \frac{q - f_2}{f_2}.
$$

Se $R \to \infty$, il diottro diventa piano e si ha

$$
q = -\frac{n_2}{n_1}p,
$$

cioè l'immagine è sempre virtuale e $I = -1$.

# Lenti sottili

<small>MNV: paragrafo 12.5</small>

Consideriamo due diottri che delimitano una regione di spazio. A sinistra e a destra dei diottri il mezzo ha indice di rifrazione $n_1$, mentre al centro c'è un blocco di materiale trasparente di spessore $s$ avente indice di rifrazione $n_2$, con $n_2 > n_1$. Se i due diottri hanno indici di curvatura $R_1$ ed $R_2$ le equazioni che determinano il comportamento ottico del sistema sono

$$
\frac{n_1}{p_1} + \frac{n_2}{q_1} = \frac{n_2 - n_1}{R_1}
$$

$$
\frac{n_2}{p_2} + \frac{n_1}{q_2} = \frac{n_1 - n_2}{R_2}
$$

$$
p_2 = s - q_1,
$$

dove l'ultima equazione indica che l'immagine del primo diottro funge da oggetto per il secondo. Queste equazioni si semplificano nell'approssimazione di *lente sottile*, per cui vale $s = 0$ e si considerano i vertici dei due diottri essenzialmente coincidenti. Utilizzando questa approssimazione $p_2 = -q_1$ e quindi

$$
\frac{n_1}{p_1} + \frac{n_1}{q_2} = (n_2 - n_1) \left( \frac{1}{R_1} - \frac{1}{R_2} \right).
$$

Nell'approssimazione utilizzata $p_1$ e $q_2$ sono le distanze di oggetto e immagine dalla lente e quindi li chiamiamo $p$ e $q$. Se uno tra questi due valori è pari a $\infty$ troviamo che l'altro prende il valore

$$
\frac{1}{f} = \frac{n_2 - n_1}{n_1} \left( \frac{1}{R_1} - \frac{1}{R_2} \right)
$$

che chiamiamo distanza focale (o semplicemente focale) della lente. Questa quantità indica la distanza dei due fuochi (uno a sinistra e uno a destra) dal vertice della lente. L'equazione della lente sottile si può quindi scrivere più semplicemente come

$$
\frac{1}{p} + \frac{1}{q} = \frac{1}{f}.
$$

La quantità $1 / f$ si chiama *potere convergente* della lente e si misura in diottrie (m$^{-1}$) e può essere sia positiva (lente convergente) che negativa (lente divergente). Si può ancora una volta definire l'ingrandimento trasversale, che vale

$$
I = \frac{y'}{y} = \frac{q}{p} = \frac{q - f}{f} = \frac{f}{p - f}.
$$

# Aberrazioni (cenni)

<small>MNV: parte del paragrafo 12.6</small>

Le equazioni che abbiamo ricavato nei paragrafi precedenti valgono solo nell'approssimazione parassiale, cioè per raggi che formano piccoli angoli con l'asse ottico. Se questo non è il caso, oppure se la luce non è monocromatica, il sistema ottico dà luogo ad *aberrazioni*: si ottiene un'immagine che è diversa da quella che si vorrebbe ottenere. Elenchiamo brevemente alcuni tipi di aberrazione

* *Aberrazione cromatica*: poiché l'indice di rifrazione di un materiale dipende dalla lunghezza d'onda della luce incidente, la distanza focale di una lente è anch'essa funzione di $\lambda$. Ne consegue che un oggetto che emetta luce non monocromatica darà diverse immagini colorate, ognuna delle quali avrà una distanza ed un ingrandimento differenti. Questo problema si può risolvere utilizzando un sistema composto da più lenti.
* *Aberrazione di sfericità*: gli specchi e le lenti sferiche sono stigmatici solo per raggi parassiali. Questo problema (che si presenta ad esempio in astronomia) si può risolvere utilizzando specchi a forma di paraboloidi di rotazione.
* *Distorsione*: in generale, l'ingrandimento trasversale $I$ non è indipendente dalla distanza dall'asse (come invece si trova in approssimazione parassiale). Lenti che hanno questo problema danno immagini che non hanno le stesse proporzioni degli oggetti che le generano. Questo effetto è piuttosto frequente, ad esempio, in obiettivi fotografici grandangolari. A [questo](http://www.digitalnewschannel.com/fotografia-tecnica/le-aberrazioni-ottiche-come-quando-e-perche-2598/distorsioni-e-curvatura-di-campo) link si possono trovare alcuni esempi di distorsioni.

