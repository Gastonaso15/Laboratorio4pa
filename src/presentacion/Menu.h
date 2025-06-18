#ifndef MENU_H
#define MENU_H
#include "../logica/controlador/SistemaControlador.h"

class Menu {
private:
    SistemaControlador& controlador;
public:
    Menu(SistemaControlador& controlador);
    void mostrarMenu();
};


#endif //MENU_H
