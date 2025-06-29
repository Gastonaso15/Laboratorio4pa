#ifndef PRODCOMPRADO_H
#define PRODCOMPRADO_H
#include "Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"

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
  bool tieneArt(DTProducto p);
  DTProducto getProductos();
  bool getEnviado() const { return enviado; }
  void setEnviado(bool valor) { enviado = valor; }
};



#endif //PRODCOMPRADO_H
