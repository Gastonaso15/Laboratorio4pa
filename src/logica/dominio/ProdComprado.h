#ifndef PRODCOMPRADO_H
#define PRODCOMPRADO_H
#include "Producto.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTProdComprado.h"


class Producto;
class Compra;

class ProdComprado {
  private:
    int cantidad;
    bool enviado;

    Producto * producto;
    Compra * compra;
  public:
    ProdComprado();
    ProdComprado(Producto* producto,Compra* compra,int cantidad,bool enviado);
    virtual ~ProdComprado();

    int getCantidad() const;

    bool getEnviado() const;
    bool tieneArt(DTProducto * p);

    void setEnviado(bool valor);
    void aumentarCantidad(int cantidadAAgregar);

    Producto* getProducto() const;
    DTProducto getProductos();
    DTProdComprado * getDTProdComprado();
};



#endif //PRODCOMPRADO_H
