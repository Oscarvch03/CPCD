// CALCULAR PI USANDO critical

#include <cstdio>
#include <cstdlib>
#include <omp.h>

double pi_calc(long N) {

  int Nthr = 4;
  int chunk = N / Nthr;

  double pi4 = 0;

  #pragma omp parallel num_threads(Nthr)
  {
    int id = omp_get_thread_num();
    int ini = id*chunk + 1;
    int fin = id < Nthr-1 ? ini+chunk-1 : N;
    printf("thread %d computing from %d to %d\n",id,ini,fin);

    double val, pi4_part;
    for(int i = ini; i <= fin; i++){
      val = (double(i) - 0.5) / N;
      pi4_part += 1. / (1+val*val);
    }

    #pragma omp critical
    {
        pi4 += pi4_part;
    }
  }

  return 4 * pi4 /  N;

}

int main(int argc, char** argv) {
  long N = atoi(argv[1]);

  double t_start = omp_get_wtime();
  double pi = pi_calc(N);
  double t_stop = omp_get_wtime();

  printf("Pi = %.12f\n",pi);
  printf("Time: %f\n",t_stop-t_start);

  return 0;
}
