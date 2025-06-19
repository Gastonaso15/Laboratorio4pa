#include "Menu.h"
#include "AltaUsuario.h"
#include "AltaProducto.h"
#include <iostream>
using namespace std;


Menu::Menu(SistemaControlador& controlador): controlador(controlador) {

}

void Menu::mostrarMenu() {
    int opcion;
    AltaUsuario altaUsuario(controlador);
    AltaProducto altaProducto(controlador);

    do {
        cout << "------ MENU PRINCIPAL ------" << endl;
        cout << "1 - Alta Usuario" << endl;
        cout << "2 - Alta Producto" << endl;
        cout << "0 - Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string respuesta = altaUsuario.altaUsuario();
                cout << respuesta << endl;
                break;
            }
            case 2: {
                altaProducto.listarNickVendedor(); //Solo para probar, falta el resto de AltaProducto
                break;
            }
            case 0:
                cout << "Saliendo del sistema..." << endl;
            break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
            break;
        }
    } while (opcion != 0);
}