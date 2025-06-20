
#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
#include "dominio/Producto.h"
#include "DTVendedor.h"
#include "../../DTs/Definiciones.h"
#include <iostream>
using namespace std;

class DTProducto {
public:
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
    bool operator<(const DTProducto& other) const;
    DTProducto getCodDTProd();
    DTProducto getNombreDTProd();
};



#endif //DTPRODUCTO_H
