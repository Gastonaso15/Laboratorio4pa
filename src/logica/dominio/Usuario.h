#ifndef LOGICA_USUARIO_H_
#define LOGICA_USUARIO_H_
#include <iostream>
#include "../DTs/DTFecha.h"
using namespace std;

class Usuario {
protected:
	string nick;
	string pass;
	DTFecha * fechaNac;

public:
	Usuario();
	Usuario(string nick, string pass, DTFecha * fechaNac);
	virtual ~Usuario();
	string getNick();
};

#endif
