#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void display_vector(vector<int> v){
    cout << "[ ";
    for(unsigned i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "]" << endl;
}

void MERGE(vector<int> &v, int ini, int fin, vector<int> &tmp){
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


void MERGESORT(vector<int> &v, int ini, int fin, vector<int> &tmp){
    int mid = (fin + ini) / 2;
    // cout << "mid = " << mid << endl;
    if(ini < mid){
        // cout << "hola" << endl;
        MERGESORT(v, ini, mid, tmp);
        // cout << "hola2" << endl;
        MERGESORT(v, mid, fin, tmp);
        MERGE(v, ini, fin, tmp);
    }
}


////////////////////////////////////////////////////////////////////////////////

int main(){

    // vector<int> v1 = {3, 5, 2, 7, 4};
    vector<int> v1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> tmp1(v1.size(), 0);
    cout << "Vector Original: " << endl;
    display_vector(v1);
    // display_vector(tmp1);
    MERGESORT(v1, 0, v1.size(), tmp1);
    cout << "Vector Ordenado: " << endl;
    display_vector(v1);

    return 0;
}
