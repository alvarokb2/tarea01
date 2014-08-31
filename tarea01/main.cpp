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

int main(int argc, char **argv) {
    if (*(argv + 1) != NULL) {
        if (strcmp(*(argv + 1), "-g") == 0) // si el primer argumento es -g
        {
            if (*(argv + 2) != NULL
                    && *(argv + 3) != NULL
                    && *(argv + 4) != NULL
                    && *(argv + 5) == NULL) //verifica que se pasen 4 argumentos
            {
                // Pipe:ingrese esta linea
                std::ifstream flujo;
                
                ifstream flujo(*(argv + 4));

                flujo.close();

            } else //si el primer parametro es -g pero no tiene 4 parametros
            {
                cout << "Error al ingresar parametros" << endl;
                cout << "el formato que debe utilizar es" << endl;
                cout << "-g yyyy-mm-dd yyyy-mm-dd archivo.csv" << endl;
            }

        } else if (strcmp(*(argv + 1), "-v") == 0) // si el primer argumento es -v
        {
            if (*(argv + 2) != NULL) //si tiene mas de 1 argumento
            {
                cout << "Para mostrar los integrantes" << endl;
                cout << "y fecha de compilacion debe ingresar" << endl;
                cout << "el parametro -v como unico parametro" << endl;
            } else {
                cout << "Integrantes del Grupo";
            }
        }
    } else //al no pasarle parametros el programa no hace nada
    {
        return 0;
    }
}
