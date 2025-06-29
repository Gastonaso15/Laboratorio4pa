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

/*bool Compra::agregoProd(DTProducto p){
  for(auto* prodComp : prodscom){
    bool b = prodComp->tieneArt(p);
    if(b){
      Producto* prod = buscarProductoPorDT(p);
      ProdComprado * cp = new ProdComprado(prod, this, 1, false);
      prodscom.insert(cp);
      return true;
    }

  }
  return false;
}*/
