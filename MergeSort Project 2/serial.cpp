#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <omp.h>
#include <fstream>
#include <string>
using namespace std;

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
    // cout << "bye" << endl;
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


void MERGESORT(vector<long> &v, long ini, long fin, vector<long> &tmp){
    int mid = (fin + ini) / 2;
    // cout << "mid = " << mid << endl;
    if(ini < mid){
        if(fin - ini > 100){
            // cout << "hola" << endl;
            MERGESORT(v, ini, mid, tmp);
            // cout << "hola2" << endl;
            MERGESORT(v, mid, fin, tmp);
            MERGE(v, ini, fin, tmp);
        }
        else{
            BubbleSort(v, ini, fin);
            // tmp = v;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////

int main(){

    // vector<int> v1 = {3, 5, 2, 7, 4};
    vector<int> v1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> tmp1(v1.size(), 0);
    // cout << "Vector Original: " << endl;
    // display_vector(v1);
    // display_vector(tmp1);

    vector<long> v2 = read_dat();
    vector<long> tmp2(v2.size(), 0);
    // cout << "v2:" << endl;
    // display_vector(v2);
    // cout << endl;
    // cout << v2.size() << endl;

    double t_start = omp_get_wtime();
    MERGESORT(v2, 0, v2.size(), tmp2);
    double t_stop = omp_get_wtime();

    cout << endl;
    cout << "Verificacion: " << endl;
    cout << tmp2[0] << " ";
    cout << tmp2[tmp2.size()/4] << " ";
    cout << tmp2[tmp2.size()/2] << " ";
    cout << tmp2[3*tmp2.size()/4] << " ";
    cout << tmp2[tmp2.size()-1] << endl;
    cout << endl;

    // cout << "Vector Ordenado: " << endl;
    // display_vector(v2);

    // cout << endl;
    printf("Time Serial: %f\n",t_stop-t_start);

    return 0;
}
