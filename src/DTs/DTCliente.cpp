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

string DTCliente::getCiudad() const {
    return this->ciudad;
}
string DTCliente::getNickname() const {
    return this->nick;
}
DTDireccion DTCliente::getDireccion() const {
    return *(this->direccion);
}
void DTCliente::asociarProd() {

}
DTCliente::DTCliente(string nick, string pass, DTFecha * fecha)
    : DTUsuario(nick, pass, fecha), ciudad(""), direccion(nullptr) { // Inicializa los miembros adicionales si los tiene
    // Puedes dejar 'ciudad' como "" y 'direccion' como nullptr
    // o usar valores por defecto si tienen sentido.
}
string DTCliente::getTipo() const {
    return "Cliente";
}

string DTCliente::obtenerInfo() const {
    return "Nickname: " + nick + "\nFecha de Nacimiento: " + fechaNac->toString() + "\nCiudad: " + ciudad+ "\nDireccion: " + direccion->toString();
}