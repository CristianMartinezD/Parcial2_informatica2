#include "escalarimagen.h"


escalarimagen::escalarimagen(QImage ima)
{
    imagen = ima;
    numfilas = imagen.height();
    numcolumnas = imagen.width();
    fstream archivo;
    archivo.open("matriz.txt", ios::out);
    archivo<<"byte MATRIZ[3][256] = {\n";
    archivo.close();
    for(int capa = 0; capa < 3; capa++) reducirmatrices(capa);

}




void escalarimagen::reducirmatrices(int capa)
{
    vector<vector<int>> matriz;
    for(int indx = 0; indx < numfilas; indx++){
        vector<int> A;
        for(int indy = 0; indy < numcolumnas; indy++){
           if(capa == 0) A.push_back(imagen.pixelColor(indy,indx).red());
           else if(capa == 1) A.push_back(imagen.pixelColor(indy,indx).green());
           else A.push_back(imagen.pixelColor(indy,indx).blue());
        }
        matriz.push_back(A);
    }


    int MATRIZDELEDS[16][16];

    int suma = 0, promedio = 0, cantidad = 0;  //DEFINICION DE ALGUNAS VARIABLES.
    int j = 0, n = 1;
    int conta = 0;
    int b = 1, c = 2;



    for(int a = 0; a < 15; a++){
    conta = 0, n = 1, j = 0, suma = 0, promedio = 0, cantidad = 0;

    while(conta < 16){

    for(int i = (numfilas/16)*b; i < (numfilas/16)*c; i++){
        for(j = j+0; j < (numcolumnas/16)*n; j++){
            suma += matriz[i][j];
            cantidad++;
        }
    }
    promedio = suma / cantidad;
    MATRIZDELEDS[a][n-1] = promedio;
    n++;
    conta++;
    suma = 0, promedio = 0, cantidad = 0;
    }

    b++;
    c++;

    }


    for(int k = 0; k < 16; k++) MATRIZDELEDS[15][k] = MATRIZDELEDS[14][k];


    fstream archivo;
    archivo.open("matriz.txt", ios::out | ios::in |ios::app);
    if(archivo.is_open()){
        archivo<<"{";
        int i = 0;
        for(auto it : MATRIZDELEDS){
            for(int j = 0; j < 16; j++){
                if(i != 0 & i!= 256)archivo<<",";
                i++;
                if(it[j] == 0) archivo<<(10);
                if(it[j] != 0 & it[j] != 255) archivo<<(it[j]);
                if(it[j] == 255) archivo<<(250);
             }
         }
        if(capa != 2) archivo<<"},\n";
        if(capa == 2) archivo<<"}\n};";
        archivo.close();
    }

}
