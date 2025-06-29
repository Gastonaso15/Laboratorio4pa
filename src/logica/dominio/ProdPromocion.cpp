#include "ProdPromocion.h"
#include "Producto.h"
#include "../../DTs/DTProdPromocion.h"

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
  return DTProdPromocion(this->cantMininima, this->descuento, producto->retornarDTProducto());
}
