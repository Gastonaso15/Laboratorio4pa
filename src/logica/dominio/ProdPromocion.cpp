#include "ProdPromocion.h"
#include <iostream>
using namespace std;

ProdPromocion::ProdPromocion(){}

ProdPromocion::~ProdPromocion(){}

ProdPromocion::ProdPromocion(int cantMininima,int descuento){
  this->cantMininima = cantMininima;
  this->descuento = descuento;
}

Promocion* ProdPromocion::retornarPromocion() {
  return this->promocion;
}

DTProdPromocion ProdPromocion::retornarDTProdPromocion(){
  DTProducto* dto = new DTProducto(producto->retornarDTProducto());
  return DTProdPromocion(this->cantMininima, this->descuento, dto);
}
