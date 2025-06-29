#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#include "../dominio/Producto.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTComentario.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../DTs/DTCompra.h"
#include "../dominio/Vendedor.h"
#include "../dominio/Promocion.h"
#include "../dominio/Compra.h"
#include <map>
#include <set>
#include "../../DTs/DTPromocion.h"
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

	void agregarProducto(DTProducto p);

	bool ingProducto(const DTProducto& producto);
	bool seleccionarProducto(int codigo);
	bool seleccionarComentario(int id);

	string agregarComentario(string texto);
	string selectVendedor(string nick);
	string altaUsuario(DTUsuario * usuario);
	string agregarRespuesta(string texto);
	string borrarComentario(int id);
	string marcarProductoComoEnviado(int codigoProducto, int idCompra);
	string agregarProdProm(set<DTProdPromocion> productosDT);

	set<DTComentario*> listarComentario();
	set<DTUsuario*> listarUsuarios();
	set<string> listarNickVendedor();
	set<DTProducto> listarProd();
	set<string> ingDatos(DTPromocion prom);
	set<DTProducto> seleccionarVendedor(string nick);
	set<DTPromocion*> listarPromociones();
	set<DTProdPromocion*> selectPromo(string nombre);
	set<string> listarClientes();
	set<DTProducto> seleccionarCliente(DTCliente cliente);
	set<string> listarNicknamesUsuario();
	set<DTProducto> seleccionarUsuario(string nick);
	set<DTProducto> obtenerProductosPendientesPorVendedor(string nickVendedor);
	set<DTCompra> seleccionarProductoC(int codigoProducto);
	set<DTComentario*> seleccionarUsuarioComentario(string nick);

	DTProducto* selectProd(int codigo);
};


#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
