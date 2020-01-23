#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sys/time.h>

#include <thread>

using namespace std;

double gettime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

void initialize(int* v1, int* v2, int size) {
  for(int i = 0; i < size; ++i){
    v1[i] = 1;
    v2[i] = 2;
  }
}

// void vector_add(const int* v1, const int* v2,
// 	  int* res, int size) {
//   for(int i = 0; i < size; ++i)
//     res[i] = v1[i] + v2[i];
// }

void V_sum_section(const int* x, const int* y, int* res, int a, int b){
    for(int i = a; i <= b; i++){
        res[i] = x[i] + y[i];
    }
    printf("Listo\n");
}

void V_sum(const int* x, const int* y, int* res, int n){
    int chunk = n / 4;
    thread thr1(V_sum_section, x, y, res, chunk + 1, 2 * chunk);
    thread thr2(V_sum_section, x, y, res, 2 * chunk + 1, 3 * chunk);
    thread thr3(V_sum_section, x, y, res, 3 * chunk + 1, 4 * chunk - 1);
    V_sum_section(x, y, res, 0, chunk);

    thr1.join();
    thr2.join();
    thr3.join();
}

int main(int argc, char** argv) {

  double st_start = gettime();

  long size = atoi(argv[1]);
  int* v1 = new int[size];
  int* v2 = new int[size];
  int* res = new int[size];

  double st_stop = gettime();


  double ct_start = gettime();
  thread thr4(initialize, v1, v2, size);
  // initialize(v1,v2,size);
  // vector_add(v1,v2,res,size);
  V_sum(v1, v2, res, size);
  thr4.join();
  double ct_stop = gettime();

  //Check answer
  long sum = 0;
  for(int i = 0; i < size; ++i)
    sum += res[i];
  printf("Res: %ld\n",sum);

  printf("Secuential time: %f\n",st_stop-st_start);
  printf("Concurrent time: %f\n",ct_stop-ct_start);
  printf("Total time: %f\n",st_stop-st_start+ct_stop-ct_start);

  delete[] v1;
  delete[] v2;
  delete[] res;

  return 0;
}

// TERMINAR
