//
// Created by marti on 12/6/2025.
//

#include "DTDireccion.h"
#include <iostream>
using namespace std;

DTDireccion::DTDireccion() {

}

DTDireccion::~DTDireccion() {

}

DTDireccion::DTDireccion(string calle, int nroPuerta) {
    this->calle = calle;
    this->nroPuerta = nroPuerta;
}

string DTDireccion::getCalle() {
    return this->calle;
}

int DTDireccion::getNroPuerta() {
    return this->nroPuerta;
}

string DTDireccion::toString() const {
    return calle + " " +to_string(nroPuerta);
}
