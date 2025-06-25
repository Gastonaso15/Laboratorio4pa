//
// Created by marti on 16/6/2025.
//

#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Usuario.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTUsuario.h"
#include "../dominio/Producto.h"
#include <iostream>
#include "../DTs/DTDireccion.h"
#include <map>

class Producto;

class Vendedor: public Usuario {
protected:
    string rut;
    map<int, Producto*> productos;
public:
    Vendedor();
    Vendedor(string nick, string pass, DTFecha *  fechaNac,string rut);
    ~Vendedor();
    void aniadirProdListaVendedor(Producto * producto);
    void retornarProductos();
    DTUsuario* retornarDTUsuario() const override;

};
#endif //VENDEDOR_H
