#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NNUMERI 90
#define NESTRATTI 5
#define NMAX 50
#define NSIM 10000

void estrazione(int estratti[NESTRATTI]) {
    int i, n = 0;
    while(n < NESTRATTI) {
        int estratto = drand48() * 90 + 1;
        int trovato = 0;
        for(i = 0; i < n; i++) {
            if(estratti[i] == estratto) trovato = 1;
        }
        if(!trovato) {
            estratti[n] = estratto;
            n++;
        }
    }
}

void print_array(int estratti[NESTRATTI]) {
    int i;
    for(i = 0; i < NESTRATTI; i++) {
        printf("%d ", estratti[i]);
    }
    printf("\n");
}

int check_numero(int estratti[NESTRATTI], int M) {
    int i;
    for(i = 0; i < NESTRATTI; i++) {
        if(estratti[i] == M) return 1;
    }
    return 0;
}

int main() {
    srand48(412329);
    int i, j, k;
    int M = 37;
    double cumulativa[NMAX] = {0};
    double p = 1.0 / 18.0;
    /*do {
        printf("Inserire un numero compreso tra 1 e 90: ");
        scanf("%d", &M);
    } while(M < 1 || M > 90);*/
    
    int estratti[NESTRATTI];
    int M_non_estratto = 0;
    for(j = 0; j < NSIM; j++) {
        int estratto_M = 0;
        for(i = 0; i < NMAX && !estratto_M; i++) {
            estrazione(estratti);
            if(i < 5 && j == 0) {
                printf("Estrazione n. %d: ", i + 1);
                print_array(estratti);
            }
            estratto_M = check_numero(estratti, M);
        }
        for(k = i; k < NMAX; k++) {
            cumulativa[k] += 1.0;
        }
        if(i == NMAX) {
            M_non_estratto += 1;
        }
    }
    
    FILE *out = fopen("cumulativa.dat", "w");
    for(k = 0; k < NMAX; k++) {
        cumulativa[k] /= NSIM;
        double prob_th = 1.0 - pow(1.0 - p, k);
        fprintf(out, "%d %lf %lf\n", k, cumulativa[k], prob_th);
    }
    fclose(out);
    
    printf("Il numero di esperimenti in cui %d non è stato estratto è %d (%.2lf%%)\n", M, M_non_estratto, M_non_estratto / (double) NSIM * 100);
    
    /*if(i == NMAX) {
        printf("Il numero %d non e' uscito nelle prime %d estrazioni.\n", M, NMAX);
    }
    else {
        printf("Il numero %d e' uscito per la prima volta all'estrazione %d.\n", M, i);
    }*/
    
    return 0;
}
