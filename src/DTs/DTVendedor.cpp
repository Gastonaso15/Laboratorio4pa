//
// Created by marti on 12/6/2025.
//

#include "DTVendedor.h"
#include <iostream>
using namespace std;

DTVendedor::DTVendedor(){
    this->RUT="";
}

DTVendedor::~DTVendedor() {

}

DTVendedor::DTVendedor(string nick, string contrasenia, DTFecha * fecha, string RUT) {
    this->RUT=RUT;
}

string DTVendedor::getRUT() {
    return this->RUT;
}