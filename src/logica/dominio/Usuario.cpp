#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include "Comentario.h"

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
}

set<DTComentario*> Usuario::getComentarios() {
	set<DTComentario*> dtComentarios;
	for (auto const& [id, comentarioPtr] : this->comentarios) {
		dtComentarios.insert(comentarioPtr->retornarDTComentario());
	}
	return dtComentarios;
}

Comentario* Usuario::obtenerComentario(int id) {
	auto it = comentarios.find(id);
	if (it != comentarios.end())
		return it->second;
	return nullptr;
}

void Usuario::eliminarComentario(int id) {
	comentarios.erase(id);
}