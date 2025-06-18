#include "AltaUsuario.h"

#include <iostream>
#include <string>

#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include "../DTs/DTDireccion.h"

using namespace std;


AltaUsuario::AltaUsuario(SistemaControlador& controlador): controlador(controlador) {}

AltaUsuario::~AltaUsuario() {}

string AltaUsuario::altaUsuario() {
    string nick, pass;
    int dia, mes, anio;

    cout << "** Alta de Usuario **" << endl;
    cout << "Ingrese nick: ";
    cin >> nick;
    cout << "Ingrese pass: ";
    cin >> pass;

    cout << "Ingrese fecha de nacimiento: " << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio;

    DTFecha* fechaNac = new DTFecha(dia, mes, anio);

    int tipoUsuario;
    cout << "Seleccione el tipo de usuario:" << endl;
    cout << "1 - Cliente" << endl;
    cout << "2 - Vendedor" << endl;
    cout << "Opcion: ";
    cin >> tipoUsuario;

    string resultado;

    if (tipoUsuario == 1) {
        string ciudad, calle;
        int numero;
        cout << "Ingrese ciudad: ";
        cin >> ciudad;
        cout << "Ingrese calle: ";
        cin >> calle;
        cout << "Ingrese numero: ";
        cin >> numero;

        DTDireccion* direccion = new DTDireccion(calle, numero);
        DTCliente* dtCliente = new DTCliente(nick, pass, fechaNac, ciudad, direccion);
        resultado = controlador.altaUsuario(dtCliente);

    }
    else if (tipoUsuario == 2) {
        string rut;
        cout << "Ingrese RUT: ";
        cin >> rut;

        DTVendedor* dtVendedor = new DTVendedor(nick, pass, fechaNac, rut);
        resultado = controlador.altaUsuario(dtVendedor);

    }
    else {
        resultado = "Tipo de usuario invalido.";
        delete fechaNac;
    }

    return resultado;
}