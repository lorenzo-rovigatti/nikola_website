#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000
double diff[N];
double approx_log(double x, int T)
{
  double s=0.0;
  int t;
  for (t=0; t < T; t++)
    s += pow(-1.0,t)*pow(x,t+1)/(t+1);
  return s;
}
double media(double *d)
{
  int i;
  double s=0.0;
  for (i=0; i < N; i++)
    {
      s += d[i];
    } 
  return s/N;
}
int main(void)
{
  double x, m;
  int t, i, ret;
  FILE *f;
  srand48(0);
  f = fopen("logerr.dat", "w");
  if (f==NULL)
    {
      printf("[ERRORE] non riesco ad aprire il file diff.dat\n");
      exit(EXIT_FAILURE);
    }
  for (t=4; t < 100; t++)
    {
      for (i=0; i < N; i++)
        {
          do
            {
              x = 2.0*(drand48() - 0.5);
            }
          while (x==-1);
          diff[i] = fabs(approx_log(x, t) - log(1.0+x));
        }
      m=media(diff);
      ret=fprintf(f, "%d %.8f\n", t, m);
      if (ret < 0)
        {
          printf("[ERRORE] scrittura su disco fallita\n");
          exit(EXIT_FAILURE);
        }
      
    }
  fclose(f);
}
