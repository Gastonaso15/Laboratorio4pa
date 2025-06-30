#ifndef DTPRODPROMOCION_H
#define DTPRODPROMOCION_H
#include "DTProducto.h"

class DTPromocion;

class DTProdPromocion {
    public:
    int cantMinima;
    int descuento;

    DTProducto producto;
    DTPromocion * promocion;

    DTProdPromocion();
    ~DTProdPromocion();
    DTProdPromocion(int cantMinima, int descuento, const DTProducto& prod);

    bool operator<(const DTProdPromocion& otro) const;

};


#endif //DTPRODPROMOCION_H
