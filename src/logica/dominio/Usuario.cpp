
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include <iostream>


Usuario::Usuario(string nick, string pass, DTFecha * fechaNac) {
	this->nick = nick;
	this->pass = pass;
	this->fechaNac= fechaNac;
}

Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

string Usuario::getNick() {
	return this->nick;
}
