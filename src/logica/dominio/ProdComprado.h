#ifndef PRODCOMPRADO_H
#define PRODCOMPRADO_H
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"

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
  ProdComprado(Producto* producto,  Compra* compra, int cantidad, bool enviado);
  virtual ~ProdComprado();
  bool tieneArt(DTProducto p);

};




#endif //PRODCOMPRADO_H
