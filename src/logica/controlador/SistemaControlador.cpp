
#include "SistemaControlador.h"
#include <iostream>
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include <map>
using namespace std;

SistemaControlador::SistemaControlador() {

}

SistemaControlador::~SistemaControlador() {
	// TODO Auto-generated destructor stub
}

string SistemaControlador::AltaUsuario(DTUsuario usuario) {

}


void SistemaControlador::agregarUsuario(DTUsuario* usuario) {
	DTUsuario *nuevoUsuario;
	DTCliente* dtoCli = dynamic_cast<DTCliente*>(usuario);
	if (dtoCli != nullptr) {
		nuevoUsuario = new Cliente(dtoCli->nick, dtoCli->pass,
			dtoCli->fechaNac,dtoCli->direccion, dtoCli->ciudad);
	} else {
		DTVendedor* dtoVen = dynamic_cast<DTVendedor*>(usuario);
		nuevoUsuario = new Vendedor(dtoVen->nick, dtoVen->pass,
				dtoCli->fechaNac, dtoVen->rut);

		}
}