#include "ProdComprado.h"
#include <iostream>
using namespace std;

ProdComprado::ProdComprado() : cantidad(0), enviado(false), producto(nullptr), compra(nullptr) {
}

ProdComprado::~ProdComprado(){
  producto = nullptr;
  compra = nullptr;
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
DTProducto * ProdComprado::getProductos() const {
  if (this->producto != nullptr) {
    return this->producto->retornarDTProducto();
  }
  return nullptr;
}
bool ProdComprado::tieneArt(DTProducto p) const {
  if (this->producto != nullptr) {
    return this->producto->getCodigo() == p.getCodDTProd();
  }
  return false;
}
void ProdComprado::setEnviado(bool valor) {
  this->enviado = valor;
}