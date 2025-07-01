#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Usuario.h"
#include "Producto.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTPromocion.h"
#include <map>
#include <set>

class ProdPromocion;
class DTProducto;
class Producto;
class Promocion;

class Vendedor: public Usuario {
protected:
    string rut;

    map<int, Producto*> productos;
    map<string,Promocion*> promociones;
public:
    Vendedor();
    Vendedor(string nick, string pass, DTFecha *  fechaNac,string rut);
    ~Vendedor();

    void aniadirProdListaVendedor(Producto * producto);
    void agregarPromocion(Promocion* promo);

    string getNickname() const;
    string getRut()const;

    DTUsuario* retornarDTUsuario() const override;

    set<Promocion*> retornarPromociones();
    set<DTPromocion*> getPromocion();
    set<DTProducto*> retornarProductos();

};
#endif //VENDEDOR_H
