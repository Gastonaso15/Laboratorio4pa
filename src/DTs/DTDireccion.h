
#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
using namespace std;

class DTDireccion {
public:
    string calle;
    int nroPuerta;
    //--------------------------------------------------------------------------------------------------------------------
    DTDireccion();
    DTDireccion(string calle, int nroPuerta);
    ~DTDireccion();

    int getNroPuerta();

    string getCalle();
    string toString() const;
};



#endif //DTDIRECCION_H
