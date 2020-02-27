//Norma de Frobenius de una matriz
//Código Parallel For Static

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <omp.h>


int frobenius(int* A, int m, int n) {
  int norm = 0;
  #pragma omp parallel
  {
      int aux = 0;
      #pragma omp for schedule(runtime)
          for(int i = 0; i < m; ++i){
              for(int j = 0; j < n; ++j){
                  aux += A[i*n+j]*A[i*n+j];
              }
          }

      #pragma omp atomic
          norm += aux;
  }
  // return sqrt(norm);
  return norm;
}


int main(int argc, char** argv) {
  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  int* A = new int[m*n];

  for(int i = 0; i < m; ++i){
    for(int j = 0; j < n; ++j)
      A[i*n+j] = 1;
  }

  double t_start = omp_get_wtime();
  int norm = frobenius(A, m, n);
  double t_stop = omp_get_wtime();

  printf("norm: %d\n",norm);
  printf("Time: %f\n",t_stop-t_start);

  delete[] A;

  return 0;
}
