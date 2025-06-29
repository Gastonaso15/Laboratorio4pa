#include "RealizarCompra.h"

RealizarCompra::RealizarCompra(SistemaControlador& controlador):controlador(controlador) {}

RealizarCompra::~RealizarCompra() {}

string RealizarCompra::realizarCompra() {
    string nick, producto;

    cout << "\n--- Seleccionar Cliente ---" << endl;
    set<string> clientes = controlador.listarClientes();

    if (clientes.empty()) {
        cout << "No hay clientes registrados." << endl;
    }

    // Mostrar clientes
    cout << "Clientes disponibles:" << endl;
    for (auto const &cliente : clientes) {
        cout << cliente << endl;
    }

    cout <<"Ingresar nombre del cliente: ";
    cin >> nick;
    set<DTProducto> productos = controlador.seleccionarCliente(nick);
    for (auto const &product : productos) {
        cout << product << endl;
    }
    bool confirmar =false;
    while (confirmar != true) {
        cout <<"ingresar nombre del producto: "<<endl;
        cin >> producto;
        for (auto const &product : productos) {
            if (producto == product.nombre) {

            }
        }
    }

    return "todo";
}

