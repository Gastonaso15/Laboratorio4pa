#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_

#include <iostream>
#include "../dominio/Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../DTs/DTCompra.h"
#include "../dominio/Vendedor.h"
#include "../dominio/Promocion.h"
#include "../dominio/Compra.h"
#include "../dominio/ProdComprado.h"
#include <map>
#include <set>
#include "../../DTs/DTPromocion.h"

using namespace std;

#include <string>


class SistemaControlador{
protected:
    static SistemaControlador* instancia;
    map<int,Producto*> productos;
    map<int,DTProducto*> carrito;
    map<string,Usuario*> usuarios;
    map<string,Promocion*> promociones;
    map<int, Compra*> compras;
    map<string, Vendedor*> vendedores;
    Vendedor* vendedorSeleccionado = nullptr;
    int ultimoCodigoProducto = 0;

public:
    SistemaControlador();
    virtual ~SistemaControlador();
    static SistemaControlador& getInstancia();
    string altaUsuario(DTUsuario * usuario);
    set<DTUsuario*> listarUsuarios();
    set<string> listarNickVendedor();
    string selectVendedor(string nick);
    bool ingProducto(DTProducto producto);
    set<DTProducto> listarProd();
    DTProducto* selectProd(int codigo);
    set<string> ingDatos(DTPromocion prom);
    set<DTProducto> seleccionarVendedor(string nick);
    string agregarProdProm(set<DTProducto> productosDT);
    set<DTProducto> obtenerProductosPendientesPorVendedor(string nickVendedor);
    set<DTCompra> seleccionarProducto(int codigoProducto);
    string marcarProductoComoEnviado(int codigoProducto, int idCompra);

};


#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
