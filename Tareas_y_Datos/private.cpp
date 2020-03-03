#include <iostream>
#include <cstdio>
#include <omp.h>

int main(){

    int var = 5;
    #pragma omp parallel private(var)
    {
        int id = omp_get_thread_num();
        printf("thread %d has var = %d\n", id, var);
    }

    return 0;
}
