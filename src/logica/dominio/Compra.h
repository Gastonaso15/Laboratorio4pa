#ifndef COMPRA_H
#define COMPRA_H
#include "../dominio/ProdComprado.h"
#include "../dominio/Cliente.h"
#include <set>

class Cliente;
class ProdComprado;

class Compra {
    private:
        int id;
        int cantProd;
        DTFecha * fecCompra;
        set<ProdComprado*> prodscom;
        Cliente * cliente;
    public:
        Compra();
        Compra(int id,int cantProd,DTFecha *fecCompra);
        virtual ~Compra();
        float getMontoTotal() const;
        bool agregoProd(DTProducto p);

};



#endif //COMPRA_H
