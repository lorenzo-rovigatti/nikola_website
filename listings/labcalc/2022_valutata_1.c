#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POINTS 50
#define A 0.1
#define B -0.5
#define NOISE 0.2

void generate_points(double x[], double y[]);

void least_squares(double x[], double y[], double *m, double *q);

int main() {
    srand48(time(NULL));
    double x[POINTS], y[POINTS];
    double m, q;
    int i;
    
    generate_points(x, y);
    
    FILE *output = fopen("points.dat", "w");
    for(i = 0; i < POINTS; i++) {
        fprintf(output, "%.3lf %.3lf\n", x[i], y[i]);
    }
    fclose(output);
    
    least_squares(x, y, &m, &q);
    
    output = fopen("fit.dat", "w");
    for(i = 0; i < POINTS; i++) {
        fprintf(output, "%.3lf %.3lf\n", x[i], m * x[i] + q);
    }
    fclose(output);
    
    return 0;
}

void generate_points(double x[], double y[]) {
    int i;
    for(i = 0; i < POINTS; i++) {
        x[i] = (double) i;
        y[i] = A * x[i] + B + (drand48() - 0.5) * NOISE;
    }
}

void least_squares(double x[], double y[], double *m, double *q) {
    double x_sum = 0, y_sum = 0, xy_sum = 0, x2_sum = 0; 
    int i;
    
    for(i = 0; i < POINTS; i++) {
        x_sum += x[i];
        y_sum += y[i];
        xy_sum += x[i] * y[i];
        x2_sum += x[i] * x[i];
    }
    
    *m = (POINTS * xy_sum - x_sum * y_sum) / (POINTS * x2_sum - x_sum * x_sum);
    *q = (y_sum - *m * x_sum) / POINTS;
}
