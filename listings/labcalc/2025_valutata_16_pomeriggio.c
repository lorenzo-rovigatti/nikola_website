#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NPTS 5000
#define NTRIALS 200000
#define ALPHAMIN 5
#define ALPHAMAX 15

double onsager(double theta, double alpha);
void findmax(double alpha, double *f_max, double *theta_max);
double onsager_prob(double alpha, double f_max);
void salva_Sarr(double *Sarr);

int main() {
    srand48(time(NULL));

    int i;
    double f_max, theta_max;
    double Sarr[ALPHAMAX - ALPHAMIN + 1] = {0};

    int alpha;
    for(alpha = ALPHAMIN; alpha <= ALPHAMAX; alpha++) {
        findmax(alpha, &f_max, &theta_max);
        if(alpha == ALPHAMAX) {
            fprintf(stderr, "Valori di f_ons massima, e theta corrispondente: %.3lf %.3lf\n", f_max, theta_max);
        }

        for(i = 0; i < NTRIALS; i++) {
            double theta = onsager_prob(alpha, f_max);
            double P2_theta = (3 * cos(theta) * cos(theta) - 1.0) / 2.0;
            Sarr[alpha - ALPHAMIN] += P2_theta;
        }
        Sarr[alpha - ALPHAMIN] /= NTRIALS;
    }

    salva_Sarr(Sarr);
    
    return 0;
}

double onsager(double theta, double alpha) {
    return sin(theta) * alpha * cosh(alpha * cos(theta)) / (2.0 * sinh(alpha));
}

void findmax(double alpha, double *f_max, double *theta_max) {
    double dtheta = M_PI / NPTS;
    double theta;
    for(*f_max = 0.0, theta = 0.0; theta <= M_PI; theta += dtheta) {
        double val = onsager(theta, alpha);
        if(val > *f_max) {
            *f_max = val;
            *theta_max = theta;
        }
    }
}

double onsager_prob(double alpha, double f_max) {
    double x, y;
    do {
        x = drand48() * M_PI;
        y = drand48() * f_max;
    } while(y > onsager(x, alpha));
    
    return x;
}

void salva_Sarr(double *Sarr) {
    FILE *output = fopen("S_alpha.dat", "w");
    int alpha;
    for(alpha = ALPHAMIN; alpha <= ALPHAMAX; alpha += 1) {
        fprintf(output, "%d %.3lf\n", alpha, Sarr[alpha - ALPHAMIN]);
    }
    fclose(output);
}
