#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define NZERI 10000
#define BINS 20

void ordina_zeri(double zeri[2]);
double calc_err(double zeri_th[2], double zeri_num[2]);
void solve_quadratic(double c[2], double zeri[2]);
void solve_quadratic_best(double c[2], double zeri[2]);
void updisto(int isto[BINS], double epsilon);

int main() {
    srand48(time(NULL));
    int i;
    int istoA[BINS] = {0}, istoB[BINS] = {0};
    double zeri_th[2], zeri_num[2], zeri_num_best[2];
    double c[2];
    double epsilon, epsilon_best;
    
    for(i = 0; i < NZERI; i++) {
        zeri_th[0] = 1e30 + (drand48() - 0.5) * 1e20;
        zeri_th[1] = 1e-30 + drand48() * 1e20;
        c[0] = zeri_th[0] * zeri_th[1];
        c[1] = -(zeri_th[0] + zeri_th[1]);
        solve_quadratic(c, zeri_num);
        solve_quadratic_best(c, zeri_num_best);
        
        ordina_zeri(zeri_th);
        ordina_zeri(zeri_num);
        ordina_zeri(zeri_num_best);
        
        epsilon = calc_err(zeri_th, zeri_num);
        updisto(istoA, epsilon);
        epsilon_best = calc_err(zeri_th, zeri_num_best);
        updisto(istoB, epsilon_best);
        if(i < 10) {
             printf("%.15G %.15G %.15G %.15G\n", zeri_th[0], zeri_th[1], epsilon, epsilon_best);
        }
    }
    
    FILE *out = fopen("isto.dat", "w");
    
    for(i = 0; i < BINS; i++) {
        fprintf(out, "%d %lf %lf\n", i, istoA[i] / (double) NZERI, istoB[i] / (double) NZERI);
    }
    
    fclose(out);
    
    return 0;
}

void ordina_zeri(double zeri[2]) {
    if(zeri[0] > zeri[1]) {
        double tmp = zeri[0];
        zeri[0] = zeri[1];
        zeri[1] = tmp;
    }
}

double calc_err(double zeri_th[2], double zeri_num[2]) {
    return fabs((zeri_th[0] - zeri_num[0]) / zeri_th[0]) + fabs((zeri_th[1] - zeri_num[1]) / zeri_th[1]);
}

void solve_quadratic(double c[2], double zeri[2]) {
    double delta = c[1] * c[1] - 4 * c[0];
    zeri[0] = (-c[1] + delta) / 2.0;
    zeri[1] = (-c[1] - delta) / 2.0;
}

void solve_quadratic_best(double c[2], double zeri[2]) {
    double delta = c[1] * c[1] - 4 * c[0];
    if(c[1] >= 0) {
        zeri[0] = -(c[1] + sqrt(delta)) / 2.0;
    }
    else {
        zeri[0] = (-c[1] + sqrt(delta)) / 2.0;
    }
    if(zeri[0] == 0.0) {
        zeri[1] = 0.0;
    }
    else {
        zeri[1] = c[0] / zeri[0];
    }
}

void updisto(int isto[BINS], double epsilon) {
    int k = floor(log10(epsilon) + BINS);
    
    if(k >= 0 && k < BINS) {
        isto[k]++;
    }
}
