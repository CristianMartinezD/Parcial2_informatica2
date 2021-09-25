#ifndef ESCALARIMAGEN_H
#define ESCALARIMAGEN_H

#include <iostream>
#include <QImage>
#include <map>
#include <vector>
#include <fstream>



using namespace std;
class EscalarImagen
{
private:
    QImage imagen;
    int numfilas;
    int numcolumnas;
    map<int, vector<int>> matrizrojo;
    map<int, vector<int>> matrizverde;
    map<int, vector<int>> matrizazul;
public:
    EscalarImagen(QImage ima);
    void reducirmatrices(int capa);
};

#endif // ESCALARIMAGEN_H
