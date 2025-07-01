
#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H
#include "../../DTs/Definiciones.h"
#include <iostream>
using namespace std;

class DTVendedor;

class DTProducto {
public:
    int codigo;
    int precio;
    int stock;
    string nombre;
    string descripcion;
    cat categoria;

    DTVendedor * vendedor;
    //--------------------------------------------------------------------------------------------------------------------
    DTProducto();
    DTProducto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria,DTVendedor * vendedor);
    DTProducto(int codigo, int descuento, int cantidad);
    DTProducto(const DTProducto& other);
    virtual ~DTProducto();

    int getCodDTProd()const;

    string getNombreDTProd();

    static string catToString(cat categoria);

    DTProducto& operator=(const DTProducto& other);

    bool operator<(const DTProducto& other) const;

    friend ostream& operator<<(ostream& os, const DTProducto& dtProducto);

};



#endif //DTPRODUCTO_H
