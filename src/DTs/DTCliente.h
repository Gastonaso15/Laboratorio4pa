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
private:
    string ciudad;
    DTDireccion * direccion;
public:
    DTCliente();
    virtual ~DTCliente();
    DTCliente(string nick, string contrasenia, DTFecha * fecha, string ciudad, DTDireccion * direccion);
    string getCiudad();
    DTDireccion getDireccion();
    void asociarProd();
};



#endif //DTCLIENTE_H
