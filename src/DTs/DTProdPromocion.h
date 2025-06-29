#ifndef DTPRODPROMOCION_H
#define DTPRODPROMOCION_H

#include "dominio/ProdPromocion.h"
#include "DTProducto.h"

class DTProducto;

class DTProdPromocion {
    public:
    int cantMinima;
    int descuento;
    DTProducto * producto;
    DTPromocion * promocion;
    DTProdPromocion();
    ~DTProdPromocion();
    DTProdPromocion(int cantMinima,int descuento,DTProducto* producto);
    bool operator<(const DTProdPromocion& otro) const;

};


#endif //DTPRODPROMOCION_H
