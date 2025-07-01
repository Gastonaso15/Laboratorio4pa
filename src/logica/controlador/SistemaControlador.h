#ifndef LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
#define LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_
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
#include "../../DTs/DTPromocion.h"
#include <map>
#include <set>
#include <string>

class SistemaControlador{
protected:
	static SistemaControlador* instancia;
	SistemaControlador();

	map<int,Producto*> productos;
	map<int,DTProducto*> carrito;
	map<string,Usuario*> usuarios;
	map<string,Promocion*> promociones;
	map<int,Compra*> compras;
	map<string,Vendedor*> vendedores;

	Vendedor* vendedorSeleccionado = nullptr;
	Cliente* clienteSeleccionado = nullptr;
	Usuario* usuarioSeleccionado = nullptr;
	Producto* productoSeleccionado = nullptr;
	Comentario* comentarioSeleccionado = nullptr;
	Compra* compraActual=nullptr;
	Promocion* promocionActual = nullptr;

	int ultimoCodigoProducto = 0;
	int ultimoCodigoComentario = 0;
	int ultimoCodigoCompra = 0;
public:
	virtual ~SistemaControlador();
	static SistemaControlador& getInstancia();

	bool ingProducto(const DTProducto& producto);
	bool seleccionarProducto(int codigo);
	bool seleccionarComentario(int id);

	string altaUsuario(DTUsuario * usuario);
	string agregarProdProm(set<DTProdPromocion> productosDT);
	string agregarComentario(string texto);
	string agregarRespuesta(string texto);
	string borrarComentario(int id);
	string marcarProductoComoEnviado(int codigoProducto, int idCompra);
	string selectVendedor(string nick);
	string confirmarCompra();

	set<string> listarNicknamesUsuario();
	set<string> listarNickVendedor();
	set<string> listarClientes();
	set<string> ingDatos(DTPromocion prom);
	set<DTUsuario*> listarUsuarios();
	set<DTProducto> listarProd();
	set<DTProducto> seleccionarVendedor(string nick);
	set<DTPromocion*> listarPromociones();
	set<DTProdPromocion*> selectPromo(string nombre);
	set<DTProducto> seleccionarCliente(string nick);
	set<DTProducto> seleccionarUsuario(string nick);
	set<DTComentario*> listarComentario();
	set<DTProducto> obtenerProductosPendientesPorVendedor(string nickVendedor);
	set<DTCompra> seleccionarProductoC(int codigoProducto);
	set<DTComentario*> seleccionarUsuarioComentario(string nick);

	Producto *buscarProductoPorDT(const DTProducto* dtp);

	DTUsuario* seleccionarUsuarioExpediente(string nick);
	DTProducto* selectProd(int codigo);
	DTCompra * verDetalleCompra();

	void agregarProducto(DTProdComprado p);
	void auxBorrarComentarioRecursivo(Comentario* com, Usuario* usuario, Producto* producto);
	void cargarDatosPrueba();
};



#endif /* LOGICA_CONTROLADOR_SISTEMACONTROLADOR_H_ */
