#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define NPTS 5000
#define NTB 2
#define NTBEG 128
#define NUMNT 13

double ptheta(double theta, double lambda);
void trova_massimo(double lambda, double *Pmax, double *thmax);
double theta_prob(double lambda, double Pmax);
void salva_energia(double Uarr[NUMNT + 1]);

int main() {
  int i, n, nt;
  double pmax, theta, lambda, thmax;
  double Uarr[NUMNT + 1] = {0};
  srand48(42);
  
  do {
    printf("Inserisci il valore di lambda (in [0.1, 10]):");
    scanf("%lf", &lambda);
  }
  while(lambda < 0.1 || lambda > 10.0);
  
  trova_massimo(lambda, &pmax, &thmax);
  printf("Pmax = %.4f, thetamax = %.4f\n", pmax, thmax);
  for(n = 0; n <= NUMNT; n++) {
    nt = NTBEG * pow(NTB, n);
    for(i = 0; i < nt; i++) {
      theta = theta_prob(lambda, pmax);
      Uarr[n] += -cos(theta); 
    }
    Uarr[n] /= nt;
  }
  salva_energia(Uarr);
  return 0;
}

double ptheta(double theta, double lambda) {
  double W = lambda / (exp(lambda) - exp(-lambda));
  return sin(theta) * exp(lambda * cos(theta)) * W;
}

void trova_massimo(double lambda, double *Pmax, double *thmax) {
  int i;
  *Pmax = 0;
  double dth = M_PI / NPTS; 
  for(i = 0; i < NPTS; i++) {
    double theta = dth * i;
    double Ptheta = ptheta(theta, lambda);
    if(Ptheta > *Pmax || i == 0) {
      *Pmax = Ptheta;
      *thmax = theta;
    }
  }
}

double theta_prob(double lambda, double Pmax) {
  double x, y;
  do {
      x = drand48() * M_PI; 
      y = drand48() * Pmax;
  } while (y > ptheta(x, lambda));
  
  return x;
}

void salva_energia(double Uarr[NUMNT + 1]) {
  int n, nt;
  FILE *f = fopen("energia.dat", "w");
  if(f == NULL) {
    printf("Errore nell'apertura del file\n");
    exit(1);
  }
  for(n = 0; n <= NUMNT; n++) {
    nt = NTBEG * pow(NTB,n);
    fprintf(f, "%d %.4f\n", nt, Uarr[n]);
  }
  fclose(f);
}
