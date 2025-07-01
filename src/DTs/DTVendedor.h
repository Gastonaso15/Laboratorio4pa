
#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H
#include "DTUsuario.h"
#include "DTFecha.h"
#include "DTPromocion.h"
#include <map>
#include <iostream>
using namespace std;

class DTProducto;

class DTVendedor:public DTUsuario{
public:
    string rut;

    set<DTPromocion*> setPromos;
    set<DTProducto*> setProductos;
    //--------------------------------------------------------------------------------------------------------------------
    DTVendedor();
    DTVendedor(string nick, string pass, DTFecha * fechaNac, string rut);
    DTVendedor(string nick, string pass, DTFecha * fechaNac, string rut,set<DTPromocion*> setPromos,set<DTProducto*> setProductos);
    virtual ~DTVendedor();

    string getRUT();
    string getTipo() const override;
    string obtenerInfo() const override;
};



#endif //DTVENDEDOR_H
