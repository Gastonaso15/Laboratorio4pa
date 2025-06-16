#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#include <iostream>
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include <map>
using namespace std;

#include <string>

class SistemaControlador{
private:
	map<string,DTProducto*>carrito;
	map<string,DTUsuario*> usuarios;
public:
	SistemaControlador();
	virtual ~SistemaControlador();
	void agregarUsuario(DTUsuario* usuario);
	virtual string ingresar(string nick, string pass);
};


#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
