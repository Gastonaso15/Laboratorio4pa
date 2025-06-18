#include "../presentacion/Menu.h"
#include <iostream>
#include "../logica/controlador/SistemaControlador.h"
using namespace std;

int main() {
    SistemaControlador controlador;
    Menu menu(controlador);
    menu.mostrarMenu();
    return 0;
}
