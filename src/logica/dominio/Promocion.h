//
// Created by Gastón on 27/6/2025.
//

#ifndef PROMOCION_H
#define PROMOCION_H
#include <set>

#include "../../DTs/DTProdPromocion.h"
#include "../../DTs/DTProducto.h"
#include "../../DTs/DTPromocion.h"
#include "../DTs/DTFecha.h"



class Promocion {
private:
    string nom;
    string desc;
    DTFecha fecVencimiento;
public:
    Promocion();
    Promocion(string nom, string desc, DTFecha fecVencimiento);
    void agregarProdProm(DTProducto p);
    DTPromocion retornarDTPromocion();
    set<DTPromocion> retornarDTProdPromocion(DTProdPromocion d);
};



#endif //PROMOCION_H
