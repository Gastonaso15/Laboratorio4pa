
#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include "DTVendedor.h"
#include <iostream>
using namespace std;

class DTProducto {
public:
    enum cat {
        Electrodomestico,
        Ropa,
        Otro
      };
    int codigo;
    string nombre;
    int precio;
    int stock;
    string descripcion;
    cat categoria;
    DTVendedor * vendedor;
    DTProducto();
    DTProducto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    virtual ~DTProducto();
};



#endif //DTPRODUCTO_H
