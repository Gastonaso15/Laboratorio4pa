#include "Compra.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include <iostream>
#include <string>

#include "Producto.h"
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
  this->cantProd = cantProd; // cantidad de instancias en compraActual
  this->productosComprados = productosComprados;
  this->fecCompra = new DTFecha(*fecCompra); //
}

Compra::Compra(int id,int cantProd,DTFecha *fecCompra,set<ProdComprado*> productosComprados, Cliente* cliente){
  this->id = id;
  this->cantProd = cantProd;
  this->productosComprados = productosComprados;
  this->fecCompra = new DTFecha(*fecCompra); // Se recomienda una copia profunda
  this->cliente = cliente; // Asignar el cliente
}

Compra::~Compra(){
    // Liberar memoria de fecCompra si Compra es dueño de él
    delete fecCompra;
    fecCompra = nullptr;

    // Liberar memoria de los ProdComprado si Compra es dueño de ellos
    for (ProdComprado* pc : productosComprados) {
        delete pc;
    }
    productosComprados.clear();
    // No se libera 'cliente' aquí, ya que el controlador o algún otro gestor de usuarios es el dueño.
}

int Compra::getId() const {
  return id; }
int Compra::getCantProd() const {
  return cantProd; }
DTFecha* Compra::getFecCompra() const {
  return fecCompra; }
Cliente* Compra::getCliente() const {
  return cliente; }

DTCompra Compra::getCompra() {
  set<DTProducto> productos ;
  for (auto producto : productosComprados) {
    productos.insert(producto->getProductos());
  }
  DTFecha fecha = *(this->getFecCompra());
  DTCompra carrito = DTCompra(this->getId(), this->getCantProd(), fecha, this->getMontoTotal(), productos);
  return carrito;
}



set<ProdComprado*> Compra::getProdComprado() const {
  return productosComprados;
}

float Compra::getMontoTotal() const {
  return this->montoTotal;
}

DTCompra Compra::toDT() const {
    // Necesitas construir un DTCompra.
    // Esto implica obtener los DTs de los objetos relacionados (Cliente, Fecha).

    DTFecha* dtFechaCopia = new DTFecha(*this->fecCompra); // Crea una copia profunda de DTFecha para el DTO
    DTCliente* dtClienteCopia = this->cliente->toDT(); // Asume que Cliente tiene un método toDT()

    // Crear y retornar una instancia de DTCompra
    // Asegúrate de que el constructor de DTCompra acepte estos parámetros
    return DTCompra(this->id, this->cantProd, *dtFechaCopia, this->montoTotal, dtClienteCopia);

    // NOTA: Si el constructor de DTCompra recibe DTFecha por valor, pasar *dtFechaCopia.
    // Si recibe DTFecha* por puntero, pasar dtFechaCopia.

    // Si tu DTCompra es muy simple y no tiene campos para montoTotal, etc., ajusta esto.
}
void Compra::agregarProdComprado(ProdComprado* pc) {
    if (pc != nullptr) {
        productosComprados.insert(pc);
    }

}

bool Compra::agregoProd(DTProducto p){
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
