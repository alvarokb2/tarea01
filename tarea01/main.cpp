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
#include <validar.cpp>

using namespace std;

int main(int argc, char **argv) {
    system("cls");
    cout << "- Tarea01 -\n\n -Contador de argumentos: "<< argc << endl;
    
    if(argc==2)
    {
        if(strcmp(*(argv+1),"-v")==0)
        {
            cout << "\nIntegrantes del Grupo";
        }
        else
        {
            cout << "\nError: Si ingresa 1 argumento debe ser -v";
        }
    }
    else if(argc==5)
    {
        if(strcmp(*(argv+1),"-g")==0)
        {
            cout << "\n Exito";
            
            ifstream flujo(*(argv + 4));

            ValidarArgumentos(*(argv +2));
            char c=flujo.get();
            while(flujo.good())
            {
                cout << c;
                c = flujo.get();
            }
            flujo.close();
            
        }
        else
        {
            cout <<"\nError: wefefewfef";
        }
    }
    else
    {
        cout << "\nError: Debe ingresar parametros\n  - prueba [-v | -g <yyyy-mm-dd> <yyyy-mm-dd> <archivo>.csv ]";
    }
    cout << "\n\n- End -\n";
    
    return 0;
}
