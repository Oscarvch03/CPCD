#include <iostream>
#include <cstdio>
#include <omp.h>
using namespace std;

int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    else{
        int x = fibonacci(n-1);
        int y = fibonacci(n-2);
        return(x + y);
    }
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
