
#include "matrix.hpp"

#include <iostream>
using namespace std;

// Constructor

MatrixOne::MatrixOne(int m, int n){
    dimx = n;
    dimy = m;
    array = new int[dimx * dimy];
    for(int i = 0; i < (dimx * dimy); i++){
        array[i] = 1;
    }
}


MatrixOne::~MatrixOne(){
    delete[] array;
}


MatrixOne& MatrixOne::operator=(MatrixOne &M){
    int Mdimx = M.get_dimx();
    int Mdimy = M.get_dimy();
    // MatrixOne aux(Mdimy, Mdimx);
    for(int i = 0; i < Mdimy; i++){
        for(int j = 0; j < Mdimx; j++){
              int val = M.get(j, i);
              // cout << "val = " << val << endl;
              this -> set(j, i, val);
        }
    }

    return *this;
}


void MatrixOne::display(){
    cout << "[" << endl;
    for(int i = 0; i < dimx * dimy; i++){
        cout << " " << array[i];
        if((i+1) % dimx == 0){
            cout << "\n";
        }
    }
    cout << "]" << endl;
}
