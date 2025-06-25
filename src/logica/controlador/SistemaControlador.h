#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#include <iostream>
#include "dominio/Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include <map>
#include <set>
using namespace std;

#include <string>

class SistemaControlador{
protected:
	map<int,Producto*> productos;
	map<int,DTProducto*>carrito;
	map<string,Usuario*> usuarios;
	map<string, Vendedor*> vendedores;
	Vendedor* vendedorSeleccionado = nullptr;
public:
	SistemaControlador();
	virtual ~SistemaControlador();
	string altaUsuario(DTUsuario * usuario);
	set<DTUsuario*> listarUsuarios();
	set<string> listarNickVendedor();
	string selectVendedor(string nick);
	bool ingProducto(DTProducto producto);
	set<DTProducto> listarProd();
};


#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
