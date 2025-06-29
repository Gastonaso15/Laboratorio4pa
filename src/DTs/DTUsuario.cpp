
#include "DTUsuario.h"
#include <iostream>
using namespace std;

DTUsuario::DTUsuario() {

}

DTUsuario::~DTUsuario() {

}

DTUsuario::DTUsuario(string nick, string pass, DTFecha *fechaNac) {
    this->nick = nick;
    this->pass= pass;
    this->fechaNac = fechaNac;
}

string DTUsuario::getNick() const{
    return this->nick;
}

string DTUsuario::getPass() {
    return this->pass;
}

DTFecha DTUsuario::getFechaNac() {
    return *(this->fechaNac);
}


