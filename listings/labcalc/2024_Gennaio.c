#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define NBINS 50
#define NCONFS 10000
#define L 13.0
#define SIGMA 1.0
#define SQR(X) ((X) * (X))

int sovrapposizione(double parts[N][2], int i);
void aggiorna_istogramma(double parts[N][2], int isto[NBINS]);
void salva_gr(int isto[NBINS]);

int main() {
    srand48(time(NULL));
    int conf, i;
    int isto[NBINS] = {0};
    double parts[N][2];
    
    for(conf = 0; conf < NCONFS; conf++) {
        parts[0][0] = parts[0][1] = 0.;
        for(i = 1; i < N; i++) {
            do {
                parts[i][0] = (drand48() - 0.5) * L;
                parts[i][1] = (drand48() - 0.5) * L;
            } while(sovrapposizione(parts, i));
        }
        aggiorna_istogramma(parts, isto);
    }
    
    salva_gr(isto);
    
    return 0;
}

int sovrapposizione(double parts[N][2], int i) {
    int j;
    int sovrapposta = 0;
    for(j = 0; j < i; j++) {
        double r_ij = sqrt(SQR(parts[j][0] - parts[i][0]) + SQR(parts[j][1] - parts[i][1]));
        if(r_ij <= SIGMA) {
            return 1;
        }
    }
    
    return 0;
}

void aggiorna_istogramma(double parts[N][2], int isto[NBINS]) {
    double delta_r = L / 200.;
    int i;
    
    for(i = 1; i < N; i++) {
        double r = sqrt(SQR(parts[i][0]) + SQR(parts[i][1]));
        int bin = r / delta_r;
        if(bin < NBINS) {
            isto[bin]++;
        }
    }
}

void salva_gr(int isto[NBINS]) {
    int alpha;
    double delta_r = L / 200.;
    double rho = (N - 1) / (SQR(L));
    FILE *out = fopen("gr.dat", "w");
    
    for(alpha = 0; alpha < NBINS; alpha++) {
        double r_alpha = (alpha + 0.5) * delta_r;
        double gr = isto[alpha] / (2 * M_PI * r_alpha * delta_r * rho * NCONFS);
        fprintf(out, "%.4lf %.4lf\n", r_alpha, gr);
    }
    
    fclose(out);
}
