#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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
                    return false;
                }
            }
            return true;
        }
        else{
            return false;
        }
        
    }
    else
    {
        return false;
    }
}

bool ValidarArchivo(char archivo[64]){
    string file = archivo;
    
    if(file.substr(file.length()-4)==".csv")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidarArgumentos(char f1[32],char f2[32], char archivo[64])
{
    if(ValidarFecha(f1)){
        if(ValidarFecha(f2)){
            if(ValidarArchivo(archivo)){
                return true;
            }
            else{
                cout <<"Tercer Argumento Invalido"<<endl;
                cout <<"El archivo debe tener extension .csv"<<endl;
                return false;
            }
        }
        else{
            cout <<"Segundo Argumento Invalido"<<endl;
            cout <<"Las fechas solo pueden contener numeros y guiones en formato yyyy-mm-dd"<<endl;
            return false;
        }
    }
    else
    {
        
        cout <<"Primer Argumento Invalido"<<endl;
        cout <<"Las fechas solo pueden contener numeros y guiones en formato yyyy-mm-dd"<<endl;
        return false;
    }
}
    