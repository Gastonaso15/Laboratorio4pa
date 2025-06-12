//
// Created by marti on 12/6/2025.
//

#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include "DTUsuario.h"

class DTVendedor::public DTUsuario{
private:
    string RUT;
public:
    DTVendedor();
    virtual DTVendedor();
    DTVendedor(string nick, string contrasenia, DTFECHA * fecha, string RUT);
    string getRUT();
};



#endif //DTVENDEDOR_H
