//
// Created by marti on 12/6/2025.
//

#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include "DTFecha.h"

class DTUsuario {
protected:
    string nick;
    string contrasenia;
    DTFECHA * fechaNac;
public:
    DTUsuario();
    vitual ~DTUsuario();
    DTUsuario(string nick, string contrasenia, DTFECHA * fechaNac);
    string getNick()const;
    string getContrasenia()const;
    DTFecha getFechaNac()const;
};