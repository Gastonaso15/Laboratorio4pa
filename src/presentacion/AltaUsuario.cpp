#include "AltaUsuario.h"

#include <iostream>
#include <string>

#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTUsuario.h"


using namespace std;

AltaUsuario::AltaUsuario() {
    // TODO Auto-generated constructor stub

}

AltaUsuario::~AltaUsuario() {
    // TODO Auto-generated destructor stub
}

void AltaUsuario::pedirCredenciales() {

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
    //fechaNac= new DTFecha(dia,mes,anio); PARA REVISAR
    cout << endl;
}


