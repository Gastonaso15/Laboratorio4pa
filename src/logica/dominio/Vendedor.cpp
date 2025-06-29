#include "Vendedor.h"
#include <string>
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTUsuario.h"

Vendedor::Vendedor(string nick, string pass, DTFecha* fechaNac, string rut)
   : Usuario(nick, pass, fechaNac){
    this->rut=rut;
}
Vendedor::~Vendedor() {

}

string Vendedor::getNickname() const {
    return this->nick;
}

DTUsuario* Vendedor::retornarDTUsuario() const {
    return new DTVendedor(this->nick, "", this->fechaNac, this->rut);
}

void Vendedor::aniadirProdListaVendedor(Producto* producto) {
    int codigo = producto->getCodigo();
    productos.insert({codigo, producto});
}

set<DTProducto> Vendedor::retornarProductos() {
    set<DTProducto> productosVendedor;
    for (const auto& prod : productos) {
        productosVendedor.insert(prod.second->retornarDTProducto());
    }
    return productosVendedor;
}