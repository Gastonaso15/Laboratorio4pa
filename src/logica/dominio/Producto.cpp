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

DTProducto Producto::retornarDTProducto(){
  return DTProducto(this->codigo, this->nombre, this->precio, this->stock, this->descripcion, this->categoria);

}

void Producto::asociarProdVendedor(Vendedor* vendedor) {
  this->vendedor=vendedor;
}