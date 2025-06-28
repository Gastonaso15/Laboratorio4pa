#include "Promocion.h"

Promocion::Promocion() {
}

Promocion::~Promocion() {}

Promocion::Promocion(string nom, string desc, DTFecha * fecVencimiento) {
    this->nom = nom;
    this->desc = desc;
    this->fecVencimiento = fecVencimiento;
}

string Promocion::getNom() {
    return nom;
}
// void Promocion::agregarProdProm(DTProducto p) {
//     //to do
// }
//
// DTPromocion Promocion::retornarDTPromocion() {
//     //to do
// }
//
// set<DTPromocion> Promocion::retornarDTProdPromocion(DTProdPromocion d) {
// //to do
// }
