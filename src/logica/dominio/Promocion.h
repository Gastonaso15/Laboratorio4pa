
#ifndef PROMOCION_H
#define PROMOCION_H
#include <set>
#include "string"
using namespace std;
#include "../DTs/DTFecha.h"
#include "../../DTs/DTPromocion.h"
#include "../../DTs/DTProdPromocion.h"


class Vendedor;
class Producto;
class ProdPromocion;


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
    void agregarProdProm(Producto* p, int cantMinima, int descuento);
    DTPromocion * retornarDTPromocion();
    DTPromocion * retornarDTPromocionConProd();
    set<DTProdPromocion*> retornarDTProdPromocion();
    bool estaVigente();

};



#endif //PROMOCION_H
