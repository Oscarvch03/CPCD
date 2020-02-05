#include <iostream>
#include <cstdio>
#include <sys/time.h>
#include <thread>

using namespace std;

double gettime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


void displayMatriz(int * matrix, int dimx, int dimy){
  cout << "[" << endl;
  for(int i = 0; i < (dimx * dimy); i++){
      cout << " " << matrix[i];
      if((i+1) % dimx == 0){
          cout << "\n";
      }
  }
  cout << "]" << endl;
}


void displayVector(int * vec, int dimy){
  cout << "[";
  for(int i = 0; i < (dimy); i++){
      cout << " " << vec[i];
  }
  cout << " ] " << endl;
}


void initializeM(int * matrix, int dimx, int dimy){
    for(int i = 0; i < (dimx*dimy); i++){
        matrix[i] = 2;
    }
}


void initializeV(int * vector, int dimy){
    for(int i = 0; i < dimy; i++){
        vector[i] = 2;
    }
}


void matrixVectorParalelHelper(const int * matrix, const int * vector, int dimx, int iniy, int finy, int * res){
    for(int i = iniy; i < finy; i++){
        int cont = 0;
        // printf("inix = %d, finx = %d\n", iniy, finy);
        // printf("iniy = %d, finy = %d\n", iniy, finy);
        for(int j = 0; j < dimx; j++){
            cont += matrix[i * dimx + j] * vector[j];
            // printf("(%d, %d)\n", i, j);
        }
        // printf("cont = %d\n", cont);
        res[i] = cont;
  }
}


void matrixVectorParalel(const int * matrix, const int * vector, int dimx, int dimy, int * res){
    int chunk1 = dimy / 8;
    // printf("chunk1 = %d\n", chunk1);
    // int chunk2 = dimy / 8;
    // printf("dimx = %d, dimy = %d\n", dimx, dimy);
    thread thr1(matrixVectorParalelHelper, matrix, vector, dimx, chunk1, 2 * chunk1, res);
    thread thr2(matrixVectorParalelHelper, matrix, vector, dimx, 2 * chunk1, 3 * chunk1, res);
    thread thr3(matrixVectorParalelHelper, matrix, vector, dimx, 3 * chunk1, 4 * chunk1, res);
    thread thr4(matrixVectorParalelHelper, matrix, vector, dimx, 4 * chunk1, 5 * chunk1, res);
    thread thr5(matrixVectorParalelHelper, matrix, vector, dimx, 5 * chunk1, 6 * chunk1, res);
    thread thr6(matrixVectorParalelHelper, matrix, vector, dimx, 6 * chunk1, 7 * chunk1, res);
    thread thr7(matrixVectorParalelHelper, matrix, vector, dimx, 7 * chunk1, 8 * chunk1, res);
    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    thr6.join();
    thr7.join();
    matrixVectorParalelHelper(matrix, vector, dimx, 0, chunk1, res);


}


int main(){

    int dimx = 10000;
    int dimy = 100000;

    int * mat = new int[dimx * dimy];
    int * vec = new int[dimy];
    int * res = new int[dimy];

    double tstart = gettime();

    thread thr8(initializeM, mat, dimx, dimy);
    thread thr9(initializeV, vec, dimy);
    thr8.join();
    thr9.join();

    matrixVectorParalel(mat, vec, dimx, dimy, res);

    // displayMatriz(mat, dimx, dimy);
    // cout << endl;
    // displayVector(vec, dimy);
    // cout << endl;
    // cout << "Res: " << endl;
    // displayVector(res, dimy);

    double tstop = gettime();

    cout << endl;
    cout << "Time Parallel: " << tstop-tstart << endl;

    delete[] mat;
    delete[] vec;
    delete[] res;
    return 0;
}
