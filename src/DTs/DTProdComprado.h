
#ifndef DTPRODCOMPRADO_H
#define DTPRODCOMPRADO_H

#include "DTProducto.h"

class DTCompra;

class DTProdComprado {
public:
    int cantidad;
    bool enviado;

    DTProducto* producto;
    DTCompra* compra;
    //--------------------------------------------------------------------------------------------------------------------
    DTProdComprado();
    DTProdComprado(int cantidad,bool enviado,DTProducto* producto);
    DTProdComprado(DTProducto* producto,int cantidad);
    virtual ~DTProdComprado();

    bool operator<(const DTProdComprado& other) const;
};

#endif //DTPRODCOMPRADO_H
