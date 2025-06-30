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
  Producto* getProducto() const;
  bool tieneArt(DTProducto * p);
  int getCantidad() const;
  DTProducto getProductos();
  bool getEnviado() const;
  void setEnviado(bool valor);
  void aumentarCantidad(int cantidadAAgregar);
  DTProdComprado * getDTProdComprado();
};



#endif //PRODCOMPRADO_H
