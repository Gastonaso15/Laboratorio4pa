#ifndef PRODCOMPRADO_H
#define PRODCOMPRADO_H


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
  ProdComprado(int cantidad,bool enviado);
  virtual ~ProdComprado();
  Producto* getProducto() const { return producto; }
  bool getEnviado() const { return enviado; }
  void setEnviado(bool valor) { enviado = valor; }
};
10


#endif //PRODCOMPRADO_H
