#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <cstdio>
#include <sys/time.h>

#include "generate_v3.hpp"

using namespace std;

double gettime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}


void count3s_thread(const vector<int> &vec, int a, int b, int &cont){
    for(int i = a; i <= b; i++){
        if (vec[i] == 3){
            cont++;
        }
    }
}


int generate_threads(const vector<int> &vec, int size){
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    std::vector<int> v;
    int chunk = size / 8;
    count3s_thread(vec, 0, chunk, count1);
    thread thr1(count3s_thread, ref(vec), chunk+1, 2*chunk, ref(count2));
    thread thr2(count3s_thread, ref(vec), 2*chunk+1, 3*chunk, ref(count3));
    thread thr3(count3s_thread, ref(vec), 3*chunk+1, 4*chunk, ref(count4));
    thread thr4(count3s_thread, ref(vec), 4*chunk+1, 5*chunk, ref(count5));
    thread thr5(count3s_thread, ref(vec), 5*chunk+1, 6*chunk, ref(count6));
    thread thr6(count3s_thread, ref(vec), 6*chunk+1, 7*chunk, ref(count7));
    thread thr7(count3s_thread, ref(vec), 7*chunk+1, 8*chunk-1, ref(count8));
    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    thr5.join();
    thr6.join();
    thr7.join();
    return count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8;
}

int count3s(const vector<int> &vec, int size){
    int count = generate_threads(vec, size);
    return count;
}


int main(int argc, char** argv) {
  int v_size = atoi(argv[1]);

  vector<int> vec;
  int n3 = generate_vector(v_size, vec);
  cout << "There are " << n3 << " 3s in the vector.\n";

  double tstart = gettime();
  int n = count3s(vec, v_size);
  double tstop = gettime();

  cout << "Time: " << tstop-tstart << endl;
  cout << "Number of 3s counted: " << n << endl;

  return 0;
}
