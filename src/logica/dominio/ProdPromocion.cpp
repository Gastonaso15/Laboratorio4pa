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


DTProdPromocion ProdPromocion::retornarDTProdPromocion() {
  DTProducto* dtProdPuntero = producto->retornarDTProducto();
  DTProducto dtProdCopia = *dtProdPuntero;
  delete dtProdPuntero;
  dtProdPuntero = nullptr;
  return DTProdPromocion(this->cantMininima, this->descuento, dtProdCopia);
}
