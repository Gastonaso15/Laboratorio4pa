#ifndef LOGICA_USUARIO_H_
#define LOGICA_USUARIO_H_
#include "../DTs/DTFecha.h"
#include "../DTs/DTUsuario.h"
#include <map>
#include <iostream>
using namespace std;

class Comentario;

class Usuario {
protected:
	string nick;
	string pass;
	DTFecha * fechaNac;
	map<int,Comentario*> comentarios;
public:
	Usuario();
	Usuario(string nick, string pass, DTFecha * fechaNac);
	virtual ~Usuario();
	string getNick();
	virtual DTUsuario* retornarDTUsuario()const=0;
	void asociarComentarioUsuario(Comentario * com);
};

#endif
