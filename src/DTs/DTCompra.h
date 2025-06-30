
#ifndef DTCOMPRA_H
#define DTCOMPRA_H
#include <iostream>
#include "DTFecha.h"
#include "DTProducto.h"
#include "DTCliente.h"
#include <set>

#include "Compra.h"


class DTCompra {

  public:
  int cantProd;
  DTFecha fecCompra;
  float montoTotal;
  set<DTProdComprado*> productosComprados;
  int id;
    set<DTProducto> productos;
  DTCliente * cliente;
  set<DTProdComprado*> getProductosComprados();


    DTCompra();

  DTCompra(int id, int cantProd, DTFecha fecCompra, float montoTotal, DTCliente *clienteParam);



  ~DTCompra();

  DTCompra(int id, int cantProd, DTFecha fecCompra, float montoTotal, set<DTProducto> productos);


  DTCompra(int id, int cantProd, DTFecha fecCompra, float montoTotal);

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
