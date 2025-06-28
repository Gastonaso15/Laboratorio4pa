#ifndef CREARPROMOCION_H
#define CREARPROMOCION_H

#include "../logica/controlador/SistemaControlador.h"
#include <string>

class CrearPromocion {
  private:
    SistemaControlador& controlador;
  public:
    CrearPromocion(SistemaControlador& controlador);
    ~CrearPromocion();
    string crearPromocion();
};




#endif //CREARPROMOCION_H
