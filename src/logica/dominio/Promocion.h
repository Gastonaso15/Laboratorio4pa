#ifndef PROMOCION_H
#define PROMOCION_H
#include <set>
#include "string"
#include "../DTs/DTFecha.h"
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

    void agregarProdProm(Producto* p, int cantMinima, int descuento);
    void setVendedor(Vendedor* v);

    bool estaVigente();

    DTPromocion * retornarDTPromocion();
    DTPromocion * retornarDTPromocionConProd();

    string getNom();

    set<DTProdPromocion*> retornarDTProdPromocion();
};



#endif //PROMOCION_H
