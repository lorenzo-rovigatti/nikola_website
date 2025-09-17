#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NSAMPLE 10000
#define N 10

void init_prob(double *p);
void metropolis(double *p, int *samples);
void frequency(int *samples, double *freq);

int main() {
    double p[N];
    double freq[N] = {0};
    int samples[NSAMPLE];

    srand48(time(NULL));

    init_prob(p);
    metropolis(p, samples);
    frequency(samples, freq);

    FILE *out = fopen("frequency.dat", "w");
    int i;
    for(i = 0; i < N; i++) {
        fprintf(out, "%d %.4lf %.4lf\n", i, p[i], freq[i]);
    }
    fclose(out);

    return 0;
}

void init_prob(double *p) {
    int i;
    double norm = 0.;
    for(i = 0; i < N; i++) {
        p[i] = drand48();
        norm += p[i];
    }
    for(i = 0; i < N; i++) {
        p[i] /= norm;
    }
}

void metropolis(double *p, int *samples) {
    int n_init = drand48() * N;
    int i, j;
    int n_prev = n_init;
    for(i = 0; i < NSAMPLE; i++) {
        int n_tmp = drand48() * N;
        double p_tmp = p[n_tmp];
        double p_prev = p[n_prev];
        double A = p_tmp / p_prev;
        if(A > 1 || drand48() <= A) {
            n_prev = n_tmp;
        }
        samples[i] = n_prev;
    }
}

void frequency(int *samples, double *freq) {
    int i;
    for(i = 0; i < NSAMPLE; i++) {
        freq[samples[i]]++;
    }
    for(i = 0; i < N; i++) {
        freq[i] /= NSAMPLE;
    }
}
