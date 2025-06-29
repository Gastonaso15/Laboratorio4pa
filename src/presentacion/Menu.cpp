#include "Menu.h"
#include "AltaUsuario.h"
#include "ListadoUsuarios.h"
#include "AltaProducto.h"
#include "ConsultarProducto.h"
#include "CrearPromocion.h"
#include "ConsultarPromocion.h"
#include "RealizarCompra.h"
#include "DejarComentario.h"
#include "EliminarComentario.h"
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
    ConsultarProducto consultarProducto(controlador);
    CrearPromocion crearPromocion(controlador);
    ConsultarPromocion consultarPromocion(controlador);
    RealizarCompra realizarCompra(controlador);
    DejarComentario dejarComentario(controlador);
    EliminarComentario eliminarComentario(controlador);

    do {
        cout << "------ MENU PRINCIPAL ------" << endl;
        cout << "1 - Alta de Usuario" << endl;
        cout << "2 - Listado de Usuarios" << endl;
        cout << "3 - Alta de Producto" << endl;
        cout << "4 - Consultar Producto" << endl;
        cout << "5 - Crear Promocion" << endl;
        cout << "6 - Consultar Promocion" << endl;
        cout << "7 - Realizar Compra" << endl;
        cout << "8 - Dejar Comentario" << endl;
        cout << "9 - Eliminar Comentario" << endl;
        cout << "10 - Enviar Producto" << endl;
        cout << "11 - Expediente Usuario" << endl;
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
            case 4: {
                respuesta = consultarProducto.consultarProducto();
                cout << respuesta << endl;
                break;
            }
            case 5: {
                respuesta = crearPromocion.crearPromocion();
                cout << respuesta << endl;
                break;
            }
            case 6: {
                respuesta = consultarPromocion.consultarPromocion();
                cout << respuesta << endl;
                break;
            }
            case 7: {
                respuesta = realizarCompra.realizarCompra();
                cout << respuesta << endl;
                break;
            }
            case 8: {
                respuesta = dejarComentario.dejarComentario();
                cout << respuesta << endl;
                break;
            }
            case 9: {
                respuesta = eliminarComentario.eliminarComentario();
                cout << respuesta << endl;
                break;
            }
            case 10: {
                break;
            }
            case 11: {
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