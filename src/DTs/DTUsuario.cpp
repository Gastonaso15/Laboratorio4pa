//
// Created by marti on 12/6/2025.
//

#include "DTUsuario.h"
#include <iostream>
using namespace std;

DTUsuario::DTUsuario() {

}

DTUsuario::~DTUsuario() {

}

DTUsuario::DTUsuario(string nick, string contrasenia, DTFecha *fechaNac) {
    this->nick = nick;
    this->contrasenia= contrasenia;
    this->fechaNac = fechaNac;
}

string DTUsuario::getNick() {
    return this->nick;
}

string DTUsuario::getContrasenia() {
    return this->contrasenia;
}

DTFecha DTUsuario::getFechaNac() {
    return *(this->fechaNac);
}


