#include <stdio.h>
#include <stdlib.h>

#define L 100
#define PROB 0.8
#define WARMUP 1000
#define MEASURE 2000

int sweep(int strada[L]);

int main() {
    srand48(123456);
    
    int strada[L];
    int i, N;
    
    FILE *out = fopen("traffico.dat", "w");
    
    for(N = 5; N <= 95; N += 5) {
        // inizializziamo la strada
        for(i = 0; i < L; i++) {
            strada[i] = (i < N); // 1 o 0, a seconda del valore di i
        }
        int movimenti = 0;
        
        for(i = 0; i < WARMUP; i++) {
            sweep(strada);
        }
        
        for(i = 0; i < MEASURE; i++) {
            movimenti += sweep(strada);
        }
        
        double rho = N / (double) L;
        double J = movimenti / (double) (MEASURE * L);
        fprintf(out, "%lf %lf\n", rho, J);
    }
    
    fclose(out);
    
    return 0;
}

int sweep(int strada[L]) {
    int i;
    int movimenti = 0;
    for(i = 0; i < L; i++) {
        int cell = drand48() * L;
        int next_cell = cell + 1;
        // condizioni periodiche al bordo
        if(cell + 1 == L) {
            next_cell = 0;
        }
        
        if(strada[cell] == 1 && strada[next_cell] == 0) {
            if(drand48() < PROB) {
                // spostiamo la macchina in avanti
                strada[cell] = 0;
                strada[next_cell] = 1;
                movimenti++;
            }
        }
    }
    
    return movimenti;
}
