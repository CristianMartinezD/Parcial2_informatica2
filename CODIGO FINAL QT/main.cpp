#include <iostream>
#include <QImage>
#include <vector>
#include <list>
#include <map>
#include <fstream>


using namespace std;

int main()
{
    string rutaImagen = "../Parcial2/imagenes/colo.png";
    QImage imagen(rutaImagen.c_str()); //Este es un constructor para cargar la imagen.

    int cordX = 100;
    int cordY = 80;

    cout<<"Intencidad del rojo en el pixel seleccionado "<<imagen.pixelColor(cordX,cordY).red()<<endl;
    cout<<"Intencidad del rojo en el pixel seleccionado "<<imagen.pixelColor(cordX,cordY).green()<<endl;
    cout<<"Intencidad del rojo en el pixel seleccionado "<<imagen.pixelColor(cordX,cordY).blue()<<endl;

    int numfilas = imagen.height();
    int numcolumnas = imagen.width();

    map<int, vector<int>> matrizrojo;
    cout<<numcolumnas<<", "<<numfilas<<endl;

    for(int indx = 0; indx < numfilas; indx++){
        vector<int> A;
        for(int indy = 0; indy < numcolumnas; indy++){
           A.push_back(imagen.pixelColor(indy,indx).red());
        }
        matrizrojo[indx] = A;
    }

/*
cout<<"\n\nIMPRIMIENDO COPIA DE MATRIZ ORIGINAL:\n"<<endl;
    map<int, vector<int>>::iterator it;
    for(it = matrizrojo.begin(); it != matrizrojo.end(); it++){
        cout<<"{"<<endl;
        for(int i = 0; i < numcolumnas; i++){
            cout<<it->second[i]<<" ";
        }
        cout<<"}"<<endl;
    }

    cout<<"\n\nIMPRIMIENDO MATRIZ ORIGINAL:\n"<<endl;

    for(int indx = 0; indx < numfilas; indx++){
        cout<<"{"<<endl;
        for(int indy = 0; indy < numcolumnas; indy++){
           cout<<(imagen.pixelColor(indy,indx).red())<<" ";
        }
        cout<<"}"<<endl;
    }



///////////////////////////// PRUEBA.
    map<int, vector<int>> matrizrojo;
    vector<int> vector1 = {1,0,4,0,6,0,5,0,9,0,3,0,1,0,5,0};
    vector<int> vector2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector3 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int> vector4 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector5 = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    vector<int> vector6 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector7 = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    vector<int> vector8 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector9 = {1,0,4,0,6,0,5,0,9,0,3,0,1,0,5,0};
    vector<int> vector10 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector11 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int> vector12 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector13 = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    vector<int> vector14 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> vector15 = {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    vector<int> vector16 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    matrizrojo[0] = vector1;
    matrizrojo[1] = vector2;
    matrizrojo[2] = vector3;
    matrizrojo[3] = vector4;
    matrizrojo[4] = vector5;
    matrizrojo[5] = vector6;
    matrizrojo[6] = vector7;
    matrizrojo[7] = vector8;
    matrizrojo[8] = vector9;
    matrizrojo[9] = vector10;
    matrizrojo[10] = vector11;
    matrizrojo[11] = vector12;
    matrizrojo[12] = vector13;
    matrizrojo[13] = vector14;
    matrizrojo[14] = vector15;
    matrizrojo[15] = vector16;

    */

    map<int, vector<int>>::iterator iterador;
    int contador = 0;
    while(matrizrojo.size() >= 16){
    for(iterador = matrizrojo.begin(); iterador != matrizrojo.end(); iterador++){
        if(contador % 2 == 0){
            map<int, vector<int>>::iterator temporal = iterador;
            ++iterador;
            cout<<"Ha sido borrado"<<endl;
            matrizrojo.erase(temporal);
        }

        contador++;

    }
    cout<<matrizrojo.size()<<endl;

    }

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

    cout<<"\n\nIMPRIMIENDO LAS FILAS QUE QUEDARON:\n"<<endl;
    map<int, vector<int>>::iterator iterador2;
    for(iterador2 = matrizrojo.begin(); iterador2 != matrizrojo.end(); iterador2++){
        cout<<"{"<<endl;
        for(int i = 0; i < numcolumnas; i++){
            cout<<iterador2->second[i]<<" ";
        }
        cout<<"}"<<endl;
    }

    cout<<"\n\nCOPIANDO MATRIZ REDUCIDA:\n"<<endl;
    iterador2 = matrizrojo.begin();
    list<vector<int>> MATRIZR;
    for(iterador2 = matrizrojo.begin(); iterador2 != matrizrojo.end(); iterador2++){
        vector<int> vect;
        for(int j = 0; j < iterador2->second.size(); j++){
            if(j % 2 != 0) vect.push_back(iterador2->second[j]);
        }
        MATRIZR.push_back(vect);
    }


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

   cout<<"IMPRIMIENDO LISTA"<<endl;
    for(auto it : MATRIZR){
        for(int j = 0; j < it.size(); j++){
            //if(j % 2 == 0)MATRIZROJO[i][j] = -1;
             cout<<it[j]<<" ";
        }
        cout<<endl;
    }




 /*
        while(columnas >= 16){
            int i = 0;
            for(auto posicion = iterador2->second.begin(); posicion != iterador2->second.end(); posicion++){
                if(i % 2 == 0){
                    posicion+=2;
                    iterador2->second.erase(posicion-2);
                    cout<<"\n\nIMPRIMIENDO:\n"<<endl;
                }
                i++;
            }
            //columnas =(iterador2->second).size();
        }
    }


    cout<<"\n\nIMPRIMIENDO LA MATRIZ FINAL:\n"<<endl;
    iterador2 = matrizrojo.begin();
    for(iterador2 = matrizrojo.begin(); iterador2 != matrizrojo.end(); iterador2++){
        cout<<"{"<<endl;
        for(int i = 0; i < numcolumnas; i++){
            cout<<iterador2->second[i]<<" ";
        }
        cout<<"}"<<endl;
    }


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

    fstream archivo;
    archivo.open("matriz.txt", ios::out);
    if(archivo.is_open()){
        archivo<<"int MATRIZ[3][cantidad de leds de la matriz (8*8)] = {\n";

        archivo<<"{";
        for(int j = 0; j<8*8; j++){
           if(j != 0 & j!= 64)archivo<<",";
           archivo<<(capaR[j]);
        }
        archivo<<"},\n";

        archivo<<"{";
        for(int j = 0; j<8*8; j++){
           if(j != 0 & j!= 64)archivo<<",";
           archivo<<(capaV[j]);
        }
        archivo<<"},\n";


        archivo<<"{";
        for(int j = 0; j<8*8; j++){
           if(j != 0 & j!= 64)archivo<<",";
           archivo<<(capaA[j]);
        }
        archivo<<"}\n};";

        archivo.close();

    }


*/

    cout<<endl;
    return 0;
}
