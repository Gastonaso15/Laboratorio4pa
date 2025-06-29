#include "Producto.h"
#include "Comentario.h"
#include "ProdComprado.h"
#include "../../DTs/DTProducto.h"
#include <iostream>
using namespace std;

Producto::Producto(){
}

Producto::~Producto(){
  for (auto& par : comentarios) {
    delete par.second;
  }
  comentarios.clear();
  for (auto& pc : prodscom) {
    delete pc;
  }
  prodscom.clear();

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
  DTVendedor* dtVen = nullptr;
  if (this->vendedor != nullptr) {
    DTUsuario* dtUsuarioBase = this->vendedor->retornarDTUsuario();
    DTVendedor* tempDtVenPtr = dynamic_cast<DTVendedor*>(dtUsuarioBase);
    if (tempDtVenPtr != nullptr) {
      dtVen = new DTVendedor(*tempDtVenPtr);
    }
    delete dtUsuarioBase;
    dtUsuarioBase = nullptr;
  }
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

void Producto::agregarProdPromocion(ProdPromocion* pp) { //
  this->prodsprom.insert(pp);
}