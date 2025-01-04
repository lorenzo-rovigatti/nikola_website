#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define L 10.0
#define N_BINS 20
#define LAMBDA 1.0

int inserimento();
void genera_posizione(double pos[2]);
double calcola_media(double prob[N_BINS], double bin_size);

int main() {
    srand48(time(NULL));
    int N = inserimento();
    int i;
    int hist_x[N_BINS] = {0};
    int hist_z[N_BINS] = {0};
    double prob_dist_x[N_BINS], prob_dist_z[N_BINS];
    double bin_size = L / (double) N_BINS;
    
    for(i = 0; i < N; i++) {
        double pos[2];
        genera_posizione(pos);
        hist_x[(int)(pos[0] / bin_size)]++;
        hist_z[(int)(pos[1] / bin_size)]++;
    }

    for(i = 0; i < N_BINS; i++) {
        prob_dist_x[i] = hist_x[i] / (double) N;
        prob_dist_z[i] = hist_z[i] / (double) N;
    }
    
    printf("Media lungo x: %.5lf\n", calcola_media(prob_dist_x, bin_size));
    printf("Media lungo z: %.5lf\n", calcola_media(prob_dist_z, bin_size));
    
    FILE *out_x = fopen("prob_dist_x.dat", "w");
    FILE *out_z = fopen("prob_dist_z.dat", "w");
    
    for(i = 0; i < N_BINS; i++) {
        fprintf(out_x, "%.5lf %.5lf\n", (i + 0.5) * bin_size, prob_dist_x[i]);
        fprintf(out_z, "%.5lf %.5lf\n", (i + 0.5) * bin_size, prob_dist_z[i]);
    }
    
    fclose(out_x);
    fclose(out_z);
    
    return 0;
}

int inserimento() {
    int N = 0;
    printf("Inserisci il numero di particelle, che deve essere maggiore di 0 e minore di 10000\n");
    do {
        scanf("%d", &N);
        if(N <= 0 || N >= 10000) {
            printf("Valore fuori dall'intervallo (0, 10000), riprova!\n");
        }
    } while(N <= 0 || N >= 10000);
    
    return N;
}

void genera_posizione(double pos[2]) {
    pos[0] = drand48() * L;
    pos[1] = -log(1.0 - drand48()) / LAMBDA;
}

double calcola_media(double prob[N_BINS], double bin_size) {
    double media = 0.;
    int i;
    
    for(i = 0; i < N_BINS; i++) {
        media += (i + 0.5) * bin_size * prob[i];
    }
    
    return media;
}
