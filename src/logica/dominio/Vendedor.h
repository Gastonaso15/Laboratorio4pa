#ifndef VENDEDOR_H
#define VENDEDOR_H
#include "Usuario.h"
#include "Producto.h"
#include "../DTs/DTProducto.h"
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
    string getNick() const;
    void aniadirProdListaVendedor(Producto * producto);
    set<DTProducto> retornarProductos();
    DTUsuario* retornarDTUsuario() const override;

};
#endif //VENDEDOR_H
