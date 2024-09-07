#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6
#define N_ESTRAZIONI 3

int chiedi_nexp() {
    int nexp = 0;
    while(nexp < 1 || nexp > 10000) {
        printf("Inserire il numero di esperimenti, che deve essere compreso tra 1 e 10000:\n");
        scanf("%d", &nexp);
    }
}

void estrai(char palline[N_ESTRAZIONI]) {
    int N_rosse = N / 2;
    int N_blu = N / 2;
    int i;
    for(i = 0; i < N_ESTRAZIONI; i++) {
        int N_rimaste = N - i;
        if(drand48() * N_rimaste < (N_rimaste - N_blu)) {
            palline[i] = 'R';
            N_rosse--;
        }
        else {
            palline[i] = 'B';
            N_blu--;
        }
    }
}

int conta_rosse(char palline[N_ESTRAZIONI]) {
    int i;
    int N_rosse = 0;
    for(i = 0; i < N_ESTRAZIONI; i++) {
        if(palline[i] == 'R') {
            N_rosse++;
        }
    }
    
    return N_rosse;
}

int main() {
    srand48(time(NULL));
    int nexp = chiedi_nexp();
    int i, j;
    int N_tre_rosse = 0;
    
    for(i = 0; i < nexp; i++) {
        char palline[N_ESTRAZIONI];
        estrai(palline);
        if(i < 10) {
            fprintf(stderr, "Turno n. %d; Palline estratte: |", i);
            for(j = 0; j < N_ESTRAZIONI; j++) {
                fprintf(stderr, "%c|", palline[j]);
            }
            fprintf(stderr, "\n");
        }
        if(conta_rosse(palline) == N_ESTRAZIONI) {
            N_tre_rosse++;
        }
    }
    
    double frequenza = N_tre_rosse / (double) nexp;
    fprintf(stderr, "Numero di palline: %d, numero di esperimenti: %d, FRED: %lf\n", N, nexp, frequenza);
    
    return 0;
}
