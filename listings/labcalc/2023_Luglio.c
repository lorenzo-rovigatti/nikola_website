#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 100000
#define M 5

int input();
void fill_sequence(char protein[M][M], double q);
double energy(char protein[M][M]);

int main() {
    int i, j, k;
    double q;
    char protein[M][M];
    FILE *out = fopen("protein.dat", "w");

    srand48(time(NULL));
    int Np = input();

    for(q = 0.0; q < 1.01; q += 0.1) {
        double E = 0.0;
        for(i = 0; i < Np; i++) {
            fill_sequence(protein, q);
            double E_i = energy(protein);
            E += E_i;

            if(i == 0) {
                printf("%lf ", q);
                for(j = 0; j < M; j++) {
                    for(k = 0; k < M; k++) {
                        printf("%c", protein[j][k]);
                    }
                }
                printf(" %.2lf\n", E_i);
            }
        }
        fprintf(out, "%.1lf %.2lf\n", q, E / Np);
    }

    fclose(out);

    return 0;
}

int input() {
    int Np = 0;
    do {
        fprintf(stderr, "Inserisci il numero di sequenze da generare (compreso tra 10 e 100000)\n");
        scanf("%d", &Np);
    } while(Np < 10 || Np > 100000);

    return Np;
}

void fill_sequence(char protein[M][M], double q) {
    int i, j;

    for(i = 0; i < M; i++) {
        for(j = 0; j < M; j++) {
            if(drand48() < q) {
                protein[i][j] = 'H';
            }
            else {
                protein[i][j] = 'P';
            }
        }
    }
}

double energy(char protein[M][M]) {
    int i, j, k;
    double E = 0;
    int coord_diff[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(i = 0; i < M; i++) {
        for(j = 0; j < M; j++) {
            for(k = 0; k < 4; k++) {
                int i_neigh = i + coord_diff[k][0];
                int j_neigh = j + coord_diff[k][1];
                if(i_neigh >= 0 && i_neigh < M && j_neigh >= 0 && j_neigh < M) {
                    if(protein[i][j] == 'H' && protein[i_neigh][j_neigh] == 'H') {
                        E += 1;
                    }
                }
            }
        }
    }

    return -E / 2.0;
}
