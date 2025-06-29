
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include "Comentario.h"
#include <iostream>


Usuario::Usuario(string nick, string contrasenia, DTFecha * fechaNac) {
	this->nick = nick;
	this->contrasenia = contrasenia;
	this->fechaNac= fechaNac;
}

Usuario::~Usuario() {

}

std::string Usuario::getNickname() const {
	return nick;
}

std::string Usuario::getContrasenia() const {
	return contrasenia;
}

void Usuario::asociarComentarioUsuario(Comentario *com) {
	this->comentarios[com->getId()] = com;
}

DTFecha* Usuario::getFechaNac() const {
	return fechaNac;
