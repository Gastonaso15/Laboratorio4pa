//
// Created by marti on 12/6/2025.
//

#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include "DTUsuario.h"

#include "DTFecha.h"
#include <iostream>
using namespace std;

class DTVendedor:public DTUsuario{
public:
    string rut;
    DTVendedor();
    virtual ~DTVendedor();
    DTVendedor(string nick, string pass, DTFecha * fechaNac, string rut);
    string getRUT();
};



#endif //DTVENDEDOR_H
