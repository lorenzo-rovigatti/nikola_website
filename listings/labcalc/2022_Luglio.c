#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NMAX 100
#define NC 1000

double lunghezza_polimero(int N, int polimero[NMAX][2]);
void genera_polimero(int N, int polimero[NMAX][2]);

int main() {
    srand48(time(NULL));
    
    int N, i;
    int polimero[NMAX][2];
    
    FILE *out = fopen("ree.dat", "w");
    for(N = 10; N <= NMAX; N++) {
        double media = 0;
        for(i = 0; i < NC; i++) {
            genera_polimero(N, polimero);
            media += lunghezza_polimero(N, polimero);
        }
        media /= NC;
        fprintf(out, "%d %lf\n", N, media);
    }
    fclose(out);
    
    return 0;
}

double lunghezza_polimero(int N, int polimero[NMAX][2]) {
    double distanza_x = polimero[0][0] - polimero[N - 1][0];
    double distanza_y = polimero[0][1] - polimero[N - 1][1];
    
    return sqrt(distanza_x * distanza_x + distanza_y * distanza_y);
}

void genera_polimero(int N, int polimero[NMAX][2]) {
    int i;
    polimero[0][0] = polimero[0][1] = 0;
    
    int mosse[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    
    for(i = 1; i < N; i++) {
        int mossa = lrand48() % 4;
        polimero[i][0] = polimero[i - 1][0] + mosse[mossa][0];
        polimero[i][1] = polimero[i - 1][1] + mosse[mossa][1];
    }
}
