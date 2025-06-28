#ifndef COMPRA_H
#define COMPRA_H


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

};



#endif //COMPRA_H
