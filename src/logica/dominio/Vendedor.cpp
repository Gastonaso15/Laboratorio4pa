
#include "Vendedor.h"
#include <iostream>
#include <string>
#include "Usuario.h"
#include <iostream>
#include "../DTs/DTFecha.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTDireccion.h"
#include "../DTs/DTUsuario.h"
using namespace std;

Vendedor::Vendedor(string nick, string pass, DTFecha* fechaNac, string rut)
   : Usuario(nick, pass, fechaNac){
    this->rut=rut;
}
Vendedor::~Vendedor() {
    // TODO Auto-generated destructor stub
}