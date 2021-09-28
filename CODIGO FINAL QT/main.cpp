#include "escalarimagen.h"

using namespace std;

int main()
{
    string rutaImagen = "../imagenes/granada.jpg";
    QImage imagen(rutaImagen.c_str()); //Este es un constructor para cargar la imagen.

    escalarimagen imagencita(imagen);

    cout<<"\n\tPERACION EXITOSA\n"<<endl;

    return 0;
}
