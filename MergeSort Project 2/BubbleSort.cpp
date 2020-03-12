#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <omp.h>
#include <fstream>
#include <string>
using namespace std;

// BUBBLESORT
void BubbleSort(vector<long> &vec){
    for(long i = 0; i < long(vec.size()); i++){
        for(long j = 0; j < long(vec.size()-1); j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

vector<long> read_dat(){
  string line;
  vector<long> aux;
  ifstream myfile("vector.dat");
  if(myfile.is_open()){
      while(getline(myfile, line)){
              string str;
              for(long i = 0; i < long(line.length()); i++){
                  if(line[i] == ' ' || i == line.length()){
                      long num = stol(str.c_str());
                      aux.push_back(num);
                      str = "";
                  }
                  else{
                      str += line[i];
                  }
              }
      }
      myfile.close();
  }
  else cout << "Unable to open file. " << endl;
  return aux;
}

void display_vector(vector<long> v){
    cout << "[ ";
    for(long i = 0; i < long(v.size()); i++){
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}


int main(){

    vector<long> v1 = read_dat();
    display_vector(v1);
    BubbleSort(v1);
    display_vector(v1);

    return 0;
}
