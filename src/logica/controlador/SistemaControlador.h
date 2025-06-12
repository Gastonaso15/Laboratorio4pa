#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_

#include <string>

#include "../interfaceSistema/ISistema.h"
#include "../dominio/Sistema.h"

class SistemaControlador : public ISistema{

private:
	Sistema* sistema;

public:
	SistemaControlador();
	virtual ~SistemaControlador();
	void agregarUsuario(DTUsuario* usuario);
	virtual string ingresar(string nick, string pass);
};


#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
#ifndef NEGOCIO_CONTROLLER_IUSUARIOCONTROLLER_H_
#define NEGOCIO_CONTROLLER_IUSUARIOCONTROLLER_H_
#include <iostream>
#include <set>
#include "../dto/DTOUsuario.h";
#include "IUsuario.h";
#include "Sistema.h"

using namespace std;

SistemaControlador::SistemaControlador() {

	private:
	Sistema* sistema;
public:
	SistemaControlador();
	void agregarUsuario(DTUsuario* usuario);
};

#endif;