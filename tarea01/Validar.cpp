#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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
