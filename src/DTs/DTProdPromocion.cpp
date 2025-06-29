#include "DTProdPromocion.h"

DTProdPromocion::DTProdPromocion() {}

DTProdPromocion::~DTProdPromocion() {}

DTProdPromocion::DTProdPromocion(int cantMinima, int descuento, DTProducto *producto) {
    this->cantMinima = cantMinima;
    this->descuento = descuento;
    this->producto = producto;
}

bool DTProdPromocion::operator<(const DTProdPromocion& otro) const {
    return this->producto->codigo < otro.producto->codigo;
}

