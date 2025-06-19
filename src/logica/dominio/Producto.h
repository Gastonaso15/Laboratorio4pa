#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "../dominio/Vendedor.h"
#include <iostream>
using namespace std;

class Producto {
  private:
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
    Vendedor * vendedor;
    //map<int,Mensaje*> mensajes;
    //list<ProdPromocion*> prodsprom;
    //list<ProdComprado*> prodscom;
  public:
    Producto();
    Producto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    virtual ~Producto();
    int getCodigo();
};



#endif //PRODUCTO_H
