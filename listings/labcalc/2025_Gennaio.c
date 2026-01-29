#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMIN 2000
#define NMAX 16000
#define B    0.2

void inserimento(const char *msg, int *d, int dmin, int dmax);
void genera_seq(int N, double xi[]);
void smussa_seq(int N, int k, const double xi[], double xis[]);
void stampa_seqs(int N, int k, const double xi[], const double xis[]);

int main() {
    int N, k;

    double xi[NMAX];
    double xis[NMAX];

    srand48(138);

    // la stringa che passo a inserimento() è un template che verrà utilizzato
    // all'interno della funzione per stampare i valori corretti dell'intervallo
    // questa è una tecnica piuttosto avanzata: se avete fatto diversamente
    // non è un problema
    inserimento("Inserisci N (%d <= N <= %d): ", &N, NMIN, NMAX);
    inserimento("Inserisci k (%d <= k <= %d): ", &k, 1, N / 10);

    genera_seq(N, xi);
    smussa_seq(N, k, xi, xis);
    stampa_seqs(N, k, xi, xis);

    return 0;
}

void inserimento(const char *msg, int *d, int dmin, int dmax) {
    do {
        printf(msg, dmin, dmax);
        scanf("%d", d);
    } while(*d < dmin || *d > dmax);
}

void genera_seq(int N, double xi[]) {
    int i;
    for(i = 0; i < N; i++) {
        double r = (2.0 * drand48() - 1.0) * B;
        xi[i] = r + cos(2.0 * M_PI * (double)i / (double)N);
    }
}

void smussa_seq(int N, int k, const double xi[], double xis[]) {
    int i, j;
    int w = 2 * k + 1;

    for(i = k; i <= N - 1 - k; i++) {
        double somma = 0.0;
        for(j = i - k; j <= i + k; j++) {
            somma += xi[j];
        }
        xis[i] = somma / (double)w;
    }
}

void stampa_seqs(int N, int k, const double xi[], const double xis[]) {
    FILE *fp = fopen("mediamobile.dat", "w");
    if(fp == NULL) {
        printf("Errore: impossibile aprire mediamobile.dat in scrittura.\n");
        return;
    }

    int i;
    for (i = k; i <= N - 1 - k; i++) {
        fprintf(fp, "%d %.4lf %.4lf\n", i, xi[i], xis[i]);
    }

    fclose(fp);
}
