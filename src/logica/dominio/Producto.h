#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "../../DTs/Definiciones.h"
#include "../../DTs/DTProducto.h"
#include "../../DTs/DTComentario.h"
#include "Vendedor.h"
#include "Promocion.h"
#include "ProdPromocion.h"
#include <set>
#include <map>
#include <string>
using namespace std;

class Vendedor;
class Comentario;
class ProdComprado;

class Producto {
  private:
    int codigo;
    int precio;
    int stock;

    string nombre;
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

    int getCodigo()const;
    int getPrecio()const;
    int getStock();

    string getNombre();
    string getDescripcion();
    string catToString(cat categoria);

    cat getCategoria();
    set<DTComentario*> getComentarios();
    Comentario* getComentario(int id);
    DTProducto* retornarDTProducto()const ;

    bool productoEnPromo();
    void asociarProdVendedor(Vendedor* vendedor);
    void agregarProdPromocion(ProdPromocion* pp);
    void asociarComentarioProducto(Comentario *com);
    void eliminarComentario(int id);
    void restarStock(int cantidad);
    const set<ProdPromocion*>& getProdPromociones() const;

};



#endif //PRODUCTO_H
