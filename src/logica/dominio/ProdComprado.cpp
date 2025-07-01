#include "ProdComprado.h"
#include <iostream>
using namespace std;

ProdComprado::ProdComprado() : cantidad(0), enviado(false), producto(nullptr), compra(nullptr) {
}

ProdComprado::~ProdComprado(){

}

ProdComprado::ProdComprado(Producto* producto,  Compra* compra, int cantidad,bool enviado){
  this->producto = producto;
  this->compra = compra;
  this->cantidad=cantidad;
  this->enviado=enviado;
}

int ProdComprado::getCantidad() const {
  return cantidad;
}

bool ProdComprado::tieneArt(DTProducto* p) {
  return this->producto->getCodigo() == p->codigo;
}

Producto* ProdComprado::getProducto() const {
  return this->producto;
}

bool ProdComprado::getEnviado() const {
  return this->enviado;
}

DTProducto ProdComprado::getProductos() {
  DTProducto prod = DTProducto(producto->getCodigo(),
      producto->getNombre(),producto->getPrecio(), producto->getStock(),producto->getDescripcion(),
      producto->getCategoria());
  return prod;
}

void ProdComprado::setEnviado(bool valor) {
  this->enviado = valor;
}

void ProdComprado::aumentarCantidad(int cantidadAAgregar) {
  this->cantidad += cantidadAAgregar;
}

DTProdComprado* ProdComprado::getDTProdComprado() {
  DTProducto* dtProd = this->producto->retornarDTProducto();
  return new DTProdComprado(dtProd, this->cantidad);
}