//
// Created by marti on 12/6/2025.
//

#include "DTCliente.h"
#include <iostream>
using namespace std;

DTCliente::DTCliente() {
    this->ciudad="";
    this->direccion=NULL;
}

DTCliente::~DTCliente() {

}

DTCliente::DTCliente(string nick, string contrasenia, DTFecha * fecha, string ciudad, DTDireccion * direccion) {
    this->ciudad=ciudad;
    this->direccion=direccion;
}

string DTCliente::getCiudad() {
    return this->ciudad;
}

DTDireccion DTCliente::getDireccion() {
    return *(this->direccion);
}