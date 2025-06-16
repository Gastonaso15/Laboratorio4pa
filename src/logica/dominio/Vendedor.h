//
// Created by marti on 16/6/2025.
//

#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include <iostream>
#include "../DTs/DTDireccion.h"

class Vendedor: public Usuario {
protected:
    string rut;
public:
    Vendedor();
    Vendedor(string nick, string pass, DTFecha *  fechaNac,string rut);
    void añadirProdListaVendedor();
    void retornarProductos();
    ~Vendedor();
};
#endif //VENDEDOR_H
