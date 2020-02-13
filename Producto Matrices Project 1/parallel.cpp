// MULTIPLICAR MATRICES PARALELO

#include "matrix.hpp"
#include "parallel.hpp"

#include <iostream>
#include <thread>

using namespace std;

MatrixOne operator * (MatrixOne & M1, MatrixOne & M2){
    int chunk = M1.get_dimy() / 8;
    int resx = M1.get_dimy();
    int resy = M2.get_dimx();
    // cout << resx << " --- " << resy << endl;
    MatrixOne RES(resx, resy);
    thread thr1(MxM_helper, ref(M1), ref(M2), ref(RES), 0, chunk+1);
    thread thr2(MxM_helper, ref(M1), ref(M2), ref(RES), chunk+1, 2*chunk+1);
    thread thr3(MxM_helper, ref(M1), ref(M2), ref(RES), 2*chunk+1, 3*chunk+1);
    thread thr4(MxM_helper, ref(M1), ref(M2), ref(RES), 3*chunk+1, 4*chunk+1);
    thread thr5(MxM_helper, ref(M1), ref(M2), ref(RES), 4*chunk+1, 5*chunk+1);
    thread thr6(MxM_helper, ref(M1), ref(M2), ref(RES), 5*chunk+1, 6*chunk+1);
    thread thr7(MxM_helper, ref(M1), ref(M2), ref(RES), 6*chunk+1, 7*chunk+1);
    MxM_helper(M1, M2, RES, 7*chunk+1, M1.get_dimy());
    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    thr6.join();
    thr7.join();

    return RES;
}


void MxM_helper(MatrixOne & M1, MatrixOne & M2, MatrixOne & RES, int iniM1y, int finM1y){
    for(int i = iniM1y; i <  finM1y; i++){
        for(int j = 0; j < M2.get_dimx(); j++){
            int val = 0;
            for(int k = 0; k < M2.get_dimy(); k++){
                val += M1.get(i, k) * M2.get(k, j);
                // cont++;
                // cout << "cont = " << cont << endl;
                if(k + 1 == M2.get_dimy()){
                    RES.set(i, j, val);
                }
            }
        }
    }
}
