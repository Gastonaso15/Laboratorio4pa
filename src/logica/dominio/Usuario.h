#ifndef LOGICA_USUARIO_H_
#define LOGICA_USUARIO_H_
#include "../DTs/DTFecha.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTComentario.h"
#include <map>
#include <iostream>
#include <set>
using namespace std;

class Comentario;

class Usuario {
protected:
	string nick;
	string contrasenia;
	DTFecha * fechaNac;

	map<int,Comentario*> comentarios;
public:
	Usuario();
	Usuario(string nick, string contrasenia, DTFecha * fechaNac);
	virtual ~Usuario();

	virtual DTUsuario* retornarDTUsuario()const=0;

	void asociarComentarioUsuario(Comentario * com);
	void eliminarComentario(int id);

	string getNick();
	string getNickname() const;
	string getContrasenia() const;

	DTFecha* getFechaNac() const;
	Comentario* obtenerComentario(int id);

	set<DTComentario*> getComentarios();
};


#endif
