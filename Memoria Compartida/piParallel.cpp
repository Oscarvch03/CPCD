#include <cstdio>
#include <omp.h>
#include <cmath>

int main(){
    int Nthr = 4;
    double sum[Nthr];
    long N = 10000; // Si N es muy grande (mayor a 2mil millones) se inestabiliza el programa
    int chunk = N / Nthr;
    #pragma omp parallel num_threads(Nthr)
    {
        double val;
        double pi4 = 0.;
        int id = omp_get_thread_num();
        int ini = id * chunk;
        int fin = (id + 1) * chunk;
        if(id == Nthr - 1){
            fin = N;
        }
        for(int i = ini; i < fin; i++){
            val = (double(i) - 0.5) / N;
            pi4 += 1. / (1+ val * val);
        }
        sum[id] = pi4;
    }

    double pi4f = 0;
    for(int j = 0; j < Nthr; j++){
        pi4f += sum[j];
    }

    double PI = 4 * pi4f / N;
    // printf("PIorig = %.13f\n", M_PI);
    printf("PIcalc parallel = %.13f\n", PI);


    return 0;
}
