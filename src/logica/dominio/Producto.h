#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "../dominio/Vendedor.h"
#include <iostream>
#include "../../DTs/Definiciones.h"

using namespace std;

class DTProducto;

class Producto {
  private:

    int codigo;
    string nombre;
    int precio;
    int stock;
    string descripcion;
    cat categoria;
    Vendedor * vendedor;
    //map<int,Mensaje*> mensajes;
    //list<ProdPromocion*> prodsprom;
    //list<ProdComprado*> prodscom;
  public:
    Producto();
    Producto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    virtual ~Producto();
    int getCodigo();
    DTProducto retornarDTProducto();
};



#endif //PRODUCTO_H
