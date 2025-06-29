
#ifndef DTCOMPRA_H
#define DTCOMPRA_H
#include <iostream>
#include "DTFecha.h"
#include "DTProducto.h"
#include "DTCliente.h"
#include <set>


class DTCompra {

  public:
  int cantProd;
  DTFecha fecCompra;
  float montoTotal;
  int id;
  DTCliente * cliente;

    DTCompra();
    ~DTCompra();
    DTCompra(int id, int cantProd, DTFecha fecCompra, float montoTotal, DTCliente* cliente);

    void agregarProd(DTProducto* producto);

    int getIdCompra() const;
    DTFecha getFecha() const;
    DTCliente * getCliente() const;
    float getMontoTotal() const;
    int getCantidadProductos() const;

    bool operator<(const DTCompra& other) const {
        return this->id < other.id;
    }
};



#endif //DTCOMPRA_H
