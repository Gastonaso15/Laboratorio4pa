#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_

#include <iostream>
#include "../dominio/Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProdComprado.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTComentario.h"
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
	SistemaControlador();
	map<int,Producto*> productos;
	map<int,DTProducto*> carrito;
	map<string,Usuario*> usuarios;
	map<string,Promocion*> promociones;
	map<int, Compra*> compras;
	map<string, Vendedor*> vendedores;
	Vendedor* vendedorSeleccionado = nullptr;
	Cliente* clienteSeleccionado = nullptr;
	Usuario* usuarioSeleccionado = nullptr;
	Producto* productoSeleccionado = nullptr;
	Comentario* comentarioSeleccionado = nullptr;
	Compra* compraActual;
	int ultimoCodigoProducto = 0;
	int ultimoCodigoComentario = 0;
public:
	virtual ~SistemaControlador();
	static SistemaControlador& getInstancia();
	string altaUsuario(DTUsuario * usuario);
	set<DTUsuario*> listarUsuarios();
	set<string> listarNickVendedor();
	string selectVendedor(string nick);

	Producto *buscarProductoPorDT(const DTProducto* dtp);

	bool ingProducto(const DTProducto& producto);
	set<DTProducto> listarProd();
	DTProducto* selectProd(int codigo);
	set<string> ingDatos(DTPromocion prom);
	set<DTProducto> seleccionarVendedor(string nick);
	string agregarProdProm(set<DTProdPromocion> productosDT);
	set<DTPromocion*> listarPromociones();
	set<DTProdPromocion*> selectPromo(string nombre);
	set<string> listarClientes();
	set<DTProducto> seleccionarCliente(string nick);
	void agregarProducto(DTProdComprado p);

	DTCompra * verDetalleCompra();

	set<string> listarNicknamesUsuario();
	set<DTProducto> seleccionarUsuario(string nick);
	bool seleccionarProducto(int codigo);
	string agregarComentario(string texto);
	set<DTComentario*> listarComentario();
	bool seleccionarComentario(int id);
	string agregarRespuesta(string texto);
	set<DTComentario*> seleccionarUsuarioComentario(string nick);
	string borrarComentario(int id);
	void auxBorrarComentarioRecursivo(Comentario* com, Usuario* usuario, Producto* producto);
	set<DTProducto> obtenerProductosPendientesPorVendedor(string nickVendedor);
	set<DTCompra> seleccionarProductoC(int codigoProducto);
	string marcarProductoComoEnviado(int codigoProducto, int idCompra);
	string confirmarCompra();
	//void cargarDatosPrueba();
};



#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
