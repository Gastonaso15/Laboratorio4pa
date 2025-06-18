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
    string getCiudad();
    DTDireccion getDireccion();//no es necesario porque esta en publico
    void asociarProd();
};



#endif //DTCLIENTE_H
