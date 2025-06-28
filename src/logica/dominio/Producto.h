#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "../../DTs/Definiciones.h"
#include "Vendedor.h"
#include <set>
#include <map>
#include <string>
using namespace std;


class DTProducto;
class Vendedor;
class Comentario;
class ProdComprado;
class ProdPromocion;

class Producto {
  private:
    int codigo;
    string nombre;
    int precio;
    int stock;
    string descripcion;
    cat categoria;
    Vendedor * vendedor;
    map<int,Comentario*> comentarios;
    set<ProdPromocion*> prodsprom;
    set<ProdComprado*> prodscom;
  public:
    Producto();
    Producto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    virtual ~Producto();
    int getCodigo();
    int getPrecio();
    DTProducto retornarDTProducto();
    void asociarProdVendedor(Vendedor* vendedor);
};



#endif //PRODUCTO_H
