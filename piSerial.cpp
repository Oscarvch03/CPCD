#include <cstdio>

double pi_calc(long N){
    double pi4 = 0.;
    double val;
    for(int i = 1; i <= N; i++){
        val = (double(i) - 0.5) / N;
        pi4 += 1. / (1+ val * val);
    }
    return 4 * pi4 / N;
}

int main(){
    double PI = pi_calc(10000); // Da igual al pi de cmath con 2mil millones
    printf("PIcalc serial = %.13f\n", PI);
}
