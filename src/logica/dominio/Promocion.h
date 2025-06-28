
#ifndef PROMOCION_H
#define PROMOCION_H
#include <set>
#include "string"
using namespace std;
#include "../../DTs/DTProdPromocion.h"
#include "../../DTs/DTPromocion.h"

class Vendedor;
class ProdPromocion;
class DTProducto;

class Promocion {
private:
    string nom;
    string desc;
    DTFecha * fecVencimiento;
    Vendedor * vendedor;
    set<ProdPromocion*> prodsprom;
public:
    Promocion();
    Promocion(string nom, string desc, DTFecha *fecVencimiento);
    virtual ~Promocion();
    string getNom();
    void agregarProdProm(DTProducto p);
    DTPromocion retornarDTPromocion();
    set<DTPromocion> retornarDTProdPromocion(DTProdPromocion d);
};



#endif //PROMOCION_H
