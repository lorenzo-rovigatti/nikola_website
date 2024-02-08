#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SQR(x) ((x) * (x))
#define LMIN 1.0
#define LMAX 5.0
#define NTRIES 10

void estrai(double punto[2], double l);
int dentro_intersez(double punto[2], double l);
double inserimento();

int main() {
    srand48(time(NULL));
    double l = inserimento();
    double R = sqrt(2) * l / 2.0;
    double C1[2] = {0, 0};
    double C2[2] = {l, l};
    int i, N, try;
    int N_in = 0;
    double punto[2];

    FILE *out = fopen("errore.dat", "w");
    for(N = 10; N <= 1000000; N *= 10) {
        double avg = 0., avg_sqr = 0.;
        for(try = 0; try < NTRIES; try++) {
            N_in = 0;
            for(i = 0; i < N; i++) {
                estrai(punto, l);

                if(dentro_intersez(punto, l)) {
                    N_in++;
                }
            }

            double A_MC = 8 * SQR(l) * N_in / (double) N;
            avg += A_MC;
            avg_sqr += SQR(A_MC);
        }
        avg /= NTRIES;
        avg_sqr /= NTRIES;
        
        double std_dev = sqrt((avg_sqr - avg*avg) / NTRIES);

        double A_th = 4 * SQR(l) * atan(2);
        printf("%lf %lf\n", A_th, avg); // commentata dopo aver controllato che il codice funziona
        fprintf(out, "%.5lf %.5lf\n", log10(N), log10(std_dev));
    }
    fclose(out);

    return 0;
}

void estrai(double punto[2], double l) {
    punto[0] = 2.0 * drand48() * l;
    punto[1] = drand48() * l;
}

int dentro_intersez(double punto[2], double l) {
    return (SQR(punto[0]) + 4 * SQR(punto[1]) < 4 * SQR(l) && punto[1] < punto[0]);
}

double inserimento() {
    double l = 0;
    while(l < LMIN || l > LMAX) {
        printf("Inserire un valore compreso tra 1 e 5\n");
        scanf("%lf", &l);
    }

    return l;
}
