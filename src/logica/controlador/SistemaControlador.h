#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#include <iostream>
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include <map>
using namespace std;

#include <string>

class SistemaControlador{
protected:
	map<string,DTProducto*>carrito;
	map<string,Usuario*> usuarios;
public:
	SistemaControlador();
	virtual ~SistemaControlador();
	void agregarUsuario(DTUsuario* usuario);
	void AltaUsuario(DTUsuario usuario);
};


#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
