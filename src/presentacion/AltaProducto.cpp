#include "AltaProducto.h"
#include <iostream>
#include <string>
#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../dominio/Usuario.h"
#include "../dominio/Vendedor.h"
#include "../DTs/Definiciones.h"
using namespace std;

AltaProducto::AltaProducto(SistemaControlador& controlador):controlador(controlador) {}

AltaProducto::~AltaProducto() {}

string AltaProducto::altaProducto() {
    string respuesta;
    //listarNickVendedor
    set<string> vendedores = controlador.listarNickVendedor();
    if (vendedores.empty()) {
       respuesta= "Error: No hay vendedores registrados.";
        return respuesta;
    } else {
        cout << "--- Vendedores registrados ---" << endl;
        for (const string& nick : vendedores) {
            cout << "- " << nick << endl;
        }
    }
    //selectVendedor
    string nick;
    cout << "--- Seleccionar Vendedor ---" << endl;
    cout << "Ingrese nick del Vendedor: ";
    cin >> nick;
    respuesta = controlador.selectVendedor(nick);
    if (respuesta.substr(0, 5) == "Error") {
        return respuesta;
    } else {
        cout << respuesta;
    }
    //ingProducto
    bool resp;
    string nombre,descripcion;
    int codigo=0,precio,stock,categoria;
    cout << endl << "** Alta de Producto **" << endl;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese descripcion: ";
    cin.ignore();
    getline(cin, descripcion);
    cout << "Ingrese precio: ";
    cin >> precio;
    cout << "Ingrese stock: ";
    cin >> stock;
    cout << "Ingrese categoria: "<< endl;
    cout << "0 - Electrodomestico" << endl;
    cout << "1 - Ropa" << endl;
    cout << "2 - Otro" << endl;
    cin >> categoria;
    if (categoria < 0 || categoria > 2) {
        cout << "Opcion invalida, se asignara 'otro' por defecto." << endl;
        categoria = 2;
    }
    cat cate = static_cast<cat>(categoria);
    DTProducto * prod = new DTProducto(codigo,nombre,precio,stock,descripcion,cate);
    resp=controlador.ingProducto(*prod);
    if (resp == true) {
        respuesta="Producto dado de Alta con exito";
    }else {
        respuesta="Error: Producto ya existe";
    }
    return respuesta;
}