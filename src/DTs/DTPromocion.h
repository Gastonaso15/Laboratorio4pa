//
// Created by agusm on 12/06/2025.
//

#ifndef DTPROMOCION_H
#define DTPROMOCION_H
#include <string>

#include "DTFecha.h"




class DTPromocion {
public:
    string nom;
    string desc;
    DTFecha *fecVencimiento;
    DTPromocion();
    DTPromocion(string nom, string desc, DTFecha *fecVencimiento);
    DTPromocion getPromocion();
};



#endif //DTPROMOCION_H
