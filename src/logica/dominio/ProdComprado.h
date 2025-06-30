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
  Producto* getProducto() const { return producto; }
  bool tieneArt(DTProducto * p);
  int getCantidad() const;
  DTProducto getProductos();
  bool getEnviado() const { return enviado; }
  void setEnviado(bool valor) { enviado = valor; }
};



#endif //PRODCOMPRADO_H
