#include "escalarimagen.h"



EscalarImagen::EscalarImagen(QImage ima)
{
    imagen = ima;
    numfilas = imagen.height();
    numcolumnas = imagen.width();
    fstream archivo;
    archivo.open("matriz.txt", ios::out);
    archivo<<"int MATRIZ[3][64] = {\n";
    archivo.close();
    for(int capa = 0; capa < 3; capa++) reducirmatrices(capa);
}




void EscalarImagen::reducirmatrices(int capa)
{
    cout<<"\n\nCOPIANDO MATRIZ DEL ROJO....\n"<<endl;
    for(int indx = 0; indx < numfilas; indx++){
        vector<int> A;
        for(int indy = 0; indy < numcolumnas; indy++){
            if(capa == 0) A.push_back(imagen.pixelColor(indy,indx).red());
            else if(capa == 1) A.push_back(imagen.pixelColor(indy,indx).green());
            else A.push_back(imagen.pixelColor(indy,indx).blue());
        }
        matrizrojo[indx] = A;
    }


    cout<<"\n\nREDUCIENDO FILAS DE LA MATRIZ DEL ROJO...."<<endl;
    map<int, vector<int>>::iterator iterador;
    int contador = 0;
    while(matrizrojo.size() >= 16){
    for(iterador = matrizrojo.begin(); iterador != matrizrojo.end(); iterador++){
        if(contador % 2 == 0){
            map<int, vector<int>>::iterator temporal = iterador;
            ++iterador;
            matrizrojo.erase(temporal);
        }

        contador++;

    }
    cout<<matrizrojo.size()<<endl;

    }

    cout<<"\n\nTERMINANDO DE REDUCIR ALGUNAS FILAS QUE NO PUDIERON SER REDUCIDAS....\n"<<endl;
    int centro;
    while(matrizrojo.size() > 8){
        matrizrojo.erase(iterador =  matrizrojo.begin());

        if(matrizrojo.size() > 8) matrizrojo.erase(--(iterador =  matrizrojo.end()));

        centro = matrizrojo.size() / 2;
        if(matrizrojo.size() > 8){
            for(iterador =  matrizrojo.begin(); iterador != matrizrojo.end(); iterador++){
                centro--;
                if(centro == 0){
                    iterador++;
                    matrizrojo.erase(iterador);
                }
            }
        }
    }

    cout<<"\n\nIMPRIMIENDO LAS 8 FILAS QUE QUEDARON:\n"<<endl;
    map<int, vector<int>>::iterator iterador2;
    for(iterador2 = matrizrojo.begin(); iterador2 != matrizrojo.end(); iterador2++){
        cout<<"{"<<endl;
        for(int i = 0; i < numcolumnas; i++){
            cout<<iterador2->second[i]<<" ";
        }
        cout<<"}"<<endl;
    }

    cout<<"\n\nCOPIANDO LAS 8 FILAS DEL ROJO EN UNA LISTA....\n"<<endl;
    iterador2 = matrizrojo.begin();
    list<vector<int>> MATRIZR;
    for(iterador2 = matrizrojo.begin(); iterador2 != matrizrojo.end(); iterador2++){
        vector<int> vect;
        for(int j = 0; j < iterador2->second.size(); j++){
            if(j % 2 == 0) vect.push_back(iterador2->second[j]);
        }
        MATRIZR.push_back(vect);
    }


    cout<<"\n\nREDUCIENDO EL NUMERO DE COLUMNAS QUE TIENE CADA UNA DE LAS 8 FILAS....\n"<<endl;
    while(MATRIZR.begin()->size() >= 16){
    list<vector<int>> auxiliar;
    for(auto it : MATRIZR){
        vector<int> vect;
        for(int j = 0; j < it.size(); j++){
            if(j % 2 != 0) vect.push_back(it[j]);
        }
        auxiliar.push_back(vect);
    }
    MATRIZR = auxiliar;

    }

    cout<<"\n\nTERMINANDO DE REDUCIR EL NUMERO DE COLUMNAS....\n"<<endl;
    list<vector<int>>::iterator iter = MATRIZR.begin();
    for(iter = MATRIZR.begin(); iter != MATRIZR.end(); iter++){
        while(iter->size() > 8){
            cout<<"entro:"<<endl;
            iter->erase(iter->begin());
            if(iter->size() > 8) iter->erase(iter->end()-1);
            centro = iter->size() / 2;
            if(iter->size() > 8) iter->erase(iter->begin() + centro);

        }
    }


    cout<<"IMPRIMIENDO LISTA:"<<endl;
    for(auto it : MATRIZR){
        for(int j = 0; j < it.size(); j++){
             cout<<it[j]<<" ";
        }
        cout<<endl;
    }


    fstream archivo;
    archivo.open("matriz.txt", ios::out | ios::in |ios::app);
    if(archivo.is_open()){
        cout<<"\nCONSTRUYENDO ARCHIVO.....\n";
        archivo<<"{";
        int i = 0;
        for(auto it : MATRIZR){
            for(int j = 0; j < 8; j++){
                if(i != 0 & i!= 64)archivo<<",";
                i++;
                archivo<<(it[j]);
             }
         }
        if(capa != 2) archivo<<"},\n";
        if(capa == 2) archivo<<"}\n};";
        archivo.close();
    }
}
