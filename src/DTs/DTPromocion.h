#ifndef DTPROMOCION_H
#define DTPROMOCION_H
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTProdPromocion.h"


class DTPromocion {
public:
    string nom;
    string desc;
    string obtenerInfo() const;
    DTFecha *fecVencimiento;

    set<DTProdPromocion*> prodsprom;
    //--------------------------------------------------------------------------------------------------------------------
    DTPromocion();
    DTPromocion(string nom, string desc, DTFecha *fecVencimiento);
    DTPromocion(string nom, string desc, DTFecha *fecVencimiento, set<DTProdPromocion*> prodsprom);
    ~DTPromocion();

    bool estaVigente();

    DTPromocion getPromocion();

    bool operator<(const DTPromocion& other) const;
};




#endif //DTPROMOCION_H
