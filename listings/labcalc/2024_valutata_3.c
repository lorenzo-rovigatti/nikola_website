#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define KAPPA 1.3
#define MASSA 0.9

double energy(double x, double v) {
  return 0.5 * MASSA * v * v + 0.5 * KAPPA * x * x;
}

void updSemiEuler(double *x, double *v, double dt) {
  *v += dt * (-KAPPA * (*x)) / MASSA;
  *x += dt * (*v);
}

void analytic(double t, double x0, double v0, double* x, double* v) {
  double w;
  w = sqrt(KAPPA / MASSA);
  *x = x0 * cos(w * t) + (v0 / w) * sin(w * t);
  *v = -w * x0 * sin(w * t) + v0 * cos(w * t);
}

void input(double *dt) {
  do {
    printf("Immetti il valore di dt, che deve essere compreso tra 0.001 e 0.01\n");
    scanf("%lf", dt);
    if(*dt < 0.001 || *dt > 0.01) {
      printf("Valore fuori dall'intervallo [0.001,0.01], riprova!\n");
    }
  } while(*dt < 0.001 || *dt > 0.01);
}

int main() {
  srand48(time(NULL));
  int i, nsteps;
  double VMIN = 0.5, VMAX = 1.5, x0 = 1.0;
  double dt, xA, vA, eneA, eneSE;
  double v0 = VMIN + drand48() * (VMAX - VMIN);
  double xSE = x0;
  double vSE = v0;
  input(&dt);
  nsteps = 2.0 * M_PI * sqrt(MASSA / KAPPA) / dt;

  FILE *out_traj = fopen("traiettoria.dat", "w");
  if(out_traj == NULL) {
    printf("ERRORE NELL'APERTURA FILE\n");
    exit(0);
  }

  FILE *out_E = fopen("energia.dat", "w");
  if(out_E == NULL) {
    printf("ERRORE NELL'APERTURA FILE\n");
    exit(0);
  }

  for(i = 0; i < nsteps; i++) {
    updSemiEuler(&xSE, &vSE, dt);
    if(i % 10 == 0) {
      analytic(dt * i, x0, v0, &xA, &vA);
      eneSE = energy(xSE, vSE);
      eneA = energy(xA, vA);
      fprintf(out_traj, "%.5f %.6f %.6f\n", dt * i, xA, xSE);
      fprintf(out_E, "%.5f %.6f %.6f\n", dt * i, eneA, eneSE);
    }
  }

  fclose(out_traj);
  fclose(out_E);

  return 0;
}
