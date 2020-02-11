
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


MatrixOne& MatrixOne::operator = (MatrixOne &M){
    int Mdimx = M.get_dimx();
    int Mdimy = M.get_dimy();
    // cout << "hbsdfh" << endl;
    array = new int[Mdimx * Mdimy];
    // MatrixOne aux(Mdimy, Mdimx);
    int cont = 0;
    for(int i = 0; i < Mdimy; i++){
        for(int j = 0; j < Mdimx; j++){
              int val = M.get(j, i);
              // cout << "val = " << val << endl;
              array[cont] = val;
              cont++;
              // printf("val = %d\n", val);

              // this -> set(j, i, val);
        }
    }

    return *this;
}


// MatrixOne& MatrixOne::operator * (MatrixOne &M){
//     int auxx = this -> get_dimx();
//     int auxy = M.get_dimy();
//     MatrixOne aux(auxx, auxy);
//     for(int i = 0; i < this -> get_dimy(); i++){
//         for(int j = 0; j < M.get_dimx(); j++){
//             int val = 0;
//             for(int k = 0; k < M.get_dimy(); k++){
//                 val += this -> get(i, k) * M.get(k, j);
//                 if(k + 1 == M.get_dimy()){
//                     aux.set(i, k, val);
//                 }
//             }
//
//         }
//     }
//     *this = aux;
//     return *this;
// }


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


MatrixOne operator * (MatrixOne &M1, MatrixOne &M2){
    int auxx = M1.get_dimx();
    int auxy = M2.get_dimy();
    MatrixOne aux(auxy, auxx);
    // int cont = 0;
    for(int i = 0; i <  M1.get_dimx(); i++){
        for(int j = 0; j < M2.get_dimy(); j++){
            int val = 0;
            for(int k = 0; k < M2.get_dimx(); k++){
                val += M1.get(i, k) * M2.get(k, j);
                if(k + 1 == M2.get_dimx()){
                    aux.set(i, j, val);
                }
            }

        }
    }
    cout << "Prueba" << endl;
    aux.display();
    return aux;
}
