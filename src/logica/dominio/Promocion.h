
#ifndef PROMOCION_H
#define PROMOCION_H
#include <set>
#include "string"
using namespace std;
#include "../../DTs/DTProdPromocion.h"
#include "../../DTs/DTPromocion.h"
#include "../../DTs/DTProducto.h"
#include "../DTs/DTFecha.h"
#include "ProdPromocion.h"

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
    void agregarProdProm(const DTProducto& p);
    DTPromocion retornarDTPromocion();
    set<DTPromocion> retornarDTProdPromocion(DTProdPromocion d);
    bool estaVigente();

};



#endif //PROMOCION_H
