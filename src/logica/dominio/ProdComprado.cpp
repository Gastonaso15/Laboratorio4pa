#include "ProdComprado.h"
#include <iostream>
using namespace std;

ProdComprado::ProdComprado(){

}

ProdComprado::~ProdComprado(){

}

ProdComprado::ProdComprado(Producto* producto,  Compra* compra, int cantidad,bool enviado){
  this->producto = producto;
  this->compra = compra;
  this->cantidad=cantidad;
  this->enviado=enviado;
}

bool ProdComprado::tieneArt(DTProducto p) {
  return this->producto->getCodigo() == p.codigo;
}