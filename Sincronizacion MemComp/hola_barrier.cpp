#include <cstdio>
#include <omp.h>


void foo1(int id) {
  printf("Hola Antes %d\n", id);
}

void foo2(int id) {
  printf("Hola Despues %d\n", id);
}


int main() {
  int Nthr = 8;

  #pragma omp parallel num_threads(Nthr)
  {
    int id = omp_get_thread_num();

    foo1(id);

    #pragma omp barrier

    foo2(id);

  }

  return 0;
}
