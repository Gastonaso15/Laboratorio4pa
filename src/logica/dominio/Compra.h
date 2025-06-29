#ifndef COMPRA_H
#define COMPRA_H
#include "../DTs/DTFecha.h"
#include "../DTs/DTCliente.h"
#include "../dominio/ProdComprado.h"
#include "../DTs/DTCompra.h"
#include "../dominio/Cliente.h"

class Cliente;
class Compra {
    private:
        int id;
        int cantProd;
        DTFecha * fecCompra;
        set<ProdComprado*> productosComprados;
        Cliente * cliente;
    float montoTotal;
    public:
        Compra();
        Compra(int id,int cantProd,DTFecha *fecCompra, Cliente* cliente);
        ~Compra();

        set<ProdComprado*> getProdComprado() const;
        float getMontoTotal() const;
         int getId() const;
        int getCantProd() const;
        DTFecha* getFecCompra() const;
        Cliente* getCliente() const;

        void agregarProdComprado(ProdComprado* pc);

        DTCompra toDT() const;
};



#endif //COMPRA_H
