#include "ProdPromocion.h"
#include <iostream>
using namespace std;

ProdPromocion::ProdPromocion{}

ProdPromocion::~ProdPromocion{}

ProdPromocion::ProdPromocion(int cantMininima,int descuento){
  this->cantMininima = cantMininima;
  this->descuento = descuento;
}
