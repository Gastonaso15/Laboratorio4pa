#ifndef COMPRA_H
#define COMPRA_H
#include "../DTs/DTFecha.h"
#include "../dominio/ProdComprado.h"
#include "../DTs/DTCompra.h"
#include "../dominio/Cliente.h"

class Cliente;
class Compra {
    private:
        int id;
        int cantProd;
        float montoTotal;

        set<ProdComprado*> productosComprados;

        DTFecha * fecCompra;
        Cliente * cliente;

    public:
        Compra();
        Compra(int id,int cantProd,DTFecha *fecCompra, Cliente* cliente);
        ~Compra();

        int getId() const;
        int getCantProd() const;

        float getMontoTotal() const;

        void agregarProdComprado(ProdComprado* pc);

        set<ProdComprado*> getProdComprado() const;

        DTFecha* getFecCompra() const;
        Cliente* getCliente() const;
        DTCompra toDT() const;
};



#endif //COMPRA_H
