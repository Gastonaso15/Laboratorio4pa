
#ifndef EXPEDIENTEUSUARIO_H
#define EXPEDIENTEUSUARIO_H

#include "../logica/controlador/SistemaControlador.h"
#include <string>

class ExpedienteUsuario {
private:
    SistemaControlador& controlador;
public:
    ExpedienteUsuario(SistemaControlador& controlador);
    ~ExpedienteUsuario();
    string expedienteUsuario();
};



#endif //EXPEDIENTEUSUARIO_H
