#include "ProdPromocion.h"
#include "Producto.h"
#include "Promocion.h"
#include "../../DTs/DTProdPromocion.h"

#include <iostream>
using namespace std;


ProdPromocion::ProdPromocion(){}

ProdPromocion::~ProdPromocion(){}

ProdPromocion::ProdPromocion(int cantMininima, int descuento, Producto* prod, Promocion* promo){
  this->cantMininima = cantMininima;
  this->descuento = descuento;
  this->producto = prod;
  this->promocion = promo;
}

Promocion* ProdPromocion::retornarPromocion() {
  return this->promocion;
}

DTProdPromocion ProdPromocion::retornarDTProdPromocion(){
  //DTProducto* dto = new DTProducto(producto->retornarDTProducto());
  return DTProdPromocion(this->cantMininima, this->descuento, producto->retornarDTProducto());
}
