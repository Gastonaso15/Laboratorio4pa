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

int Producto::getCodigo()const{
  return this->codigo;
}

int Producto::getPrecio()const{
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

/*DTProducto Producto::retornarDTProducto() {
  DTVendedor* dtVen = nullptr;
  if (this->vendedor != nullptr) {
    dtVen = this->vendedor->retornarDTVendedor(); // Asumo que retornarDTVendedor() devuelve NEW DTVendedor*
  }
  return DTProducto(this->codigo, this->nombre, this->precio, this->stock,
                    this->descripcion, this->categoria, dtVen);
}*/

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

void Producto::asociarComentarioProducto(Comentario *com) {
  this->comentarios[com->getId()] = com;
}

set<DTComentario*> Producto::getComentarios() {
  set<DTComentario*> dtComentarios;
  for (auto const& [id, comentarioPtr] : this->comentarios) {
    dtComentarios.insert(comentarioPtr->retornarDTComentario());
  }
  return dtComentarios;
}

Comentario* Producto::getComentario(int id) {
  auto it = this->comentarios.find(id);
  if (it != this->comentarios.end()) {
    return it->second;
  }
  return nullptr;
}

void Producto::eliminarComentario(int id) {
  comentarios.erase(id);
}