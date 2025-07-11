#ifndef PRODPROMOCION_H
#define PRODPROMOCION_H

#include "../DTs/DTProdPromocion.h"

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
        ProdPromocion(int cantMininima, int descuento, Producto* prod, Promocion* promo);
        virtual ~ProdPromocion();

        Promocion* retornarPromocion();
        DTProdPromocion retornarDTProdPromocion();

        int getCantMinima() const;
        int getDescuento() const;
};



#endif //PRODPROMOCION_H
