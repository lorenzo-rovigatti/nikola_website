#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define THETA 0.5
#define H 2.0
#define N_MC 100000
#define SQR(x) ((x) * (x))

double input();
double raggio(double y_p, double theta);
double V_teorico(double h, double R, double y_p, double r);
double V_MC(double h, double R, double y_p);

int main() {
    double y_p;
    double R = raggio(H, THETA);
    double y_max = input();
    double delta_y = (H + y_max) / 50;
    
    FILE *output = fopen("volume.dat", "w");
    for(y_p = -H; y_p < y_max; y_p += delta_y) {
        double r = raggio(y_p, THETA);
        double Vth = V_teorico(H, R, y_p, r);
        double Vmc = V_MC(H, R, y_p);
        
        fprintf(output, "%.3lf %.3lf %.3lf\n", y_p, Vmc, Vth);
    }
    fclose(output);
    
    return 0;
}

double input() {
    double y_max;
    do {
        printf("Inserire il valore massimo di y da considerare: ");
        scanf("%lf", &y_max);
    }
    while(y_max > 0 || y_max < -H);
    
    return y_max;
}

double raggio(double y_p, double theta) {
    return fabs(y_p) * tan(theta);
}

double V_teorico(double h, double R, double y_p, double r) {
    return M_PI / 3 * (SQR(R) * h - SQR(r) * fabs(y_p));
}

double V_MC(double h, double R, double y_p) {
    int i;
    int Np = 0;
    double V_paral = SQR(2 * R) * H;
    
    for(i = 0; i < N_MC; i++) {
        double x = (drand48() - 0.5) * 2 * R;
        double y = -drand48() * H;
        double z = (drand48() - 0.5) * 2 * R;
        
        if(y < y_p) {
            double r = raggio(y, THETA);
            if(SQR(x) + SQR(z) < SQR(r)) {
                Np++;
            }
        }
    }
    
    return V_paral * Np / (double) N_MC;
}
