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
        set<DTProdPromocion*> prodprom=controlador.selectPromo(nombre);
        if (prodprom.empty()) {
            respuesta="Error: No hay Promociones registradas con ese nombre.";
        }else {
            for (DTProdPromocion* p : prodprom) {
                DTProducto* dtprod = p->producto;
                cout << "Cantidad Minima: " << p->cantMinima << endl << "Descuento: " << p->descuento << endl;
                cout << "Precio: " << dtprod->precio << endl << "Stock: " << dtprod->stock << endl
            << "Descripcion: " << dtprod->descripcion << endl << "Categoria: " << DTProducto::catToString(dtprod->categoria) << endl
            << "Vendedor: " << dtprod->vendedor->nick << endl;
                respuesta="Informacion de Promocion mostrada con exito";
            }
        }
    }
    return respuesta;
}