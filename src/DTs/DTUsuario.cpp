//
// Created by marti on 12/6/2025.
//

#include "DTUsuario.h"

DTUsuario::DTUsuario() {

}

DTUsuario::~DTUsuario() {

}

DTUsuario::DTUsuario(string nick, string contrasenia, DTFECHA *fechaNac) {
    this->nick = nick;
    this->contrasenia= contrasenia;
    this->fechaNac = fechaNac;
}

string DTUsuario::getNick()const {
    return this->nick;
}

string DTUsuario::getContrasenia()const {
    return this->contrasenia;
}

DTFecha DTUsuario::getFechaNac()const {
    return this->fechaNac;
}


