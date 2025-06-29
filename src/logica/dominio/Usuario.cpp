
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include <iostream>


Usuario::Usuario(string nick, string contrasenia, DTFecha * fechaNac) {
	this->nick = nick;
	this->contrasenia = contrasenia;
	this->fechaNac= fechaNac;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

std::string Usuario::getNickname() const {
	return nick;
}

std::string Usuario::getContrasenia() const {
	return contrasenia;
}

DTFecha* Usuario::getFechaNac() const {
	return fechaNac;
}