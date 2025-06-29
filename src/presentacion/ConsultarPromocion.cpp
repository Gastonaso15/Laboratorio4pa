#include "ConsultarPromocion.h"
#include <iostream>
#include <string>
#include "../logica/controlador/SistemaControlador.h"
using namespace std;

ConsultarPromocion::ConsultarPromocion(SistemaControlador& controlador):controlador(controlador) {}

ConsultarPromocion::~ConsultarPromocion() {}

string ConsultarPromocion::consultarPromocion() {
    string respuesta;
    //listarPromos
    set<DTPromocion*> promociones = controlador.listarPromociones();
    if (promociones.empty()) {
        respuesta= "Error: No hay Promociones registradas.";
        return respuesta;
    } else {
        cout << "--- Promociones registradas ---" << endl;
        for (DTPromocion * promo : promociones) {
            cout << promo->obtenerInfo() << endl;
            cout << "---------------------------" << endl;
            delete promo;
        }
    }
    //selectPromo
    string continuar,nombre;
    cout << endl << "** Consultar Promocion **" << endl;
    cout << "Desea ver los Productos de alguna Promocion?: ";
    cin >> continuar;
    if(continuar=="Si" || continuar=="SI" || continuar=="si") {
        cout << "Ingrese nombre de Promocion: ";
        cin >> nombre;
        set<DTProdPromocion*> prodprom = controlador.selectPromo(nombre);
        if (prodprom.empty()) {
            respuesta="Error: No hay Promociones registradas con ese nombre.";
        } else {
            for (DTProdPromocion* p : prodprom) {
                cout << "Cantidad Minima: " << p->cantMinima << endl
                     << "Descuento: " << p->descuento << endl;
                cout << "Codigo: " << p->producto.codigo << endl
                         << "Nombre: " << p->producto.nombre << endl
                         << "Precio: " << p->producto.precio << endl
                         << "Stock: " << p->producto.stock << endl
                         << "Descripcion: " << p->producto.descripcion << endl
                         << "Categoria: " << DTProducto::catToString(p->producto.categoria) << endl;
                if (p->producto.vendedor != nullptr) {
                    cout << "Vendedor: " << p->producto.vendedor->nick << endl;
                } else {
                    cout << "Vendedor: No especificado" << endl;
                }
                delete p;
            }
            respuesta="Informacion de Promocion mostrada con exito";
        }
    }
    return respuesta;
}
