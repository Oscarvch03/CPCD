#include <cstdio>
#include <omp.h>

int main(){
    printf("Master thread running serial region. \n");
    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();

        if(id > 0){
            printf("Thread %d running parallel region. \n", id);
        }
        else{
            printf("Master thread running parallel region. \n");
        }
    }
    printf("Master thread running serial region.\n");
    return 0;
}
