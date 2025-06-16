#include "SistemaControlador.h"
#include <iostream>
#include <string>
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include <map>
#include <stdexcept>

using namespace std;

SistemaControlador::SistemaControlador() {}

SistemaControlador::~SistemaControlador() {
    // Liberar memoria de los usuarios
    for (auto& par : usuarios) {
        delete par.second;
    }
    usuarios.clear();
}

void SistemaControlador::agregarUsuario(DTUsuario* usuario) {
    Usuario* nuevoUsuario = nullptr;

    if (DTCliente* dtoCli = dynamic_cast<DTCliente*>(usuario)) {
        DTFecha* fechaCopia = new DTFecha(*dtoCli->fechaNac);  // copia por valor

        nuevoUsuario = new Cliente(
            dtoCli->nick,
            dtoCli->pass,
            fechaCopia,
            dtoCli->direccion,
            dtoCli->ciudad
        );

    } else if (DTVendedor* dtoVen = dynamic_cast<DTVendedor*>(usuario)) {
        DTFecha* fechaCopia = new DTFecha(*dtoVen->fechaNac);  // copia por valor

        nuevoUsuario = new Vendedor(
            dtoVen->nick,
            dtoVen->pass,
            fechaCopia,
            dtoVen->rut
        );
    }

    if (nuevoUsuario != nullptr) {
        string nick = usuario->nick;
        if (usuarios.find(nick) == usuarios.end()) {
            usuarios[nick] = nuevoUsuario;
        } else {
            delete nuevoUsuario;
            throw runtime_error("El usuario con ese nick ya existe.");
        }
    } else {
        throw runtime_error("Tipo de usuario desconocido.");
    }
}
