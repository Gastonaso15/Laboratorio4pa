#include "Menu.h"
#include "AltaUsuario.h"
#include "ListadoUsuarios.h"
#include "AltaProducto.h"
#include <iostream>
using namespace std;


Menu::Menu(SistemaControlador& controlador): controlador(controlador) {

}

void Menu::mostrarMenu() {
    int opcion;
    string respuesta;
    AltaUsuario altaUsuario(controlador);
    ListadoUsuarios listadoUsuarios(controlador);
    AltaProducto altaProducto(controlador);

    do {
        cout << "------ MENU PRINCIPAL ------" << endl;
        cout << "1 - Alta de Usuario" << endl;
        cout << "2 - Listado de Usuarios" << endl;
        cout << "3 - Alta de Producto" << endl;
        cout << "0 - Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                respuesta = altaUsuario.altaUsuario();
                cout << respuesta << endl;
                break;
            }
            case 2: {
                listadoUsuarios.listarUsuarios();
                break;
            }
            case 3: {
                respuesta = altaProducto.altaProducto();
                cout << respuesta << endl;
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