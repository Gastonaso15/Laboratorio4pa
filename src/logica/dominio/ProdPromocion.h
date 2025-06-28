#ifndef PRODPROMOCION_H
#define PRODPROMOCION_H

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
};



#endif //PRODPROMOCION_H
