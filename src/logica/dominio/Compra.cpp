#include "Compra.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include <iostream>
using namespace std;

Compra::Compra(){}

Compra::~Compra(){}

Compra::Compra(int id,int cantProd,DTFecha *fecCompra){
  this->id = id;
  this->cantProd = cantProd;
  this->fecCompra = fecCompra;
}

/* bool Compra::agregoProd(DTProducto p){
  for(auto* prodComp : prodscom){
    bool b = prodComp->tieneArt(p);
    if(b){
      ProdComprado * cp = new ProdComprado(p, this, 1, false);
      prodscom.insert(cp);
      return true;
    }
    return false;
  }
}
*/