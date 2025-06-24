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

DTCliente::DTCliente(string nick, string pass, DTFecha * fecha, string ciudad, DTDireccion * direccion){
    this->nick= nick;
    this->pass= pass;
    this->fechaNac= fecha;
    this->ciudad= ciudad;
    this->direccion= direccion;
}

string DTCliente::getCiudad() {
    return this->ciudad;
}

DTDireccion DTCliente::getDireccion() {
    return *(this->direccion);
}
void DTCliente::asociarProd() {

}

string DTCliente::getTipo() const {
    return "Cliente";
}

string DTCliente::obtenerInfo() const {
    return "Nickname: " + nick + "\nFecha de Nacimiento: " + fechaNac->toString() + "\nCiudad: " + ciudad+ "\nDireccion: " + direccion->toString();
}