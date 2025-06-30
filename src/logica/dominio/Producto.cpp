#include "Producto.h"
#include "Comentario.h"
#include "ProdComprado.h"
#include "../../DTs/DTProducto.h"

Producto::Producto(){
}

Producto::~Producto(){
  for (auto const& [key, val] : comentarios) {
    delete val;
  }
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

string Producto::getNombre() {
  return this->nombre;
}

int Producto::getStock() {
  return this->stock;
}

string Producto::getDescripcion() {
  return this->descripcion;
}

cat Producto::getCategoria() {
  return this->categoria;
}

string Producto::catToString(cat categoria) {
    switch (categoria) {
      case Electrodomestico: return "Electrodomestico";
      case Ropa: return "Ropa";
      case Otro: return "Otro";
      default: return "Categoria desconocida";
    }
 }

DTProducto* Producto::retornarDTProducto() const {
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
  return new DTProducto(this->codigo, this->nombre, this->precio, this->stock, this->descripcion, this->categoria, dtVen);
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

void Producto::restarStock(int cantidad) {
  if (this->stock >= cantidad) {
    this->stock -= cantidad;
  } else {
    this->stock = 0;
  }
}

const set<ProdPromocion*>& Producto::getProdPromociones() const {
  return prodsprom;
}
Vendedor* Producto::getVendedor() const {
  return this->vendedor;
}