#include "Cliente.h"
#include <string>
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTDireccion.h"
#include "../DTs/DTCliente.h"
#include "../DTs/DTUsuario.h"


Cliente::Cliente(string nick, string pass, DTFecha* fechaNac, DTDireccion* direccion, string ciudad)
 : Usuario(nick, pass, fechaNac),
   ciudad(ciudad),
   direccion(direccion)
{
}

Cliente::~Cliente() {
    delete fechaNac;
    delete direccion;
}

void Cliente::asociarProd() {}

DTCliente* Cliente::toDT() {
    return new DTCliente(
        this->getNickname(),
        this->getContrasenia(),
        this->getFechaNac(),
        this->getCiudad(),
        this->getDireccion()
    );
}


DTCliente Cliente::getCliente() const {
    return DTCliente(
        this->getNickname(),
        this->getContrasenia(),
        this->getFechaNac(),
        this->getCiudad(),
        this->getDireccion()
    );
}

DTUsuario* Cliente::retornarDTUsuario() const {
    return new DTCliente(
        this->getNickname(),
        "",
        this->getFechaNac(),
        this->getCiudad(),
        this->getDireccion()
    );
}

std::string Cliente::getCiudad() const {
    return this->ciudad;
}

DTDireccion* Cliente::getDireccion() const {
    /*if (this->direccion != nullptr) {
        return this->direccion->toDT();
    }
    return nullptr;
    */
    return this->direccion;
}

void Cliente::agregarCompra(Compra* compra) {
    if (compra != nullptr) {
        this->compras[compra->getId()] = compra;
    }
}