#ifndef ESCALARIMAGEN_H
#define ESCALARIMAGEN_H

#include <iostream>
#include <QImage>
#include <vector>
#include <fstream>

using namespace std;


class escalarimagen
{
private:
    QImage imagen;
    int numfilas;
    int numcolumnas;
public:
    escalarimagen(QImage ima);
    void reducirmatrices(int capa);
};

#endif // ESCALARIMAGEN_H
