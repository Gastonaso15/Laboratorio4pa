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

DTPromocion * Promocion::retornarDTPromocion() {
   return new DTPromocion(this->nom,this->desc,this->fecVencimiento);
}

DTPromocion * Promocion::retornarDTPromocionConProd() {
    set<DTProdPromocion*> dtprods;
    for (ProdPromocion* p : this->prodsprom) {
        dtprods.insert(new DTProdPromocion(p->retornarDTProdPromocion()));
    }
    return new DTPromocion(this->nom,this->desc,this->fecVencimiento,dtprods);
}

set<DTProdPromocion*> Promocion::retornarDTProdPromocion() {
    set<DTProdPromocion*> dtprods;
    for (ProdPromocion* p : this->prodsprom) {
        dtprods.insert(new DTProdPromocion(p->retornarDTProdPromocion()));
    }
    return dtprods;
}


