#ifndef __MATRIX_ONE_HPP
#define __MATRIX_ONE_HPP

// class MatrixOne;

// MatrixOne operator * (MatrixOne & M1, MatrixOne & M2); // Serial

// MatrixOne operator * (MatrixOne & M1, MatrixOne & M2); // Paralelo
// void MxM_helper(MatrixOne & M1, MatrixOne & M2, MatrixOne & RES, int iniM1y, int finM1y); // Helper Paralelo

class MatrixOne{

private:
    int *array;
    int dimx;
    int dimy;

public:
    MatrixOne(int m, int n);
    ~MatrixOne();

    int get_dimx(){
        return dimx;
    }

    int get_dimy(){
        return dimy;
    }

    int get(int x, int y){
        return array[x * dimx + y];
    }

    void set(int x, int y, int val){
        array[x * dimx + y] = val;
    }

    MatrixOne& operator = (MatrixOne &M);

    void display();

};

#endif
