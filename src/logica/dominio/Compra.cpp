#include "Compra.h"
#include <iostream>
using namespace std;

Compra::Compra(){}

Compra::~Compra(){}

Compra::Compra(int id,int cantProd,DTFecha *fecCompra){
  this->id = id;
  this->cantProd = cantProd;
  this->fecCompra = fecCompra;
}

