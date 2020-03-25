#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <omp.h>
#include <fstream>
#include <string>
#include <functional>
using namespace std;


bool verifOrd(vector<long> &v){
    for(long i = 0; i < long(v.size()) - 1; i++){
        if(v[i] > v[i + 1]){
            return 0;
        }
    }
    return 1;
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


// BUBBLESORT
void BubbleSort(vector<long> &vec, long ini, long fin){
    for(long i = ini; i < fin; i++){
        for(long j = ini; j < fin-1; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}


void MERGE(vector<long> &v, long ini, long fin, vector<long> &tmp){
    int mid = (fin + ini) / 2;
    int p1 = ini;
    int p2 = mid;
    int pt = ini;

    while(p1 < mid && p2 < fin){
        if(v[p1] < v[p2]){
            tmp[pt] = v[p1];
            pt++;
            p1++;
        }
        else{
            tmp[pt] = v[p2];
            pt++;
            p2++;
        }
    }

    while(p1 < mid){
        tmp[pt] = v[p1];
        pt++;
        p1++;
    }

    while(p2 < fin){
        tmp[pt] = v[p2];
        pt++;
        p2++;
    }

    for(int i = ini; i < fin; i++){
        v[i] = tmp[i];
    }
}


void MERGESORT_helper(vector<long> &v, long ini, long fin, vector<long> &tmp){
    if(fin-ini > 100){
        long mid = (fin + ini) / 2;
        #pragma omp task shared(v, tmp)
        {
            MERGESORT_helper(ref(v), ini, mid, ref(tmp));
        }
        #pragma omp task shared(v, tmp)
        {
            MERGESORT_helper(ref(v), mid, fin, ref(tmp));
        }
        #pragma omp taskwait
        {
            MERGE(ref(v), ini, fin, ref(tmp));
        }
    }
    else{
        BubbleSort(ref(v), ini, fin);
    }
}


void MERGESORT(vector<long> &v, long ini, long fin, vector<long> &tmp){
    #pragma omp parallel
    {
        #pragma omp single
        {
            MERGESORT_helper(ref(v), 0, v.size(), ref(tmp));
        }
    }
}


////////////////////////////////////////////////////////////////////////////////


int main(){

    cout << endl;
    vector<long> v = read_dat();
    cout << "Tamanho del Vector: " << v.size() << endl;
    vector<long> tmp(v.size(), 0);

    // display_vector(v);

    cout << "Ordenando Vector... " << endl;
    cout << endl;

    double t_start;
    double t_stop;
    if(v.size() <= 100){
        BubbleSort(v, 0, v.size());
        tmp = v;
    }
    else{
        t_start = omp_get_wtime();
        MERGESORT(v, 0, v.size(), tmp);
        t_stop = omp_get_wtime();
    }

    // display_vector(tmp);

    bool Ord = verifOrd(tmp);
    if(Ord == 1){
        cout << "El Vector ha sido Ordenado. " << endl;
    }
    else{
        cout << "El vector NO ha sido Ordenado. " << endl;
    }

    printf("Time Parallel: %.8f\n",t_stop-t_start);
    cout << endl;

    return 0;
}
