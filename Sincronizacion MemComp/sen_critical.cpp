#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include <cmath>

int main(int argc, char** argv) {
  int n = atoi(argv[1]);
  int array[n];
  for(int i = 0; i < n; i++){
      array[i] = i;
  }

  int Nthr = 8;
  float sum_sin = 0;
  int chunk = n / Nthr;

  #pragma omp parallel num_threads(Nthr)
  {
    int id = omp_get_thread_num();
    int ini = id * chunk + 1;
    int fin = id < Nthr - 1 ? ini + chunk - 1 : n;
    printf("thread %d computing from %d to %d\n",id,ini,fin);

    float cont1 = 0;
    for(int i = ini; i < fin; i++){
      cont1 += sin(array[i]);
    }

    #pragma omp critical
    {
        sum_sin += cont1;
    }
  }
  printf("Sum_sin = %f\n", sum_sin);

  // Serial
  int m = atoi(argv[1]);
  float cont = 0;
  for(int i = 0; i < m; i++){
      cont += sin(i);
  }
  printf("Cont Serial = %f\n", cont);

  // REVISAR PORQUE ESTA REMAL

  return 0;
}
