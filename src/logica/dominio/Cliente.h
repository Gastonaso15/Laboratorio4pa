//
// Created by marti on 16/6/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include <iostream>

#include "../../DTs/DTCliente.h"
#include "../DTs/DTDireccion.h"

class Cliente: public Usuario{

protected:
    DTDireccion * direccion;
    string ciudad;
public:
    Cliente(string nick, string pass, DTFecha *  fechaNac,DTDireccion* direccion, string ciudad);
    Cliente getCliente();
    Cliente();
    ~Cliente();
    void asociarProd();
    DTCliente getCliente() const;
};



#endif //CLIENTE_H
