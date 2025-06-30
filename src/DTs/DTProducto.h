
#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
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
    virtual ~DTProducto();
    DTProducto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria,DTVendedor * vendedor);
    DTProducto(int codigo, int descuento, int cantidad);
    DTProducto(const DTProducto& other);

    friend ostream& operator<<(ostream& os, const DTProducto& dtProducto);

    DTProducto& operator=(const DTProducto& other);
    int getCodDTProd()const;

    bool operator<(const DTProducto& other) const;

    string getNombreDTProd();

    static string catToString(cat categoria);

};



#endif //DTPRODUCTO_H
