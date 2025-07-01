
#ifndef DTCOMPRA_H
#define DTCOMPRA_H
#include <iostream>
#include "DTFecha.h"
#include "DTProducto.h"
#include "DTProdComprado.h"
#include "DTCliente.h"
#include <set>

class DTCompra {
  public:
    int id;
    int cantProd;
    float montoTotal;

    DTFecha *fecCompra;
    DTCliente * cliente;

    set<DTProdComprado*> productosComprados;
    //--------------------------------------------------------------------------------------------------------------------
    DTCompra();
    DTCompra(int id, int cantProd, DTFecha *fecCompra, float montoTotal, DTCliente *clienteParam);
    DTCompra(int id, int cantProd, DTFecha *fecCompra, float montoTotal, set<DTProdComprado*> productos);
    DTCompra(int id, int cantProd, DTFecha *fecCompra, float montoTotal, set<DTProdComprado*> productos,DTCliente * cliente);
    DTCompra(int id, int cantProd, DTFecha *fecCompra, float montoTotal);
    ~DTCompra();

    int getIdCompra() const;
    int getCantidadProductos() const;

    float getMontoTotal() const;

    void agregarProd(DTProducto* producto);

    DTFecha * getFecha() const;
    DTCliente * getCliente() const;

    set<DTProdComprado*> getProductosComprados();

    bool operator<(const DTCompra& other) const {
        return this->id < other.id;
    }
};



#endif //DTCOMPRA_H
