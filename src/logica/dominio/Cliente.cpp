
#include "Cliente.h"
#include <iostream>
#include <string>
#include "Usuario.h"
#include <iostream>
#include "../DTs/DTFecha.h"
#include "../DTs/DTDireccion.h"
#include "../DTs/DTCliente.h"
#include "../DTs/DTUsuario.h"
using namespace std;

Cliente::Cliente(string nick, string pass, DTFecha* fecha, DTDireccion* direccion, string ciudad)
 : Usuario(nick, pass, fechaNac){
    this->direccion=direccion;
    this->ciudad=ciudad;
}
Cliente::~Cliente() {
    // TODO Auto-generated destructor stub
}
void Cliente::asociarProd() {

}