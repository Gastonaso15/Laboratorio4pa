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
void Promocion::agregarProdProm(const DTProducto& p) {
    ProdPromocion * prodprom = new ProdPromocion(p.precio,p.stock);
    prodsprom.insert(prodprom);
}

bool Promocion::estaVigente() {
    DTFecha hoy =  DTFecha::obtenerFechaActual();
    if (hoy <= *fecVencimiento) {
        return true;
    }else {
        return false;
    }
}

DTPromocion Promocion::retornarDTPromocion() {
   return DTPromocion(this->nom,this->desc,this->fecVencimiento);
}

// set<DTPromocion> Promocion::retornarDTProdPromocion(DTProdPromocion d) {
// //to do
// }
