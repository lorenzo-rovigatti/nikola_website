#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SQR(x) ((x) * (x))
#define LMIN 4.0
#define LMAX 10.0
#define NTRIES 10

void estrai(double *x, double *y, double a);
int dentro_circonferenza(double x, double y, double C[2], double R);
double inserimento();

int main() {
    srand48(time(NULL));
    double l = inserimento();
    double R = sqrt(2) * l / 2.0;
    double C1[2] = {0, 0};
    double C2[2] = {l, l};
    int i, N, try;
    int N_in = 0;
    double x, y;

    FILE *out = fopen("errore.dat", "w");
    for(N = 10; N <= 1000000; N *= 10) {
        double avg = 0., avg_sqr = 0.;
        for(try = 0; try < NTRIES; try++) {
            N_in = 0;
            for(i = 0; i < N; i++) {
                estrai(&x, &y, l);

                if(!dentro_circonferenza(x, y, C1, R) && !dentro_circonferenza(x, y, C2, R)) {
                    N_in++;
                }
            }

            double A_MC = 0.5 * SQR(l) * N_in / (double) N;
            avg += A_MC;
            avg_sqr += SQR(A_MC);
        }
        avg /= NTRIES;
        avg_sqr /= NTRIES;
        
        double std_dev = sqrt((avg_sqr - avg*avg) / NTRIES);

        //double A_th = 0.5 * l * l * (1.0 - M_PI / 4.0);
        //printf("%lf %lf\n", A_th, avg); // commentata dopo aver controllato che il codice funziona
        fprintf(out, "%.5lf %.5lf\n", log10(N), log10(std_dev));
    }
    fclose(out);

    return 0;
}

void estrai(double *x, double *y, double l) {
    *x = drand48() * l;
    *y = drand48() * l;
}

int dentro_circonferenza(double x, double y, double C[2], double R) {
    return sqrt(SQR(x - C[0]) + SQR(y - C[1])) < R;
}

double inserimento() {
    double l = 0;
    while(l < LMIN || l > LMAX) {
        printf("Inserire un valore compreso tra %lf e %lf\n", LMIN, LMAX);
        scanf("%lf", &l);
    }

    return l;
}
