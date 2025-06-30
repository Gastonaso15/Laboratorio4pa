#ifndef COMPRA_H
#define COMPRA_H
#include "../DTs/DTFecha.h"
#include "../DTs/DTProdComprado.h"
#include "../DTs/DTCliente.h"
#include "../dominio/ProdComprado.h"
#include "../DTs/DTCompra.h"
#include "../dominio/Cliente.h"
class DTCompra;
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
        Compra(int id,int cantProd,DTFecha *fecCompra,set<ProdComprado*> productosComprados);
        Compra(int id,int cantProd,DTFecha *fecCompra,float montoTotal,Cliente* cliente);
        Compra(int id,int cantProd,DTFecha *fecCompra,set<ProdComprado*> productosComprados, Cliente* cliente);
        ~Compra();
        void setId(int id);
        void setFecCompra(DTFecha* fecha);
        void setMontoTotal(float monto);
        void setCliente(Cliente* cliente);

        set<ProdComprado*> getProdComprado() const;
        float getMontoTotal() const;
         int getId() const;
        int getCantProd() const;
        DTFecha* getFecCompra() const;
        Cliente* getCliente() const;
        DTCompra * getCompra();
        void agregarProdComprado(ProdComprado* pc);
        bool agregoProd(DTProdComprado p);

        DTCompra toDT() const;
};



#endif //COMPRA_H
