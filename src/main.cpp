#include <iostream>
#include "logica/controlador/SistemaControlador.h"
#include "presentacion/Menu.h"
using namespace std;

int main() {
    SistemaControlador& controlador = SistemaControlador::getInstancia();
    Menu menuPrincipal(controlador);
    menuPrincipal.mostrarMenu();
    return 0;
}