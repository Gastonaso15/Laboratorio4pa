#ifndef ENVIAR_PRODUCTO_H
#define ENVIAR_PRODUCTO_H
#include "../logica/controlador/SistemaControlador.h"
#include <string>

class EnviarProducto {
private:
    SistemaControlador& controlador;
public:
    EnviarProducto(SistemaControlador& controlador);
    ~EnviarProducto();

    std::string enviarProducto();
};

#endif