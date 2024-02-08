#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NLANCI 6
#define GMIN 1
#define GMAX 100000

void lanciaDadi(int dadi[NLANCI]);
void ordinaDadi(int dadi[NLANCI]);
void salvaFrequenze(int freq[NLANCI + 1], int Ng);

int main() {
    int Ng = 0, i, j;
    int freq[NLANCI + 1] = {0};
    int p1[NLANCI], p2[NLANCI];
    int N_gino = 0, N_pareggi = 0;
    srand48(time(NULL));

    do {
        printf("Inserire il numero di giocate, compreso tra %d e %d: \n", GMIN, GMAX);
        scanf("%d", &Ng);
    } while(Ng < GMIN || Ng > GMAX);

    for(i = 0; i < Ng; i++) {
        lanciaDadi(p1);
        lanciaDadi(p2);
        ordinaDadi(p1);
        ordinaDadi(p2);

        int P_gino = 0, P_mario = 0;
        for(j = 0; j < NLANCI; j++) {
            if(p1[j] > p2[j]) {
                P_gino++;
            }
            if(p2[j] > p1[j]) {
                P_mario++;
            }
        }
        freq[P_gino]++;
        if(P_gino > P_mario) {
            N_gino++;
        }
        else if(P_gino == P_mario) {
            N_pareggi++;
        }
    }

    salvaFrequenze(freq, Ng);

    printf("Numero giocate: %d\n", Ng);
    printf("Gino ha vinto %d volte, Mario ha vinto %d volte\n", N_gino, Ng - N_gino - N_pareggi);
    printf("Numero di pareggi: %d\n", N_pareggi);

    return 0;
}

void lanciaDadi(int dadi[NLANCI]) {
    int i;
    for(i = 0; i < NLANCI; i++) {
        dadi[i] = drand48() * 6 + 1;
    }
}

void ordinaDadi(int dadi[NLANCI]) {
    int i, j, tmp;
    for(i = 0; i < NLANCI - 1; i++) {
        for(j = 0; j < NLANCI - 1 - i; j++) {
            if(dadi[j] < dadi[j + 1]) {
                tmp = dadi[j];
                dadi[j] = dadi[j + 1];
                dadi[j + 1] = tmp;
            }
        }
    }
}

void salvaFrequenze(int freq[NLANCI + 1], int Ng) {
    int i;
    FILE *output = fopen("freq.dat", "w");
    if(output == NULL) {
      printf("Impossibile aprire il file\n");
      exit(1);
    }
    for(i = 0; i < NLANCI + 1; i++) {
        fprintf(output, "%d %.4lf\n", i, freq[i] / (double) Ng);
    }
    fclose(output);
}
