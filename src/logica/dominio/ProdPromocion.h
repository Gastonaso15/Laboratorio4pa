#ifndef PRODPROMOCION_H
#define PRODPROMOCION_H

#include "../DTs/DTPromocion.h"
#include "Promocion.h"

class Producto;
class Promocion;

class ProdPromocion {
    private:
        int cantMininima;
        int descuento;
        Producto * producto;
        Promocion * promocion;
    public:
        ProdPromocion();
        ProdPromocion(int cantMininima,int descuento);
        virtual ~ProdPromocion();
        Promocion* retornarPromocion();
};



#endif //PRODPROMOCION_H
