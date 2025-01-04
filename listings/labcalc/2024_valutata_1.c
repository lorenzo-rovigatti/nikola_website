#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define VL 0.0
#define VR 6.0
#define NMC 100000
#define NPTS 1000
#define SQR(X) ((X) * (X))

double func(double V, double KF) {
  double sigma_1 = 0.15;
  double sigma_2 = 0.45;
  double K1 = 1.0 / sqrt(2.0 * M_PI * SQR(sigma_1));
  double K2 = 1.0 / sqrt(2.0 * M_PI * SQR(sigma_2));
  double sig21 = 2.0 * SQR(sigma_1);
  double sig22 = 2.0 * SQR(sigma_2);
  double f = K1*exp(-pow(V - 2.0, 2.0) / sig21) + K2 * exp(-pow(V - 4.0, 2.0) / sig22);
  
  return f * pow(KF, V);
}

double calcarea(double vmin, double vmax, double kf) {
  int i;
  double v, sumf = 0.0;
  for (i = 0; i < NMC; i++) {
      v = drand48() * (vmax - vmin) + vmin;
      sumf += func(v, kf);
  }
  return (vmax - vmin) * sumf / NMC;
}

void salva_func(char *txt, double kf, double A) {
  int i;
  double v, dv;
  FILE *output = fopen(txt, "w");
  if(output == NULL) {
    printf("ERRORE APERTURA FILE\n");
    exit(0);
  }
  
  dv = (VR - VL) / NPTS;
  for(i = 0; i < NPTS; i++) {
    v = VL + i * dv;
    fprintf(output, "%.6f %.6f\n", v, func(v, kf) / A);
  }
  fclose(output);
  
}

int main() {
  srand48(time(NULL));
  double vmin = 2.577;
  double A1, A2, kf;
  
  A1 = calcarea(VL, VR, 0.6);
  salva_func("kf3.dat", 0.6, A1);
  
  for (kf = 0.6; kf < 2.0; kf += 0.05) {
      A1 = calcarea(VL, vmin, kf);
      A2 = calcarea(vmin, VR, kf);
      if(fabs(A1 - A2) < 0.03) {
        printf("A1 = %.5f, A2 = %.5f\n", A1, A2);
        printf("Il valore di k per cui le due aree sono uguali è %.5f\n", kf);
        salva_func("kfopt.dat", kf, A1 + A2);
      }
  }
  
  return 0;
}
