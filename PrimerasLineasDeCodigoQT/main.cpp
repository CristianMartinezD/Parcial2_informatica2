#include <iostream>
#include <QImage>
#include <vector>
#include <map>
#include <fstream>


using namespace std;

int main()
{
    string rutaImagen = "../Parcial2/imagenes/colo.png";
    QImage imagen(rutaImagen.c_str()); //Este es un constructor para cargar la imagen.

    int cordX = 100;
    int cordY = 80;

    cout<<"Intencidad del rojo en el pixel seleccionado"<<imagen.pixelColor(cordX,cordY).red()<<endl;
    cout<<"Intencidad del rojo en el pixel seleccionado"<<imagen.pixelColor(cordX,cordY).green()<<endl;
    cout<<"Intencidad del rojo en el pixel seleccionado"<<imagen.pixelColor(cordX,cordY).blue()<<endl;

    vector<int> capaR;
    vector<int> capaV;
    vector<int> capaA;

    QImage imagencita = imagen.scaled(QSize(8,8)); //Pude haber puesto solo scaled(8,8);
    for(int indx = 0; indx < imagencita.width(); indx++){
        cout<<"{";
        for(int indy = 0; indy < imagencita.height(); indy++){
            capaR.push_back(imagencita.pixelColor(indx,indy).red());
            cout<<imagencita.pixelColor(indx,indy).red()<<" "; //imprimiendo capa del rojo
        }
        cout<<"}";
    }

    cout<<endl;
    for(int indx = 0; indx < imagencita.width(); indx++){
        cout<<"{";
        for(int indy = 0; indy < imagencita.height(); indy++){
            capaV.push_back(imagencita.pixelColor(indx,indy).green());
            cout<<imagencita.pixelColor(indx,indy).green()<<" "; //imprimiendo capa del verde
        }
        cout<<"}";
    }


    cout<<endl;
    for(int indx = 0; indx < imagencita.width(); indx++){
        cout<<"{";
        for(int indy = 0; indy < imagencita.height(); indy++){
            capaA.push_back(imagencita.pixelColor(indx,indy).blue());
            cout<<imagencita.pixelColor(indx,indy).blue()<<" "; //imprimiendo capa del Azul
        }
        cout<<"}";
    }

    /*
     Una vez que ya tenga los tres vectores, los guardo en archivo de texto asi:
     int MATRIZ[3][cantidad de leds de la matriz (8*8)] = {
     {ROJO},
     {VERDE},
     {AZUL}
     };
     Y COPIO ESE CONTENIDO A TINKERCAD.
     Para ello hago lo siguiente:
     */

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



    //map<string,vector<int>> MATRIZ = {{"ROJO",capaR},{"VERDE",capaV},{"AZUL",capaA}};


    /*
    for(int indx = 0; indx < imagen.width(); indx++){
        for(int indy = 0; indy < imagen.height(); indy++){
            cout<<imagen.pixelColor(indx,indy).red()<<" "; //imprimiendo capa del rojo
        }
        cout<<endl;
    }


    for(int indx = 0; indx < imagen.width(); indx++){
        for(int indy = 0; indy < imagen.height(); indy++){
            cout<<imagen.pixelColor(indx,indy).green()<<" "; //imprimiendo capa del verde
        }
        cout<<endl;
    }


    for(int indx = 0; indx < imagen.width(); indx++){
        for(int indy = 0; indy < imagen.height(); indy++){
            cout<<imagen.pixelColor(indx,indy).blue()<<" "; //imprimiendo capa del Azul
        }
        cout<<endl;
    }

    */


    cout<<endl;
    return 0;
}
