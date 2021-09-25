#include <iostream>
#include <QImage>
#include <vector>
//#include <list>
#include <map>
//#include <fstream>
#include <escalarimagen.h>


using namespace std;

int main()
{
    string rutaImagen = "../Parcial2/imagenes/usa.png";
    QImage imagen(rutaImagen.c_str()); //Este es un constructor para cargar la imagen.

    EscalarImagen imagencita(imagen);

/*
    int numfilas = imagen.height();
    int numcolumnas = imagen.width();

    map<int, vector<int>> matrizrojo;
    cout<<numcolumnas<<", "<<numfilas<<endl;

    cout<<"\n\nCOPIANDO MATRIZ DEL ROJO....\n"<<endl;
    for(int indx = 0; indx < numfilas; indx++){
        vector<int> A;
        for(int indy = 0; indy < numcolumnas; indy++){
           A.push_back(imagen.pixelColor(indy,indx).red());
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
            if(j % 2 != 0) vect.push_back(iterador2->second[j]);
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

*/


 /*


///////////////////////////////////////////////////////
    cout<<"\n\nIMPRIMIENDO MATRIZ ESCALADA:\n"<<endl;
    vector<int> capaR;
    vector<int> capaV;
    vector<int> capaA;
    QImage imagencita = imagen.scaled(QSize(8,8)); //Pude haber puesto solo scaled(8,8);
    for(int indx = 0; indx < imagencita.height(); indx++){
        cout<<"{";
        for(int indy = 0; indy < imagencita.width(); indy++){
            capaR.push_back(imagencita.pixelColor(indy,indx).red());
            cout<<imagencita.pixelColor(indy,indx).red()<<" "; //imprimiendo capa del rojo
        }
        cout<<"}";
    }

    cout<<endl;
    for(int indx = 0; indx < imagencita.height(); indx++){
        cout<<"{";
        for(int indy = 0; indy < imagencita.width(); indy++){
            capaV.push_back(imagencita.pixelColor(indy,indx).green());
            cout<<imagencita.pixelColor(indy,indx).green()<<" "; //imprimiendo capa del verde
        }
        cout<<"}";
    }


    cout<<endl;
    for(int indx = 0; indx < imagencita.height(); indx++){
        cout<<"{";
        for(int indy = 0; indy < imagencita.width(); indy++){
            capaA.push_back(imagencita.pixelColor(indy,indx).blue());
            cout<<imagencita.pixelColor(indy,indx).blue()<<" "; //imprimiendo capa del Azul
        }
        cout<<"}";
    }

    /////
     Una vez que ya tenga los tres vectores, los guardo en archivo de texto asi:
     int MATRIZ[3][cantidad de leds de la matriz (8*8)] = {
     {ROJO},
     {VERDE},
     {AZUL}
     };
     Y COPIO ESE CONTENIDO A TINKERCAD.
     Para ello hago lo siguiente:
    /////


*/
//    fstream archivo;
//    archivo.open("matriz.txt", ios::out);
//    if(archivo.is_open()){
//        archivo<<"int MATRIZ[3][cantidad de leds de la matriz (8*8)] = {\n";

//        archivo<<"{";
//        for(int j = 0; j<8*8; j++){
//           if(j != 0 & j!= 64)archivo<<",";
//           archivo<<(capaR[j]);
//        }
//        archivo<<"},\n";

//        archivo<<"{";
//        for(int j = 0; j<8*8; j++){
//           if(j != 0 & j!= 64)archivo<<",";
//           archivo<<(capaV[j]);
//        }
//        archivo<<"},\n";


//        archivo<<"{";
//        for(int j = 0; j<8*8; j++){
//           if(j != 0 & j!= 64)archivo<<",";
//           archivo<<(capaA[j]);
//        }
//        archivo<<"}\n};";

//        archivo.close();

//    }




    cout<<endl;
    return 0;
}
