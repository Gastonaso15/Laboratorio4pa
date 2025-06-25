#include "ConsultarProducto.h"
#include "../DTs/DTProducto.h"
#include <string>
#include <iostream>
using namespace std;

ConsultarProducto::ConsultarProducto(SistemaControlador& controlador):controlador(controlador) {}

ConsultarProducto::~ConsultarProducto() {}

string ConsultarProducto::consultarProducto() {
    string respuesta;
    //listarProd
    set<DTProducto> productos = controlador.listarProd();
    if (productos.empty()) {
        respuesta= "Error: No hay productos registrados.";
        return respuesta;
    } else {
        cout << "--- Productos registrados ---" << endl;
        for (const DTProducto& prod : productos) {
            cout << "Codigo: " << prod.codigo << " Nombre: " << prod.nombre << endl;
        }
    }
    //selectProd
    int codigo;
    cout << endl << "** Consultar Producto **" << endl;
    cout << "Ingrese codigo: ";
    cin >> codigo;
    DTProducto * producto  = controlador.selectProd(codigo);
    if (producto != nullptr) {
        cout << "Precio: " << producto->precio << endl << "Stock: " << producto->stock << endl
        << "Descripcion: " << producto->descripcion << endl << "Categoria: " << DTProducto::catToString(producto->categoria) << endl
        << "Vendedor: " << producto->vendedor->nick << endl;
        respuesta="Informacion de Producto mostrada con exito";
    }else {
        respuesta="Error: Producto no encontrado.";
    }
    return respuesta;
}


