#ifndef CONSULTARPRODUCTO_H
#define CONSULTARPRODUCTO_H
#include "../logica/controlador/SistemaControlador.h"
#include <string>

class ConsultarProducto {
private:
    SistemaControlador& controlador;
public:
    ConsultarProducto(SistemaControlador& controlador);
    virtual ~ConsultarProducto();

    string consultarProducto();
};




#endif //CONSULTARPRODUCTO_H
