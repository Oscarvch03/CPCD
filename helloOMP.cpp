#include <cstdio>
#include <omp.h>

int main(){
    #pragma omp parallel
    {
        // int Nthr = omp_get_num_threads();
        int id = omp_get_thread_num();

        printf("Hello( %d) ", id);
        printf("World( %d)\n", id);
    }
    return 0;
}
