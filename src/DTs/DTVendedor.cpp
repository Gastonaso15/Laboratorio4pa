
#include "DTVendedor.h"
#include "DTFecha.h"
#include <iostream>
using namespace std;

DTVendedor::DTVendedor(){
}

DTVendedor::~DTVendedor() {

}

DTVendedor::DTVendedor(string nick, string pass, DTFecha * fechaNac, string rut) {
    this->nick=nick;
    this->pass=pass;
    this->rut=rut;
    this->fechaNac=fechaNac;
}

DTVendedor::DTVendedor(string nick, string pass, DTFecha * fechaNac, string rut,set<DTPromocion*> setPromos,set<DTProducto*> setProductos) {
    this->nick=nick;
    this->pass=pass;
    this->rut=rut;
    this->fechaNac=fechaNac;
    this->setPromos=setPromos;
    this->setProductos=setProductos;
}

string DTVendedor::getRUT() {
    return this->rut;
}

string DTVendedor::getTipo() const {
    return "Vendedor";
}

string DTVendedor::obtenerInfo() const {
    return "Nickname: " + nick + "\nFecha de Nacimiento: " + fechaNac->toString() + "\nRUT: " + rut;
}