#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 200
double diff[N];
double approx_log(double x, int T)
{
  double s=0.0;
  int t;
  for (t=0; t < T; t++)
    s += pow(-1,t)*pow(x,t+1)/(t+1);
  return s;
}

int main(void)
{
  double x;
  int i, ret;
  FILE *f;
  srand48(12345);
  for (i=0; i < N; i++)
    {
      do
        {
          x = 2.0*(drand48() - 0.5);
        }
      while (x==-1);
      diff[i] = fabs(approx_log(x, 4) - log(1.0+x));
    }

  f = fopen("diff.dat", "w");
  if (f==NULL)
    {
      printf("[ERRORE] non riesco ad aprire il file diff.dat\n");
      exit(EXIT_FAILURE);
    }
  for (i=0; i < N; i++)
    {
      ret=fprintf(f, "%d %.8f\n", i+1, diff[i]);
      if (ret < 0)
        {
          printf("[ERRORE] scrittura su disco fallita\n");
          exit(EXIT_FAILURE);
        }
    }

  fclose(f);
}
