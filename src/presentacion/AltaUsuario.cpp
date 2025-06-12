#include "AltaUsuario.h"

#include <iostream>
#include <string>

#include "../logica/controlador/SistemaControlador.h"
#include "../logica/interfaceSistema/ISistema.h"
#include "DTs/DTFecha.h"
#include "DTs/DTUsuario.h"


using namespace std;

AltaUsuario::AltaUsuario() {
    // TODO Auto-generated constructor stub

}

AltaUsuario::~AltaUsuario() {
    // TODO Auto-generated destructor stub
}

void AltaUsuario::pedirCredenciales() {

    //notese que si bien estamos usando la interface ISistema,
    //estamos haciendo un new de su implementacioón
    //por lo tanto el desacoplamiento que tenemos es un bajo
    //mojoraremos esto utilizando el patrón Factory en futuras versiones

    ISistema *iSistema = new SistemaControlador();
    string nick, pass;
    int dia, mes, anio;
    cout << " ** Login ** " << endl;
    cout << "Ingrese nick: ";
    cin >> nick;
    cout << endl;
    cout << "Ingrese pass: ";
    cin >> pass;
    cout << endl;
    cout << "Fecha Nacimiento: ";
    cin >> dia, mes, anio;
    fechaNac= new DTFecha(dia,mes,anio);
    cout << endl;
    cout << iSistema->ingresar(dtusuario);
}


