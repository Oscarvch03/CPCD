#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){

    ////////////////////////////////////////////////////////////////////////////
    // Leo el archivo serial.txt y calculo la suma de los tiempos
    // y de los tiempos al cuadrado

    double timeS = 0;
    double timeS2 = 0;

    string line;
    ifstream myfile("serial.txt");
    if(myfile.is_open()){
        vector<double> aux;
        while(getline(myfile, line)){
            if(isdigit(line[0])){
                string str;
                for(size_t i = 0; i < line.length() + 1; i++){
                    if(line[i] == '\t' || i == line.length()){
                        double num = atof(str.c_str());
                        aux.push_back(num);
                        str = "";
                    }
                    else{
                        str += line[i];
                    }
                }
                timeS += aux[0];
                timeS2 += aux[1];
                aux = {};
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file. " << endl;

    cout << "timeS = " << timeS << endl;
    cout << "timeS2 = " << timeS2 << endl;


    ////////////////////////////////////////////////////////////////////////////
    // Calculo la media de los tiempos y de los tiempos al cuadrado (serial)

    double mtS = timeS / 100;
    double mtS2 = timeS2 / 100;

    cout << "mtS = " << mtS << endl;
    cout << "mtS2 = " << mtS2 << endl;


    ////////////////////////////////////////////////////////////////////////////
    // Leo el archivo parallel.txt y calculo la suma de los tiempos
    // y de los tiempos al cuadrado

    double timeP = 0;
    double timeP2 = 0;

    string line2;
    ifstream myfile2("parallel.txt");
    if(myfile2.is_open()){
        vector<double> aux;
        while(getline(myfile2, line2)){
            if(isdigit(line2[0])){
                string str;
                for(size_t i = 0; i < line2.length() + 1; i++){
                    if(line2[i] == '\t' || i == line2.length()){
                        double num = atof(str.c_str());
                        aux.push_back(num);
                        str = "";
                    }
                    else{
                        str += line2[i];
                    }
                }
                timeP += aux[0];
                timeP2 += aux[1];
                aux = {};
            }
        }
        myfile2.close();
    }
    else cout << "Unable to open file. " << endl;

    cout << endl;
    cout << "timeP = " << timeP << endl;
    cout << "timeP2 = " << timeP2 << endl;


    ////////////////////////////////////////////////////////////////////////////
    // Calculo la media de los tiempos y de los tiempos al cuadrado (parallel)

    double mtP = timeP / 100;
    double mtP2 = timeP2 / 100;

    cout << "mtP = " << mtP << endl;
    cout << "mtP2 = " << mtP2 << endl;


    ////////////////////////////////////////////////////////////////////////////
    // Calculo el SpeedUp promedio & el SpeedUp promedio
    // para los tiempos al cuadrado

    double SpU = mtS / mtP;
    double SpU2 = mtS2 / mtP2;

    cout << endl;
    cout << "SpU = " << SpU << endl;
    cout << "SpU2 = " << SpU2 << endl;


    ////////////////////////////////////////////////////////////////////////////
    // Calculo la Desviacion Estandar del SpeedUp

    double DE = sqrt(SpU2 - (SpU*SpU));
    cout << endl;
    cout << "DE = " << DE << endl;


    return 0;

}
