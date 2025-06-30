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

    bool operator<(const DTPromocion& other) const;
    DTFecha *fecVencimiento;
    set<DTProdPromocion*> prodsprom;
    DTPromocion();
    ~DTPromocion();
    DTPromocion(string nom, string desc, DTFecha *fecVencimiento);
    DTPromocion(string nom, string desc, DTFecha *fecVencimiento, set<DTProdPromocion*> prodsprom);
    DTPromocion getPromocion();
};




#endif //DTPROMOCION_H
