#include "matrix.hpp"

#include <iostream>
using namespace std;

// Constructor

MatrixOne::MatrixOne(int m, int n){
    dimx = m;
    dimy = n;
    array = new int[dimx * dimy];
    for(int i = 0; i < (dimx * dimy)){
        array[i] = 1;
    }
}


MatrixOne::~MatrixOne(){
    delete[] array;
}


// MatrixOne MatrixOne::&operator=(MatrixOne &M){
//
// }


void MatrixOne::display(){
    cout << "[";
    for(int i = 0; i < (dimx * dimy); i++){
        cout << " " << array[i];
        if((i+1) % dimx == 0){
            cout << "\n ";
        }
    }
}
