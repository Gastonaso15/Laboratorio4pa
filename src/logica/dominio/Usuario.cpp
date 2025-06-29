
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include "Comentario.h"
#include <iostream>


Usuario::Usuario(string nick, string pass, DTFecha * fechaNac) {
	this->nick = nick;
	this->pass = pass;
	this->fechaNac= fechaNac;
}

Usuario::~Usuario() {

}

string Usuario::getNick() {
	return this->nick;
}

void Usuario::asociarComentarioUsuario(Comentario *com) {
	this->comentarios[com->getId()] = com;
}
