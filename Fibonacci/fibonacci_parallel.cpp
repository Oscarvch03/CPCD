#include <iostream>
#include <cstdio>
#include <omp.h>
using namespace std;

void t_fibonacci(int n, int &res){
    if(n <= 1){
        res = n;
    }
    else{
        int x, y;
        #pragma omp task shared(x)
        {
            // t_fibonacci(n-1, x);
            int l = n - 1;
            int id = omp_get_thread_num();
            // printf("thread %d is tasked with computing fib(%d)\n", id, l);
            t_fibonacci(l, x);
        }
        #pragma omp task shared(y)
        {
            t_fibonacci(n-2, y);
        }
        #pragma omp taskwait
        res = x + y;
    }
}

int fibonacci(int n){
    int res;
    #pragma omp parallel
    // tener en cuenta que puedo definir num_threads(#)
    #pragma omp single
    {
        t_fibonacci(n, res);
    }
    return res;
}

int main(){
    int num = 30;
    printf("Calculando Fibonacci de %d\n", num);
    double t_start = omp_get_wtime();
    cout << fibonacci(num) << endl;
    double t_stop = omp_get_wtime();

    printf("Time: %f\n",t_stop-t_start);

    return 0;
}
