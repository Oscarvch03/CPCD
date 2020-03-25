#include <iostream>
#include "generate_random.hpp"
using namespace std;

int main(int argc, char** argv) {
  long size = atoi(argv[1]);

  long* a = new long[size];

  unsigned seed = 123;
  generate_norepeat_vector(size, a, seed);

  write_vector(size, a);

  cout << "Vector Listo. " << endl;  

  return 0;
}
