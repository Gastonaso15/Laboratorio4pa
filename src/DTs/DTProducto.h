
#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
#include "../dominio/Producto.h"
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
    DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria,DTVendedor * vendedor);
    DTProducto(int codigo, int descuento, int cantidad);
    virtual ~DTProducto();
    bool operator<(const DTProducto& other) const;
    DTProducto getCodDTProd();
    DTProducto getNombreDTProd();
    static string catToString(cat categoria);
};



#endif //DTPRODUCTO_H
