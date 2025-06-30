#include "DTPromocion.h"

DTPromocion::DTPromocion() {

}

DTPromocion::~DTPromocion(){}

DTPromocion::DTPromocion(string nom, string desc, DTFecha *fecVencimiento) {
    this->nom = nom;
    this->desc = desc;
    this->fecVencimiento = fecVencimiento;
}

DTPromocion::DTPromocion(string nom, string desc, DTFecha *fecVencimiento, set<DTProdPromocion*> prodsprom) {
    this->nom = nom;
    this->desc = desc;
    this->fecVencimiento = fecVencimiento;
    this->prodsprom = prodsprom;
}

DTPromocion DTPromocion::getPromocion() {
    return DTPromocion(this->nom, this->desc, this->fecVencimiento);
}

bool DTPromocion::operator<(const DTPromocion& other) const {
    return this->nom < other.nom;
}

string DTPromocion::obtenerInfo() const {
    return "Nombre: " + nom + "\nDescripcion: " + desc + "\nFecha de Vencimiento: " + fecVencimiento->toString();
}