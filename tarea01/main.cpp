/* 
 * File:   main.cpp
 * Author: Alvaro
 *
 * Created on 31 de agosto de 2014, 17:08
 */


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

int main(int argc, char **argv) {
    system("cls");
    cout << "- Tarea01 -\n\n -Contador de argumentos: " << argc << endl;

    if (argc == 2) {
        if (strcmp(*(argv + 1), "-v") == 0) {
            cout << "\nIntegrantes del Grupo";
        } else {
            cout << "\nError: Si ingresa 1 argumento debe ser -v";
        }
    } else if (argc == 5) {
        if (strcmp(*(argv + 1), "-g") == 0) {
            cout << "\n Exito";

            ifstream flujo(*(argv + 4));

            ValidarArgumentos(*(argv + 2),*(argv+3));
            char c = flujo.get();
            while (flujo.good()) {
                cout << c;
                c = flujo.get();
            }
            flujo.close();

        } else {
            cout << "\nError: wefefewfef";
        }
    } else {
        cout << "\nError: Debe ingresar parametros\n  - prueba [-v | -g <yyyy-mm-dd> <yyyy-mm-dd> <archivo>.csv ]";
    }
    cout << "\n\n- End -\n";

    return 0;
}
