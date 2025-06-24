#ifndef LISTADOUSUARIOS_H
#define LISTADOUSUARIOS_H

#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTUsuario.h"
#include <string>


class ListadoUsuarios {
  private:
    SistemaControlador& controlador;
  public:
    ListadoUsuarios(SistemaControlador& controlador);
    virtual ~ListadoUsuarios();
    void listarUsuarios();
};



#endif //LISTADOUSUARIOS_H
