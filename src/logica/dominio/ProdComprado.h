#ifndef PRODCOMPRADO_H
#define PRODCOMPRADO_H
#include "Producto.h"
#include "../DTs/DTProducto.h"


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

  Producto* getProducto() const;
  DTProducto* getProductos() const;
  DTProducto* retornarDTProductoAsociado() const;

  int getCantidad() const;

  bool tieneArt(DTProducto p) const;
  bool getEnviado() const;

  void setEnviado(bool valor);
};



#endif //PRODCOMPRADO_H
