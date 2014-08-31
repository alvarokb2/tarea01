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

//prueba
using namespace std;

bool ValidarFecha(char fechaInicio[32]) {
    string fechai = fechaInicio;
    string aux;
    if (fechai.length() == 10) {
        if (fechai.substr(4, 1) == "-" && fechai.substr(7, 1) == "-") {
            aux = fechai.substr(0, 4) + fechai.substr(5, 2) + fechai.substr(8, 2);
            fechai = aux.substr(0, 8);
            for (int i = 0; i < fechai.length(); i++) {
                if (!isdigit(fechai[i])) {
                    cout << "  - Las fechas solo pueden contener numeros y guiones en formato yyyy-mm-dd " << endl;
                    return false;
                }
            }
            cout << "  - fecha ingresada correctamente" << endl;
            return true;
        }
        else{
            cout << "  - Las fechas solo pueden contener numeros y guiones en formato yyyy-mm-dd " << endl;
            return false;
        }
    }
    else
    {
        cout << "  - Las fechas solo pueden contener numeros y guiones en formato yyyy-mm-dd " << endl;
        return false;
    }
}

bool ValidarArchivo(char archivo[64]){
    string file = archivo;
    
    if(file.substr(file.length()-4)==".csv")
    {
        cout << "  - formato correcto" << endl;
        return true;
    }
    else
    {
        cout << "  - formato incorrecto" << endl;
        return false;
    }
}

bool ValidarArgumentos(char f1[32],char f2[32], char archivo[64])
{
    cout << endl << "Validar argumentos :" << endl;
    if(ValidarFecha(f1) && ValidarFecha(f2) && ValidarArchivo(archivo)){
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char **argv) {
    system("cls");
    cout << "- Tarea01 -\n\n -Contador de argumentos: " << argc << endl;

    if (argc == 2) {
        if (strcmp(*(argv + 1), "-v") == 0) {
            cout << "Integrantes del Grupo" << endl;
        } else {
            cout << "Error: Si ingresa 1 argumento debe ser -v" << endl;
        }
    } else if (argc == 5) {
        if (strcmp(*(argv + 1), "-g") == 0) {

            ValidarArgumentos(*(argv + 2),*(argv + 3),*(argv + 4));
                
            ifstream flujo(*(argv + 4));
            string str;
            int count=0;
            char c = flujo.get();
            while (flujo.good()) {
                if(c=='\n')count++;
                str.append(&c);
                c = flujo.get();
            }
            cout << endl << "Archivo: " << *(argv+4) << endl;
            cout << "  - Size  : " << str.size() << endl;
            cout << "  - Lines : " << count << endl;
            flujo.close();

        } else {
            cout << "Error: Debe ingresar parametros\n  - prueba [-v | -g <yyyy-mm-dd> <yyyy-mm-dd> <archivo>.csv ]" << endl;
        }
    } else {
        cout << "Error: Debe ingresar parametros\n  - prueba [-v | -g <yyyy-mm-dd> <yyyy-mm-dd> <archivo>.csv ]" << endl;
    }
    cout << "\n- End -\n";

    return 0;
}
