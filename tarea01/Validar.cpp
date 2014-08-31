#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;


bool ValidarArgumentos(char fechaInicio[32], char fechaTermino[32]) {
    string fechai = fechaInicio;
    string fechat = fechaTermino;
    string aux;
    if (fechai.length() == 10 && fechai.substr(4, 1) == "-" && fechai.substr(7, 1) == "-") {
        aux = fechai.substr(0, 4) + fechai.substr(5, 2) + fechai.substr(8, 2);
        fechai = aux.substr(0, 8);
        cout << fechai;

        for (int i = 0; i < fechai.length(); i++) {
            if (!isdigit(fechai[i])) {

                cout << "fecha 1 incorrecta";
                return false;
            }
        }
    } else if (fechat.length() == 10 && fechat.substr(4, 1) == "-" && fechai.substr(7, 1) == "-") {
        aux = fechat.substr(0, 4) + fechat.substr(5, 2) + fechat.substr(8, 2);
        fechat = aux.substr(0, 8);
        cout << fechat;

        for (int i = 0; i < fechat.length(); i++) {
            if (!isdigit(fechat[i])) {

                cout << "fecha 2 incorrecta";
                return false;
            }
        }

    }
}