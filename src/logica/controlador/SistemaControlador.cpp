
#include "SistemaControlador.h"

#include <string>

#include "../dominio/Sistema.h"
#include "DTs/DTCliente.h"
#include "DTs/DTUsuario.h"
#include "DTs/DTVendedor.h"

SistemaControlador::SistemaControlador() {
	this->sistema = new Sistema();

}

SistemaControlador::~SistemaControlador() {
	// TODO Auto-generated destructor stub
}

string SistemaControlador::AltaUsuario(DTUsuario usuario) {

}


void SistemaControlador::agregarUsuario(DTUsuario* usuario) {
	Usuario *nuevoUsuario;
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

	this->sistema->usuarios.insert(nuevoUsuario);
}