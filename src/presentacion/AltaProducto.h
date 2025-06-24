
#ifndef ALTAPRODUCTO_H
#define ALTAPRODUCTO_H

#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTProducto.h"
#include <string>

class AltaProducto {
  private:
    SistemaControlador& controlador;
  public:
    AltaProducto(SistemaControlador& controlador);
    virtual ~AltaProducto();
    void listarNickVendedor();
    string selectVendedor(string nick);
    string ingProducto(DTProducto producto);
};


#endif //ALTAPRODUCTO_H
