#include "Producto.h"
#include "../../DTs/DTProducto.h"
#include <iostream>
using namespace std;

Producto::Producto(){
}

Producto::~Producto(){

}

Producto::Producto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria){
  this->codigo = codigo;
  this->nombre = nombre;
  this->precio = precio;
  this->stock = stock;
  this->descripcion = descripcion;
  this->categoria = categoria;
}

int Producto::getCodigo()const{
  return this->codigo;
}

int Producto::getPrecio()const{
  return this->precio;
}

DTProducto Producto::retornarDTProducto(){
  DTVendedor* dtVen = dynamic_cast<DTVendedor*>(this->vendedor->retornarDTUsuario());
  return DTProducto(this->codigo, this->nombre, this->precio, this->stock, this->descripcion, this->categoria,dtVen);
}

void Producto::asociarProdVendedor(Vendedor* vendedor) {
  this->vendedor=vendedor;
}


bool Producto::productoEnPromo() {
  if (prodsprom.empty()) { // Si no hay productos en promoción asociados
    return false;
  }

  // Si hay promociones, verificamos si alguna está vigente
  for (const auto& prodProm : prodsprom) {
    if (prodProm->retornarPromocion()->estaVigente()) {
      return true; // Encontramos al menos una promoción vigente
    }
  }

  // Si iteramos por todas y ninguna está vigente
  return false;
}
