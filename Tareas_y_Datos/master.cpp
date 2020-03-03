// VARIABLES DE CONTROL
// export OMP_NUM_THREADS=#
//  


#include <iostream>
#include <cstdio>
#include <omp.h>

void foo1(int id){
    printf("Hello from thread %d\n", id);
}

void foo2(int id){
    printf("Hello from master thread (%d)\n", id);
}

void foo3(int id){
    printf("Hello again from thread %d\n", id);
}


int main(){
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        foo1(id);
        #pragma omp master
        {
            foo2(id);
        }
        #pragma omp barrier
        foo3(id);
    }

    return 0;
}
