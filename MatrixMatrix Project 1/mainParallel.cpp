#include "matrix.hpp"
#include "parallel.hpp"

#include <iostream>
#include <cstdio>
#include <sys/time.h>
#include <fstream>

using namespace std;

const int DIMX = 1000;
const int DIMY = 1000;


double gettime(){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


int main(int argc, char** argv){

    int size = atoi(argv[1]);

    MatrixOne M1(DIMY, size);
    MatrixOne M2(size, DIMX);
    // M1.display();
    // M2.display();

    // double tstart = gettime();
    // MatrixOne R = M1 * M2;
    // double tstop = gettime();

    ofstream myfile;
    myfile.open("parallel.txt");
    myfile << "Tiempos Parallel:\n";
    myfile << "t\t" << "t²\n";

    for(int i = 0; i < 100; i++){

        double tstart = gettime();
        MatrixOne R = M1 * M2;
        double tstop = gettime();

        double time = tstop - tstart;
        double time2 = time * time;

        myfile << time << "\t" << time2 << "\n";

    }


    // R.display();
    // printf("%d\n", R.get(0, 0));
    // printf("Time Parallel: %f\n", tstop - tstart);

    return 0;

}
