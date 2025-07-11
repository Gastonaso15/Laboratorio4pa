
#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include "DTFecha.h"
#include <iostream>
using namespace std;

class DTUsuario {
public:
    string nick;
    string pass;
    DTFecha * fechaNac;
    //--------------------------------------------------------------------------------------------------------------------
    DTUsuario();
    DTUsuario(string nick, string contrasenia, DTFecha * fechaNac);
    virtual ~DTUsuario();

    string getNick() const;
    string getPass();
    DTFecha getFechaNac();

    virtual string getTipo() const = 0;
    virtual string obtenerInfo() const = 0;
};

#endif