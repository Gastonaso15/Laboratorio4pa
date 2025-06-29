#include "DTCompra.h"

// Constructor vacío
DTCompra::DTCompra() {}

// Constructor con parámetros
DTCompra::DTCompra(int id, int cantProd, DTFecha fecCompra, float montoTotal, DTCliente* clienteParam)
  : id(id), cantProd(cantProd), fecCompra(fecCompra), montoTotal(montoTotal), cliente(clienteParam) {

}
// Destructor
DTCompra::~DTCompra() {}

// Getters
int DTCompra::getIdCompra() const {
    return id;
}

DTFecha DTCompra::getFecha() const {
    return fecCompra;
}

DTCliente * DTCompra::getCliente() const {
    return cliente;
}

int DTCompra::getCantidadProductos() const {
    return cantProd;
}

float DTCompra::getMontoTotal() const {
    return montoTotal;
}