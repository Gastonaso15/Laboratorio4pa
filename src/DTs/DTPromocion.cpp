
#include "DTPromocion.h"

DTPromocion::DTPromocion() {
}

DTPromocion::DTPromocion(string nom, string desc, DTFecha *fecVencimiento) {
    this->nom = nom;
    this->desc = desc;
    this->fecVencimiento = fecVencimiento;
}

DTPromocion DTPromocion::getPromocion() {
    return DTPromocion(this->nom, this->desc, this->fecVencimiento);
}
