
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
				dtoCli->nom, dtoCli->descrip, dtoCli->paisResidencia);
	} else {
		DTVendedor* dtoVen = dynamic_cast<DTVendedor*>(usuario);
		nuevoUsuario = new Vendedor(dtoVen->nick, dtoVen->pass,
				dtoVen->nom, dtoVen->descrip, dtoVen->instituto);

		}
	}

	this->sistema->usuarios.insert(nuevoUsuario);
}