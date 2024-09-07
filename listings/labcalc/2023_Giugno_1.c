#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NPMIN 3
#define NPMAX 50
#define TRIES 10000

void genera_compleanni(int compleanni[NPMAX], int N);
int controlla_compleanni(int compleanni[NPMAX], int N);
void salva_frequenze(double prob[NPMAX - NPMIN + 1]);

int main() {
    srand48(time(NULL));
    int compleanni[NPMAX];
    double prob[NPMAX - NPMIN + 1];
    int N, i;

    for(N = NPMIN; N <= NPMAX; N++) {
        for(i = 0; i < TRIES; i++) {
            genera_compleanni(compleanni, N);
            prob[N - NPMIN] += controlla_compleanni(compleanni, N);
        }
        prob[N - NPMIN] /= TRIES;
        double delta_PN = sqrt(prob[N - NPMIN] * (1 - prob[N - NPMIN]) / N);

        printf("Gruppo di %2d persone: P = %.3lf +- %.2lf%% (con %d gruppi simulati)\n", N, prob[N - NPMIN], delta_PN, TRIES);

    }

    salva_frequenze(prob);

    return 0;
}

void genera_compleanni(int compleanni[NPMAX], int N) {
    int i;
    for(i = 0; i < N; i++) {
        compleanni[i] = drand48() * 365 + 1;
    }
}

int controlla_compleanni(int compleanni[NPMAX], int N) {
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = i + 1; j < N; j++) {
            if(compleanni[i] == compleanni[j]) {
                return 1;
            }
        }
    }

    return 0;
}

void salva_frequenze(double prob[NPMAX - NPMIN + 1]) {
    int i;
    FILE *output = fopen("compleanno.dat", "w");

    for(i = 0; i < (NPMAX - NPMIN + 1); i++) {
        fprintf(output, "%d %lf\n", i + NPMIN, prob[i]);
    }

    fclose(output);
}
