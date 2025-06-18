#ifndef ALTAUSUARIO_H
#define ALTAUSUARIO_H
#include "../logica/controlador/SistemaControlador.h"
#include <string>
class AltaUsuario {
private:
    SistemaControlador& controlador;
public:
    AltaUsuario(SistemaControlador& controlador);
    virtual ~AltaUsuario();
    string altaUsuario();
};

#endif //ALTAUSUARIO_H


