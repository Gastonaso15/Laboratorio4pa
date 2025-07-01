
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

DTCliente::DTCliente(string nick, string pass, DTFecha * fecha, string ciudad, DTDireccion * direccion,set<DTCompra*> setCompras){
    this->nick= nick;
    this->pass= pass;
    this->fechaNac= fecha;
    this->ciudad= ciudad;
    this->direccion= direccion;
    this->setCompras= setCompras;
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
    : DTUsuario(nick, pass, fecha), ciudad(""), direccion(nullptr) {
}

string DTCliente::getTipo() const {
    return "Cliente";
}

string DTCliente::obtenerInfo() const {
    return "Nickname: " + nick + "\nFecha de Nacimiento: " + fechaNac->toString() + "\nCiudad: " + ciudad+ "\nDireccion: " + direccion->toString();
}