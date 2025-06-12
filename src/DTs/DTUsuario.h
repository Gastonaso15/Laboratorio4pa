//
// Created by marti on 12/6/2025.
//

#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include "DTFecha.h"
#include <iostream>
using namespace std;

class DTUsuario {
protected:
    string nick;
    string contrasenia;
    DTFecha * fechaNac;
public:
    DTUsuario();
    virtual ~DTUsuario();
    DTUsuario(string nick, string contrasenia, DTFecha * fechaNac);
    string getNick();
    string getContrasenia();
    DTFecha getFechaNac();
};

#endif