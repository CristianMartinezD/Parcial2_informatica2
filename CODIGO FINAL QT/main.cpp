#include "escalarimagen.h"

using namespace std;

int main()
{
    string rutaImagen = "../imagenes/";
    string nombre;
    cout<<"\nDe las imagenes que hay en la siguiente ruta, cual deseas usar(y no olvides poner su extencion)"<<endl;
    cout<<"\nDesktop/Universidad/INFORMATICA\Parcial #2/Parcial2/imagenes : "; cin>>nombre;
    rutaImagen.append(nombre);

    QImage imagen(rutaImagen.c_str()); //Este es un constructor para cargar la imagen.

    escalarimagen imagencita(imagen);

    cout<<"\n\tOPERACION EXITOSA\n"<<endl;

    return 0;
}
