#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define D 4.0
#define L 100.0
#define KAPPA 10.66
#define OMEGA 3.198
#define A 20
#define SQR(x) ((x) * (x))

double distanza(double p[2], double q[2]) {
    double r_sqr = SQR(p[0] - q[0]) + SQR(p[1] - q[1]);
    return sqrt(r_sqr);
}

double intensita_media(double slit1[2], double slit2[2], double y) {
    double t;
    double I = 0;
    double schermo[2] = {L, y};
    
    int Nt = 0;
    for(t = 0; t < 10.0; t += 0.01, Nt++) {
        double dist1 = distanza(slit1, schermo);
        double dist2 = distanza(slit2, schermo);
        
        double E1 = cos(KAPPA * dist1 - OMEGA * t);
        double E2 = cos(KAPPA * dist2 - OMEGA * t);
        
        I += SQR(E1 + E2);
    }
    
    I /= (double) Nt; // il cast non è strettamente necessario, ma non guasta mai
    
    return I;
}

int input() {
    int N_punti;
    do {
        printf("Inserire il numero di punti da simulare:");
        scanf("%d", &N_punti);
    }
    while(N_punti <= 0);
    
    return N_punti;
}

int main() {
    srand48(123456);
    
    double slit1[2] = {0, D};
    double slit2[2] = {0, -D};
    
    int N_punti = input();
    
    FILE *output = fopen("interferenza.dat", "w");
    int i;
    for(i = 0; i < N_punti; i++) {
        double y = (drand48() - 0.5) * 2 * A;
        double I = intensita_media(slit1, slit2, y);
        double I_th = 2 * SQR(cos(KAPPA * D * y / L));
        
        fprintf(output, "%.2lf %.2lf %.2lf\n", y, I, I_th);
    }
    fclose(output);
    
    return 0;
}
