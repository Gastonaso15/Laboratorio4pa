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

Producto::getCodigo(){
  return this->codigo;
}

Producto::getPrecio(){
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
  //Cambios respecto al Diagrama de Clase; asi es mas eficiente
  bool enPromo=!prodsprom.empty();
  if (enPromo) {
    for (const auto& prodProm : prodsprom) {
      if (prodProm->retornarPromocion()->estaVigente()) {
        return true;
      }
    }
  }
  return false;
}
