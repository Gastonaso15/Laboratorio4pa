#include "Promocion.h"
#include "ProdPromocion.h"
#include "Producto.h"
#include "../../DTs/DTPromocion.h"
#include "../../DTs/DTProdPromocion.h"
#include "../../DTs/DTFecha.h"


Promocion::Promocion() {
}

Promocion::~Promocion() {
    delete fecVencimiento;
    for (auto& pp : prodsprom) {
        delete pp;
    }
    prodsprom.clear();
}

Promocion::Promocion(string nom, string desc, DTFecha * fecVencimiento) {
    this->nom = nom;
    this->desc = desc;
    this->fecVencimiento = fecVencimiento;
}

string Promocion::getNom() {
    return nom;
}

void Promocion::agregarProdProm(Producto* p, int cantMinima, int descuento) {
    ProdPromocion * prodprom = new ProdPromocion(cantMinima, descuento, p, this);
    this->prodsprom.insert(prodprom);
    p->agregarProdPromocion(prodprom);
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


