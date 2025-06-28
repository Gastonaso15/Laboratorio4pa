#ifndef CONSULTARPROMOCION_H
#define CONSULTARPROMOCION_H

#include "../logica/controlador/SistemaControlador.h"
#include <string>

class ConsultarPromocion {
  private:
    SistemaControlador& controlador;
  public:
    ConsultarPromocion(SistemaControlador& controlador);
    ~ConsultarPromocion();
    string consultarPromocion();
};



#endif //CONSULTARPROMOCION_H
