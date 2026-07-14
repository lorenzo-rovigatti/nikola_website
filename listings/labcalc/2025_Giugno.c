#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define N0 100000
#define LAMBDA_A 0.05
#define LAMBDA_B 0.02
#define DT 0.5
#define TMAX 200.0

void aggiorna_atomi(int *N, double p);
void simula_passo(int *NA, int *NB, double pa, double pb);

int main() {
    srand48(1209382);
    
    int NA = N0;
    int NB = 0;

    double pa = LAMBDA_A * DT;
    double pb = LAMBDA_B * DT;

    int max_NB = 0;
    double max_t;

    FILE *out = fopen("catena.dat", "w");
    if(out == NULL) {
      printf("Errore nell'apertura del file 'catena.dat'\n");
      exit(1);
    }
    for(double t = 0.; t < TMAX; t += DT) {
        simula_passo(&NA, &NB, pa, pb);
        double NA_th = N0 * exp(-LAMBDA_A * t);
        double NB_th = N0 * LAMBDA_A / (LAMBDA_B - LAMBDA_A) * (exp(-LAMBDA_A * t) - exp(-LAMBDA_B * t));

        fprintf(out, "%.2f %d %.8f %d %.8f\n", t, NA, NA_th, NB, NB_th);

        if(NB > max_NB) {
            max_NB = NB;
            max_t = t;
        }
    }
    fclose(out);

    /* ho calcolato il massimo teorico facendo la derivata dell'eq (2), ma va bene
       anche calcolare il massimo numericamente, come si fa per i valori di simulazione */
    double max_t_th = log(LAMBDA_A / LAMBDA_B) / (LAMBDA_A - LAMBDA_B);
    double max_NB_th = N0 * LAMBDA_A / (LAMBDA_B - LAMBDA_A) * (exp(-LAMBDA_A * max_t_th) - exp(-LAMBDA_B * max_t_th));
    printf("I valori massimi numerici e teorici sono: %d (al tempo %lf) e %lf (al tempo %lf)\n", max_NB, max_t, max_NB_th, max_t_th);

    return 0;
}

void aggiorna_atomi(int *N, double p) {
    if(drand48() < p) *N += 1;
}

void simula_passo(int *NA, int *NB, double pa, double pb){
    int i;
    int diventa_B = 0;
    int diventa_C = 0;
    for(i = 0; i < *NA; i++) {
        aggiorna_atomi(&diventa_B, pa);
    }
    for(i = 0; i < *NB; i++) {
        aggiorna_atomi(&diventa_C, pb);
    }

    *NA -= diventa_B;
    *NB += diventa_B - diventa_C;
}
