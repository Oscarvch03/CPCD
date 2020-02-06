
#include "matrix.hpp"
#include <iostream>
using namespace std;


int main(){

    int m = 3;
    int n = 3;
    // //
    // MatrixOne mat1(m, n);
    // // mat1.display();
    // for(int i = 0; i < 3; i++){
    //     mat1.set(i, i, 8);
    // }
    // mat1.set(0, 1, 9);
    // mat1.display();
    //
    // MatrixOne mat2 = mat1;
    // mat2.display();


    MatrixOne M1(m, n);
    MatrixOne M2(m, n);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            M1.set(i, j, 2);
            M2.set(i, j, 2);
        }

    }
    cout << "M1:" << endl;
    M1.display();
    cout << endl;
    cout << "M2:" << endl;
    M2.display();

    MatrixOne Res = M1 * M2;
    // cout << endl;
    cout << "Res:" << endl;
    Res.display();


    return 0;
}
