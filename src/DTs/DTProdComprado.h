
#ifndef DTPRODCOMPRADO_H
#define DTPRODCOMPRADO_H


#include "DTProducto.h"

class DTCompra;

class DTProdComprado {
public:
    int cantidad;
    bool enviado;
    DTProducto * producto;
    DTCompra* compra;
    DTProdComprado();
    DTProdComprado(int cantidad,bool enviado,DTProducto* producto);
    virtual ~DTProdComprado();
    bool operator<(const DTProdComprado& other) const;
};

#endif //DTPRODCOMPRADO_H
