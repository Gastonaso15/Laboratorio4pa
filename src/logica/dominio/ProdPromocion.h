#ifndef PRODPROMOCION_H
#define PRODPROMOCION_H

#include "../DTs/DTPromocion.h"
#include "../DTs/DTProdPromocion.h"
#include "Promocion.h"

class Producto;
class Promocion;
class DTProdPromocion;

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
        DTProdPromocion retornarDTProdPromocion();
};



#endif //PRODPROMOCION_H
