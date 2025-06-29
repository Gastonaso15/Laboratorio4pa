#include "DTProdPromocion.h"

DTProdPromocion::DTProdPromocion() {}

DTProdPromocion::~DTProdPromocion() {}

DTProdPromocion::DTProdPromocion(int cantMinima, int descuento, const DTProducto& prod)
  : cantMinima(cantMinima), descuento(descuento), producto(prod) {}

bool DTProdPromocion::operator<(const DTProdPromocion& otro) const {
    return this->producto.codigo < otro.producto.codigo;
}

