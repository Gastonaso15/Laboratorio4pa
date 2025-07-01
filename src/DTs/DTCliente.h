
#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include "DTDireccion.h"
#include "DTUsuario.h"
#include <map>
#include <iostream>
#include <set>
using namespace std;

class DTCompra;

class DTCliente:public DTUsuario {
public:
    string ciudad;
    DTDireccion * direccion;

    map<int,DTCompra*> compras;

    set<DTCompra*> setCompras;
    //--------------------------------------------------------------------------------------------------------------------
    DTCliente();
    DTCliente(string nick, string pass, DTFecha * fecha, string ciudad, DTDireccion * direccion);
    DTCliente(string nick, string pass, DTFecha * fecha);
    DTCliente(string nick, string pass, DTFecha * fecha, string ciudad, DTDireccion * direccion,set<DTCompra*> setCompras);
    virtual ~DTCliente();

    string getCiudad() const;
    string getNickname() const;
    string getTipo() const override;
    string obtenerInfo() const override;
    DTDireccion getDireccion() const;

    void asociarProd();
};


#endif //DTCLIENTE_H
