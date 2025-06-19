#include "AltaProducto.h"
#include <iostream>
#include <string>
#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../dominio/Usuario.h"
#include "../dominio/Vendedor.h"
using namespace std;

AltaProducto::AltaProducto(SistemaControlador& controlador):controlador(controlador) {}

AltaProducto::~AltaProducto() {}

void AltaProducto::listarNickVendedor() {
    set<string> vendedores = controlador.listarNickVendedor();
    if (vendedores.empty()) {
        cout << "No hay vendedores registrados." << endl;
    } else {
        cout << "--- Vendedores registrados ---" << endl;
        for (const string& nick : vendedores) {
            cout << "- " << nick << endl;
        }
    }
}