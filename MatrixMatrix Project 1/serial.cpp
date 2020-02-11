// MULTIPLICAR MATRICES SERIAL

#include "matrix.hpp"
#include "serial.hpp"

#include <iostream>

using namespace std;

MatrixOne operator * (MatrixOne & M1, MatrixOne & M2){
    int auxx = M1.get_dimy();
    int auxy = M2.get_dimx();
    // cout << auxx << " --- " << auxy << endl;
    MatrixOne aux(auxx, auxy);
    int cont = 0;
    for(int i = 0; i <  M1.get_dimy(); i++){
        for(int j = 0; j < M2.get_dimx(); j++){
            int val = 0;
            for(int k = 0; k < M2.get_dimy(); k++){
                val += M1.get(i, k) * M2.get(k, j);
                cont++;
                // cout << "cont = " << cont << endl;
                if(k + 1 == M2.get_dimy()){
                    aux.set(i, j, val);
                }
            }
        }
    }
    // cout << "Prueba" << endl;
    // aux.display();
    return aux;
}
