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
  this->fecCompra = fecCompra;
}

Compra::Compra(int id,int cantProd,DTFecha *fecCompra,set<ProdComprado*> productosComprados, Cliente* cliente){
  this->id = id;
  this->cantProd = cantProd;
  this->productosComprados = productosComprados;
  this->fecCompra = fecCompra;
  this->cliente = cliente;
}

Compra::Compra(int id,int cantProd,DTFecha *fecCompra,float montoTotal,Cliente * cliente){
  this->id = id;
  this->cantProd = cantProd;
  this->fecCompra = fecCompra;
  this->montoTotal = montoTotal;
  this->cliente = cliente;
}


Compra::~Compra(){
  for (ProdComprado* pc : productosComprados) {
    delete pc;
  }
  delete fecCompra;
}

int Compra::getId() const {
  return id; }
int Compra::getCantProd() const {
  return cantProd; }
DTFecha* Compra::getFecCompra() const {
  return fecCompra; }
Cliente* Compra::getCliente() const {
  return cliente; }

DTCompra* Compra::getCompra() {
  set<DTProdComprado*> productos ;
  for (auto producto : productosComprados) {
    productos.insert(producto->getDTProdComprado());
  }
  DTFecha * fecha = (this->getFecCompra());
  DTCliente dtCli = this->cliente->getCliente();
  DTCliente *cli = new DTCliente(dtCli);
  DTCompra*  carrito = new DTCompra(this->getId(), this->getCantProd(), fecha, this->getMontoTotal(), productos,cli);
  return carrito;
}



set<ProdComprado*> Compra::getProdComprado() const {
  return productosComprados;
}

float Compra::getMontoTotal() const {
  return this->montoTotal;
}

DTCompra Compra::toDT() const {
    DTFecha* dtFechaCopia = new DTFecha(*this->fecCompra);
    DTCliente* dtClienteCopia = this->cliente->toDT();
    return DTCompra(this->id, this->cantProd, dtFechaCopia, this->montoTotal, dtClienteCopia);
}
void Compra::agregarProdComprado(ProdComprado* pc) {
    if (pc != nullptr) {
        productosComprados.insert(pc);
    }

}

/*bool Compra::agregoProd(DTProdComprado p){
  for(auto* prodComp : productosComprados){
    bool b = prodComp->tieneArt(p.producto);
    if(!b){
      Producto* prod = controlador.buscarProductoPorDT(p.producto);
      ProdComprado * cp = new ProdComprado(prod, this, p.cantidad, false);
      productosComprados.insert(cp);
      delete sistemaGlobal;
      return true;
    }

  }
  return false;
}*/

bool Compra::agregoProd(DTProdComprado p_dto){
  for(auto* prodComp : productosComprados){
    if(prodComp->tieneArt(p_dto.producto)){
      prodComp->aumentarCantidad(p_dto.cantidad);
      return true;
    }
  }
  SistemaControlador& sistemaGlobal = SistemaControlador::getInstancia();
  Producto* prod = sistemaGlobal.buscarProductoPorDT(p_dto.producto);
  ProdComprado * cp = new ProdComprado(prod, this, p_dto.cantidad, false);
  productosComprados.insert(cp);
  return true;
}

void Compra::setId(int id) {
  this->id = id;
}
void Compra::setFecCompra(DTFecha* fecha) {
  this->fecCompra = fecha;
}
void Compra::setMontoTotal(float monto) {
  this->montoTotal = monto;
}
void Compra::setCliente(Cliente* cliente) {
  this->cliente=cliente;
}
