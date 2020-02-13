#include <iostream>
#include <cstdio>
#include <sys/time.h>

using namespace std;

double gettime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


void matrixVectorSerial(const int * matrix, const int * vector, int dimx, int dimy, int * res){
    for(int i = 0; i < dimy; i++){
        int cont = 0;
        for(int j = 0; j < dimx; j++){
            cont += matrix[i * dimx + j] * vector[j];
        }
        res[i] = cont;
    }
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


int main(){

    int dimx = 10000;
    int dimy = 100000;

    int * mat = new int[dimx * dimy];
    int * vec = new int[dimy];
    int * res = new int[dimy];

    double tstart = gettime();

    for(int i = 0; i < (dimx*dimy); i++){
        mat[i] = 2;
    }

    for(int i = 0; i < dimy; i++){
        vec[i] = 2;
    }

    // displayMatriz(mat, dimx, dimy);
    // cout << endl;
    // displayVector(vec, dimy);
    matrixVectorSerial(mat, vec, dimx, dimy, res);
    // cout << endl;
    // cout << "Res: " << endl;
    // displayVector(res, dimy);

    double tstop = gettime();

    cout << endl;
    cout << "Time Serial: " << tstop-tstart << endl;


    delete[] mat;
    delete[] vec;
    delete[] res;
    return 0;
}
