#include "RealizarCompra.h"

RealizarCompra::RealizarCompra(SistemaControlador& controlador):controlador(controlador) {}

RealizarCompra::~RealizarCompra() {}

string RealizarCompra::realizarCompra() {
    //listarClientes
    string nick;
    int codigo;
    cout << "\n--- Seleccionar Cliente ---" << endl;
    set<string> clientes = controlador.listarClientes();
    if (clientes.empty()) {
        return "Error: No hay clientes registrados";
    }
    cout << "Clientes disponibles:" << endl;
    for (auto const &cliente : clientes) {
        cout << cliente << endl;
    }
    //seleccionarCliente
    cout <<"Ingresar nombre del cliente: ";
    cin >> nick;
    set<DTProducto> productos = controlador.seleccionarCliente(nick);
    for (auto const &product : productos) {
        cout << product << endl;
    }

    //-----
    string opcion;
    cout <<endl << "Desea comprar?: " << endl;
    cin >> opcion;
    set<DTProducto> productosCompra;
    if(opcion=="Si" || opcion=="SI" || opcion=="si") {
        //agregarProducto
        while (opcion=="Si" || opcion=="SI" || opcion=="si") {
            cout <<"Ingresar codigo del producto: "<<endl;
            cin >> codigo;
            bool encontrado = false;
            for (const DTProducto& product : productos) {
                if (codigo == product.codigo) {
                    productosCompra.insert(product);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
            cout << "Error: Codigo de producto no valido." << endl;
            }
            cout << "Desea agregar otro producto?: ";
            cin >> opcion;
        }
    }
    return "Compra Cancelada";


}

