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


void ValidarArgumentos(char fechaInicio[32])
{
    string fechai = fechaInicio;
    string aux;
    if(fechai.length()==10 && fechai.substr(4,1)=="-" && fechai.substr(7,1)=="-")
    {
        aux = fechai.substr(0,4)+fechai.substr(5,2)+fechai.substr(8,2);
        fechai = aux.substr(0,8 );
        cout <<fechai;
        
        for(int i=0;i<fechai.length();i++)
        {
            while(isdigit(fechai[i]))
            {
                    
            }
        }
    }
}

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
