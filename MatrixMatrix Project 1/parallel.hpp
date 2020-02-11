#ifndef __PARALLEL_ONE_HPP
#define __PARALLEL_ONE_HPP

MatrixOne operator * (MatrixOne & M1, MatrixOne & M2);

void MxM_helper(MatrixOne & M1, MatrixOne & M2, MatrixOne & RES, int iniM1y, int finM1y);

#endif
