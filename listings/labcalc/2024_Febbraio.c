#include <stdio.h>
#include <stdlib.h>

#define M 4
#define X_MAX 100
#define INF 100000

void inserisci_x(int *x);
int trova_min(int x, int m[X_MAX + 1], int V[M]);
void stampa_m(int m[X_MAX + 1], int indice, int x);

int main() {
    int V[3][4] = { 
        {1, 2, 3, 4},
        {1, 2, 3, 5},
        {1, 2, 3, 6}
    };
    int m[X_MAX + 1] = {0};
    int i, x, y;
    
    inserisci_x(&x);
    
    for(i = 0; i < 3; i++) {
        for(y = 1; y <= x; y++) {
            m[y] = trova_min(y, m, V[i]);
        }
        
        stampa_m(m, i, x);
    }
    
    return 0;
}

void inserisci_x(int *x) {
    do {
        printf("Inserisci un numero nell'intervallo [1, %d]\n", X_MAX);
        scanf("%d", x);
    } while(*x <= 1 || *x > X_MAX);
}

int trova_min(int x, int m[X_MAX + 1], int V[M]) {
    int i;
    int my_min = INF;
    for(i = 0; i < M; i++) {
        int arg = x - V[i];
        if(arg >= 0 && m[arg] < my_min) {
            my_min = m[arg] + 1;
        }
    }
    
    return my_min;
}

void stampa_m(int m[X_MAX + 1], int indice, int x) {
    char nomefile[256];
    sprintf(nomefile, "min_%d.dat", indice);
    FILE *out = fopen(nomefile, "w");
    int y;
    for(y = 0; y <= x; y++) {
        fprintf(out, "%d %d\n", y, m[y]);
    }
    
    fclose(out);
}
