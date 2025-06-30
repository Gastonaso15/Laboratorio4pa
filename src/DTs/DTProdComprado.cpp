
#include "DTProdComprado.h"

DTProdComprado::DTProdComprado() {

}

DTProdComprado::~DTProdComprado() {

}

DTProdComprado::DTProdComprado(int cantidad,bool enviado,DTProducto* producto) {
    this->cantidad = cantidad;
    this->enviado = enviado;
    this->producto = producto;
}

bool DTProdComprado::operator<(const DTProdComprado& other) const {
    return producto->codigo < other.producto->codigo;
}