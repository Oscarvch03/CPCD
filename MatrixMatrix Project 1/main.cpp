
#include "matrix.cpp"


int main(){

    int m = 10;
    int n = 10;

    MatrixOne mat1(m, n);
    mat1.display();
    for(int i = 0; i < 10; i++){
        mat1.set(i, i, 8);
    }
    mat1.set(0, 1, 9);
    mat1.display();

    MatrixOne mat2(m, n);
    // mat2.display();
    mat2 = mat1;
    mat2.display();

    return 0;
}
