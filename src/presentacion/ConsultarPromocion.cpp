#include "ConsultarPromocion.h"
#include <iostream>
#include <string>
#include "../logica/controlador/SistemaControlador.h"
using namespace std;

ConsultarPromocion::ConsultarPromocion(SistemaControlador& controlador):controlador(controlador) {}

ConsultarPromocion::~ConsultarPromocion() {}

string ConsultarPromocion::consultarPromocion() {
    return "";
}