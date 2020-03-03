#include <iostream>
#include <cstdio>
#include <omp.h>
using namespace std;

int main(){

    int var1 = 3;
    int var2 = 6;

    #pragma omp parallel default(shared), private(var1)
    // se comporta igual con o sin default(shared)
    {
        int id = omp_get_thread_num();
        var1 = id + 10;
        if(id % 2 == 0){
            #pragma omp atomic
            var2 += id;
            printf("valor de var1 en el thread %d es %d\n", id, var1);
            printf("valor de var2 en el thread %d es %d\n", id, var2);
        }
    }

    return 0;
}
