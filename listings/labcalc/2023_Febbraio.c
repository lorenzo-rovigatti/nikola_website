#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define BITS 8

void somma(int* A, int* B, int* ApB) {
	int i;
	int S, riporto = 0;

	for(i = 0; i < BITS; i++) {
		S = A[i] + B[i] + riporto;
		if (S > 1) {
			riporto = 1;
			S = S - 2;
        }
		else {
			riporto = 0;
        }
		ApB[i] = S; 
    }
}

void genera_numero(int N[BITS]) {
	int i;
	N[BITS - 1] = 0;
	for(i = 0; i < BITS - 1; i++) {
		N[i] = drand48() > 0.5 ? 1:0;
    }
}

int converti_numero(int *N) {
	int S = 0, i;
	for(i = 0; i < BITS; i++) {
		S += ((int)pow(2,i)) * N[i];
    }
	return S;
}

void inserimento(int *nsum) {
	int fine, ret;
	do {
		fine = 1;
		printf("Immetti il numero di somme da effettuare: ");
		ret = scanf("%d", nsum);
		if(*nsum < 1 || ret == 0) {
			fine = 0;
		}
    }
	while(!fine);
}

int main(void) {
  int i, sum[BITS], nsum;
  int A[BITS] = {0}, B[BITS] = {0};
  int numA, numB, hist[255] = {0};
  srand48(time(NULL));
  
  FILE *f = fopen("frequenze.dat", "w");
  if(f == NULL) {
      printf("errore nell'apertura del file\n");
      exit(1);
  }
  inserimento(&nsum);
  for(i = 0; i < nsum; i++) {
      genera_numero(A);
      genera_numero(B);
      somma(A, B, sum);
      //numA = converti_numero(A);
      //numB = converti_numero(B);
      int ApB = converti_numero(sum);
      //printf("numA=%d numB=%d somma=%d\n", numA, numB, ApB);
      hist[ApB]++;
  }
  
  for(i = 0; i < 255; i++) {
      fprintf(f, "%d %.5f\n", i, hist[i] / (double)nsum);
  }
  fclose(f);
  return 0;
}
