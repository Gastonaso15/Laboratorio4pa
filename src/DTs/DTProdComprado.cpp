
#include "DTProdComprado.h"

DTProdComprado::DTProdComprado() {

}

DTProdComprado::~DTProdComprado() {

}

DTProdComprado::DTProdComprado(int cantidad,bool enviado,DTProducto* producto) {
    this->cantidad = cantidad;
    this->enviado = enviado;
    this->producto = producto;
    this->compra = nullptr;
}

DTProdComprado::DTProdComprado(DTProducto* producto,int cantidad) {
    this->cantidad = cantidad;
    this->enviado = false;
    this->producto = producto;
    this->compra = nullptr;
}

bool DTProdComprado::operator<(const DTProdComprado& other) const {
    return producto->codigo < other.producto->codigo;
}