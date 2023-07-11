#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define POINTS 50
#define MIN -5.0
#define MAX -2.0
#define SQR(x) ((x) * (x))

void generate_points(double v[]);
double excluding_average(double v[], int da_escludere);

int main() {
    srand48(time(NULL));
    double values[POINTS];
    int i;
    
    generate_points(values);
    
    FILE *output = fopen("misure.dat", "w");
    for(i = 0; i < POINTS; i++) {
        fprintf(output, "%.3lf\n", values[i]);
    }
    fclose(output);
    
    double media_jk = 0.;
    for(i = 0; i < POINTS; i++) {
        media_jk += excluding_average(values, i);;
    }
    media_jk /= POINTS;
    
    output = fopen("media.dat", "w");
    for(i = 0; i < POINTS; i++) {
        fprintf(output, "%.3lf\n", media_jk);
    }
    fclose(output);
    
    return 0;
}

void generate_points(double v[]) {
    int i;
    for(i = 0; i < POINTS; i++) {
        v[i] = drand48() * (MAX - MIN) + MIN;
    }
}

double excluding_average(double v[], int da_escludere) {
    int i;
    double m = 0;
    for(i = 0; i < POINTS; i++) {
        if(i != da_escludere) {
            m += v[i];
        }
    }
    m /= POINTS - 1;
    
    return m;
}
