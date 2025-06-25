
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
    string altaProducto();
    /*void listarNickVendedor();
    string selectVendedor();
    string ingProducto(DTProducto producto);*/
};


#endif //ALTAPRODUCTO_H
