#include "RealizarCompra.h"
#include "../DTs/DTProdComprado.h"
#include "DTProdComprado.h"

RealizarCompra::RealizarCompra(SistemaControlador& controlador):controlador(controlador) {}

RealizarCompra::~RealizarCompra() {}

string RealizarCompra::realizarCompra() {
    //listarClientes
    string resultado;
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
    int cantidad;
    cout <<endl << "Desea comprar?: " << endl;
    cin >> opcion;
    if(opcion=="Si" || opcion=="SI" || opcion=="si") {
        //agregarProducto
        while (opcion=="Si" || opcion=="SI" || opcion=="si") {
            cout <<"Ingresar codigo del producto: "<<endl;
            cin >> codigo;
            cout <<"Ingresar cantidad deseada: "<<endl;
            cin >> cantidad;
            bool encontrado = false;
            for (const DTProducto& product : productos) {
                if (codigo == product.codigo) {
                    DTProducto* prodPtr = new DTProducto(product);
                    DTProdComprado nuevoProd(cantidad,false,prodPtr);
                    controlador.agregarProducto(nuevoProd);
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
        //verDetalleCompra
        DTCompra*  compra=controlador.verDetalleCompra();
        if (compra != nullptr) {
            set<DTProdComprado*> productoscom = compra->getProductosComprados();
            cout << "Precio total $: " << compra->montoTotal << endl << "Fecha de Compra: " << compra->fecCompra->toString() << endl;
            cout << "--- Productos Comprados ---" << endl;
            for (DTProdComprado* prodComprado : productoscom){
                cout << "Nombre: " << prodComprado->producto->nombre << endl;
                cout << "Precio: $" << prodComprado->producto->precio << endl;
                cout << "Descripcion: " << prodComprado->producto->descripcion << endl;
                cout << "Cantidad: " << prodComprado->cantidad << endl;
                cout << endl;
            }
        }else {
            return "Error: No se pudo obtener el detalle de la compra";
        }
        //confirmarCompra
        string respuesta;
        cout << endl << "Desea confirmar su compra?: " << endl;
        cin >> respuesta;
        if(respuesta=="Si" || respuesta=="SI" || respuesta=="si") {
            resultado=controlador.confirmarCompra();
            return resultado;
        }

    }
    return "Compra Cancelada";

}

