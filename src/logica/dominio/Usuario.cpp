/*
 * Usuario.cpp
 *
 *  Created on: 8 may 2024
 *      Author: gabriel
 */

#include "Usuario.h"
#include <iostream>

#include "../../DTs/DTFecha.h"

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