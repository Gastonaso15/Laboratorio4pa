#include <iostream>
#include "DTFecha.h"
#include "DTProducto.h"
#ifndef DTCOMPRA_H
#define DTCOMPRA_H
using namespace std;


class DTCompra {
  private:
    int cantProd;
    DTFecha fecCompra;
    float montoTotal();

  public:
    DTCompra();
    ~DTCompra();
    DTCompra(int cantProd, DTFecha fecCompra, float montoTotal);
    void agregarProd(DTProducto* producto);
};



#endif //DTCOMPRA_H
