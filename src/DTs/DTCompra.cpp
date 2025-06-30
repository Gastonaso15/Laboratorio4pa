#include "DTCompra.h"

DTCompra::DTCompra() {}

DTCompra::DTCompra(int id, int cantProd, DTFecha * fecCompra, float montoTotal, DTCliente* clienteParam)
  : id(id), cantProd(cantProd), fecCompra(fecCompra), montoTotal(montoTotal), cliente(clienteParam) {

}

DTCompra::~DTCompra() {

}

DTCompra::DTCompra(int id, int cantProd, DTFecha * fecCompra, float montoTotal, set<DTProdComprado*> productos) {
    this->id = id;
    this->cantProd = cantProd;
    this->fecCompra = fecCompra;
    this->montoTotal = montoTotal;
    this->productosComprados = productos;
    this->cliente = nullptr;
}

DTCompra::DTCompra(int id, int cantProd, DTFecha * fecCompra, float montoTotal, set<DTProdComprado*> productos,DTCliente * cliente) {
    this->id = id;
    this->cantProd = cantProd;
    this->fecCompra = fecCompra;
    this->montoTotal = montoTotal;
    this->productosComprados = productos;
    this->cliente = cliente;
}



DTCompra::DTCompra(int id, int cantProd, DTFecha *fecCompra, float montoTotal) {
    this->id = id;
    this->cantProd = cantProd;
    this->fecCompra = fecCompra;
    this->montoTotal = montoTotal;
}


// Getters
int DTCompra::getIdCompra() const {
    return id;
}

DTFecha *DTCompra::getFecha() const {
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

set<DTProdComprado*> DTCompra::getProductosComprados() {
    set<DTProdComprado*> dtsProductos;
    for (DTProdComprado *pc : this->productosComprados) {
        dtsProductos.insert(pc);
    }
    return dtsProductos;
}