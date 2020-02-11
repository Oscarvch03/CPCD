
#include "matrix.hpp"

#include <iostream>
#include <cstdio>
#include <sys/time.h>

using namespace std;

const int DIMX = 50;
const int DIMY = 50;


double gettime(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


int main(int argc, char** argv){

    int size = atoi(argv[1]);

    MatrixOne M1(DIMY, size);
    MatrixOne M2(size, DIMX);
    M1.display();
    M2.display();

    double tstart = gettime();
    MatrixOne R = M1 * M2;
    double tstop = gettime();

    // R.display();
    printf("%d\n", R.get(0, 0));
    printf("Time: %f\n", tstop - tstart);

    return 0;


    // int m = 3;
    // int n = 3;
    // // //
    // // MatrixOne mat1(m, n);
    // // // mat1.display();
    // // for(int i = 0; i < 3; i++){
    // //     mat1.set(i, i, 8);
    // // }
    // // mat1.set(0, 1, 9);
    // // mat1.display();
    // //
    // // MatrixOne mat2 = mat1;
    // // mat2.display();
    //
    //
    // MatrixOne M1(m, n);
    // MatrixOne M2(m, n);
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         M1.set(i, j, 2);
    //         M2.set(i, j, 2);
    //     }
    //
    // }
    // cout << "M1:" << endl;
    // M1.display();
    // cout << endl;
    // cout << "M2:" << endl;
    // M2.display();
    //
    // MatrixOne Res = M1 * M2;
    // // cout << endl;
    // cout << "Res:" << endl;
    // Res.display();

}
