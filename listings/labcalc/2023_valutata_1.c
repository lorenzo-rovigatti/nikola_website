#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PMIN 1
#define PMAX 10000

void inserimento(int *Np);
int gioca(int *passi, int N);
void salva_freq(int *passi, int Np, int passi_max);

int main() {
    int Np, i;
    int passi[100] = {0};
    int N_mario = 0;
    
    srand48(time(NULL));
    
    inserimento(&Np);
    
    for(i = 0; i < Np; i++) {
        int N = drand48() * 11 + 10;
        int risultato = gioca(passi, N);
        N_mario += risultato;
    }
    
    salva_freq(passi, Np, 100);
    
    printf("Resoconto:\n----------\n");
    printf("N partite: %d\nN vittorie di Gino: %d\nN vittorie di Mario: %d\n", Np, Np - N_mario, N_mario);
    
    return 0;
}

void inserimento(int *Np) {
    *Np = 0;
    do {
        printf("Inserire il numero di partite da giocare, compreso tra %d e %d: \n", PMIN, PMAX);
        scanf("%d", Np);
    } while(*Np < PMIN || *Np > PMAX);
}

int gioca(int *passi, int N) {
    int N_passi = 0;
    int estratti[21] = {0};
    int P = N;
    while(P > 0 && P < 4 * N) {
        int k = drand48() * N + 1;
        if(estratti[k]) {
            P -= k;
        }
        else {
            P += k;
        }
        estratti[k] = 1;
        N_passi++;
    }
    
    passi[N_passi]++;
    
    return (P <= 0);
}

void salva_freq(int *passi, int Np, int passi_max) {
    int i;
    FILE *output = fopen("passi.dat", "w");
    if(output == NULL) {
      printf("Impossibile aprire il file\n");
      exit(1);
    }
    for(i = 0; i < passi_max; i++) {
        fprintf(output, "%d %.4lf\n", i, passi[i] / (double) Np);
    }
    fclose(output);
}
