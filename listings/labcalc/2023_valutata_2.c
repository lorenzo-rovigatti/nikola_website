#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMIN 1000
#define NMAX 10000000

void inserimento(int *Np);
int genera_numero();
void salva_histo(int *histo, int Np);

int main() {
    int Np, i;
    int N_gino = 0;
    int min_colpi = 50;
    int max_colpi = 0;
    int histo[50] = {0};

    inserimento(&Np);
    srand48(time(NULL));

    for(i = 0; i < Np; i++) {
        int num = genera_numero(31000, 32000);
        int N_colpi = 1;
        while(num > 1) {
            if(num % 2 == 0) {
                num /= 2;
            }
            else {
                num--;
            }
            N_colpi++;
        }
        if(N_colpi % 2) {
            N_gino++;
            if(N_colpi > max_colpi) {
                max_colpi = N_colpi;
            }
            if(N_colpi < min_colpi) {
                min_colpi = N_colpi;
            }
        }
        histo[N_colpi - 1]++;
    }

    salva_histo(histo, Np);

    printf("Giocate %d partite\n", Np);
    printf("Gino ha vinto %d partite, Mario %d\n", N_gino, Np - N_gino);
    printf("Minimo di colpi: %d, massimo di colpi: %d\n", min_colpi, max_colpi);

    return 0;
}

void inserimento(int *Np) {
    int res;
    *Np = 0;
    do {
        printf("Inserire il numero di partite da giocare, compreso tra %d e %d: \n", NMIN, NMAX);
        res = scanf("%d", Np);
    } while(*Np < NMIN || *Np > NMAX || res != 1);
}

int genera_numero(int N1, int N2) {
    return drand48() * (N2 - N1 + 1) + N1;
}

void salva_histo(int *passi, int Np) {
    int i;
    FILE *output = fopen("freq.dat", "w");
    if(output == NULL) {
      printf("Impossibile aprire il file\n");
      exit(1);
    }
    for(i = 0; i < 50; i++) {
        if(passi[i] > 0) {
            fprintf(output, "%d %.10lf\n", i + 1, passi[i] / (double) Np);
        }
    }
    fclose(output);
}
