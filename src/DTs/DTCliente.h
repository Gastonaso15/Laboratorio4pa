//
// Created by marti on 12/6/2025.
//

#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include "DTDireccion.h"
#include "DTUsuario.h"
#include <iostream>
using namespace std;

class DTCliente:public DTUsuario {
public:
    string ciudad;
    DTDireccion * direccion;

    DTCliente();
    virtual ~DTCliente();
    DTCliente(string nick, string pass, DTFecha * fecha, string ciudad, DTDireccion * direccion);
    DTCliente(string nick, string pass, DTFecha * fecha);

    string getCiudad() const;
    DTDireccion getDireccion() const;
    string getNickname() const;
    string getTipo() const override;
    string obtenerInfo() const override;


    void asociarProd();
};


#endif //DTCLIENTE_H
