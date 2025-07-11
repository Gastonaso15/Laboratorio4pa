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
    delete fechaNac;
}

string Vendedor::getNickname() const {
    return this->nick;
}

DTUsuario* Vendedor::retornarDTUsuario() const {
    return new DTVendedor(this->nick, "", this->fechaNac, this->rut);
}

set<DTPromocion*> Vendedor::getPromocion() {
    set<DTPromocion*> retorno;
    for (auto const promos : promociones) {
        retorno.insert(promos.second->retornarDTPromocionConProd());
    }
    return retorno;
}

void Vendedor::aniadirProdListaVendedor(Producto* producto) {
    int codigo = producto->getCodigo();
    productos.insert({codigo, producto});
}

set<DTProducto*> Vendedor::retornarProductos() {
    set<DTProducto*> productosVendedor;
    for (const auto& par : productos) {
        Producto* p = par.second;
        DTProducto* dtProdPuntero = p->retornarDTProducto();
        productosVendedor.insert(dtProdPuntero);
    }
    return productosVendedor;
}

set<Promocion*> Vendedor::retornarPromociones() {
    set<Promocion*> retorno;
    for (auto const promos : promociones) {
        retorno.insert(promos.second);
    }
    return retorno;
}

string Vendedor::getRut() const {
    return this->rut;
}

void Vendedor::agregarPromocion(Promocion* promo) {
    promociones[promo->getNom()] = promo;
}