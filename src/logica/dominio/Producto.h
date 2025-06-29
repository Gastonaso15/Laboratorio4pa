#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "../../DTs/Definiciones.h"
#include "../../DTs/DTProducto.h"
#include "../../DTs/DTComentario.h"
#include "Vendedor.h"
#include "ProdPromocion.h"
#include <set>
#include <map>
#include <string>

class Vendedor;
class Comentario;
class ProdComprado;

class Producto {
  private:
    int codigo;
    int precio;
    int stock;

    string descripcion;
    string nombre;

    cat categoria;
    Vendedor * vendedor;

    map<int,Comentario*> comentarios;

    set<ProdPromocion*> prodsprom;
    set<ProdComprado*> prodscom;
  public:
    Producto();
    Producto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria);
    virtual ~Producto();

    int getCodigo()const;
    int getPrecio()const;

    set<DTComentario*> getComentarios();

    Comentario* getComentario(int id);
    DTProducto retornarDTProducto();

    bool productoEnPromo();

    void asociarProdVendedor(Vendedor* vendedor);
    void agregarProdPromocion(ProdPromocion* pp);
    void asociarComentarioProducto(Comentario *com);

};



#endif //PRODUCTO_H
