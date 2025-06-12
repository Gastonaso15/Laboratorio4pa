//
// Created by marti on 12/6/2025.
//

#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
using namespace std;

class DTDireccion {
private:
    string calle;
    int nroPuerta;
public:
    DTDireccion();
    ~DTDireccion();
    DTDireccion(string calle, int nroPuerta);
    string getCalle();
    int getNroPuerta();
};



#endif //DTDIRECCION_H
