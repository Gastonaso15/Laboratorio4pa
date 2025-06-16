//
// Created by marti on 12/6/2025.
//

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

string DTVendedor::getRUT() {
    return this->rut;
}