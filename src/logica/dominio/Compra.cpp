#include "Compra.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTCompra.h"
#include "../DTs/DTCliente.h"
#include "../dominio/ProdComprado.h"
#include "../dominio/Cliente.h"

using namespace std;


Compra::Compra() {
}

Compra::Compra(int id, int cantProd, DTFecha *fecCompra, set<ProdComprado *> productosComprados) {
  this->id = id;
  this->cantProd = cantProd;
  this->productosComprados = productosComprados;
  this->fecCompra = new DTFecha(*fecCompra); //
}

Compra::Compra(int id,int cantProd,DTFecha *fecCompra,set<ProdComprado*> productosComprados, Cliente* cliente){
  this->id = id;
  this->cantProd = cantProd;
  this->productosComprados = productosComprados;
  this->fecCompra = new DTFecha(*fecCompra);
  this->cliente = cliente;
}

Compra::~Compra(){
    delete fecCompra;
    fecCompra = nullptr;
    for (ProdComprado* pc : productosComprados) {
        delete pc;
    }
    productosComprados.clear();
}

int Compra::getId() const {
  return id; }
int Compra::getCantProd() const {
  return cantProd; }
DTFecha* Compra::getFecCompra() const {
  return fecCompra; }
Cliente* Compra::getCliente() const {
  return cliente; }

/*DTCompra Compra::getCompra() {
  std::set<DTProducto> productos ;
  for (auto producto : productosComprados) {
    DTProducto* dtProdPuntero = producto->getProductos();
    DTProducto dto = *dtProdPuntero;
    delete dtProdPuntero;
    productos.insert(dto);
  }
  DTFecha fecha = *(this->getFecCompra());
  DTCompra carrito = DTCompra(this->getId(), this->getCantProd(), fecha, this->getMontoTotal(), productos);
  return carrito;
}
*/
set<ProdComprado*> Compra::getProdComprado() const {
  return productosComprados;
}

float Compra::getMontoTotal() const {
  return this->montoTotal;
}

DTCompra Compra::toDT() const {
    DTFecha* dtFechaCopia = new DTFecha(*this->fecCompra);
    DTCliente* dtClienteCopia = this->cliente->toDT();
    return DTCompra(this->id, this->cantProd, *dtFechaCopia, this->montoTotal, dtClienteCopia);
}
void Compra::agregarProdComprado(ProdComprado* pc) {
    if (pc != nullptr) {
        productosComprados.insert(pc);
    }

}

/*bool Compra::agregoProd(DTProducto p){
  for(auto* prodComp : productosComprados){
    bool b = prodComp->tieneArt(p);
    if(!b){
      SistemaControlador* sistemaGlobal;
      Producto* prod = sistemaGlobal->buscarProductoPorDT(p);
      ProdComprado * cp = new ProdComprado(prod, this, 1, false);
      productosComprados.insert(cp);
      delete sistemaGlobal;
      return true;
    }

  }
  return false;
}
*/