#include "SistemaControlador.h"
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "../dominio/Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include "../dominio/Promocion.h"
#include "../dominio/Compra.h"
#include "../dominio/Comentario.h"
#include "../dominio/ProdComprado.h"
#include <map>
#include "../presentacion/EnviarProducto.h"



set<Promocion*> promociones;
Promocion* promocionActual = nullptr;
SistemaControlador* SistemaControlador::instancia = nullptr;

SistemaControlador::SistemaControlador() {}

SistemaControlador::~SistemaControlador() {
    for (auto& par : usuarios) {
        delete par.second;
    }
    usuarios.clear();
    for (auto& par : productos) {
        delete par.second;
    }
    productos.clear();
    for (auto& par : promociones) {
        delete par.second;
    }
    promociones.clear();
}

SistemaControlador& SistemaControlador::getInstancia() {
    if (instancia == nullptr) {
        instancia = new SistemaControlador();
    }
    return *instancia;
}

string SistemaControlador::altaUsuario(DTUsuario* usuario) {
    Usuario* nuevoUsuario = nullptr;
    string respuesta;
    if (DTCliente* dtoCli = dynamic_cast<DTCliente*>(usuario)) {
        DTFecha* fechaNac = new DTFecha(*dtoCli->fechaNac);  // copia por valor

        nuevoUsuario = new Cliente(
            dtoCli->nick,
            dtoCli->pass,
            fechaNac,
            dtoCli->direccion,
            dtoCli->ciudad
        );

    } else if (DTVendedor* dtoVen = dynamic_cast<DTVendedor*>(usuario)) {
        DTFecha* fechaNac = new DTFecha(*dtoVen->fechaNac);  // copia por valor

        nuevoUsuario = new Vendedor(
            dtoVen->nick,
            dtoVen->pass,
            fechaNac,
            dtoVen->rut
        );
    }

    if (nuevoUsuario != nullptr) {
        string nick = usuario->nick;
        if (usuarios.find(nick) == usuarios.end()) {
            usuarios[nick] = nuevoUsuario;
            respuesta="Alta Usuario realizada con exito";
        } else {
            delete nuevoUsuario;
            respuesta="El usuario con ese nick ya existe.";
        }
    } else {
        respuesta="Tipo de usuario desconocido.";
    }
    return respuesta;
}

set<string> SistemaControlador::listarNickVendedor() {
    set <string> nicks;
    for (auto& par : usuarios) {
        Usuario* u = par.second;
        Vendedor* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) {
            nicks.insert(v->getNickname());
        }
    }
    return nicks;
}

set<DTUsuario*> SistemaControlador::listarUsuarios() {
    set<DTUsuario*> resultado;
    for (auto const& par: usuarios){
        Usuario* usuario = par.second;
        resultado.insert(usuario->retornarDTUsuario());
    }
    return resultado;
}

string SistemaControlador::selectVendedor(string nick) {
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        Vendedor* v = dynamic_cast<Vendedor*>(it->second);
        if (v != nullptr) {
            vendedorSeleccionado = v;
            return "Vendedor " + nick + " seleccionado correctamente.";
        } else {
            return "Error: El usuario no es un vendedor.";
        }
    } else {
        return "Error: No se encontro un usuario con ese nick.";
    }
}

Producto* SistemaControlador::buscarProductoPorDT(const DTProducto dtp) {
    auto it = productos.find(dtp.codigo);
    if (it != productos.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

bool SistemaControlador::ingProducto(const DTProducto& producto) {
    int cod = ++ultimoCodigoProducto;
    Producto * prod = new Producto(cod, producto.nombre, producto.precio, producto.stock, producto.descripcion, producto.categoria);
    prod->asociarProdVendedor(vendedorSeleccionado);
    //En los diagramas se pasa solo el nick, pero es mejor pasarle el puntero para evitar porblemas
    vendedorSeleccionado->aniadirProdListaVendedor(prod);
    int codigo = prod->getCodigo();
    auto result = productos.insert({codigo, prod});
    return result.second; // true si se insertó, false si ya existía --- Siempre va a dar true porque el codigo siempre es diferente
}

set<DTProducto> SistemaControlador::listarProd() {
    set<DTProducto> resultado;
    for (const auto& par : productos) {
        Producto* p = par.second;
        DTProducto dto = p->retornarDTProducto();
        resultado.insert(dto);
    }

    return resultado;
}

DTProducto* SistemaControlador::selectProd(int codigo) {
    //En los diagramas ingresa DTProducto, pero es mas comodo con int
    auto it = productos.find(codigo);
    if (it != productos.end()) {
        Producto* prod = it->second;
        return new DTProducto(prod->retornarDTProducto());
    } else {
        return nullptr;
    }
}

set<string> SistemaControlador::ingDatos(DTPromocion prom) {
    Promocion* nuevaPromo = new Promocion(prom.nom, prom.desc, prom.fecVencimiento);
    promocionActual = nuevaPromo;
    this->promociones[nuevaPromo->getNom()] = nuevaPromo;
    set<string> nicks=listarNickVendedor();
    return nicks;
}

set<DTProducto> SistemaControlador::seleccionarVendedor(string nick) {
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        Vendedor* v = dynamic_cast<Vendedor*>(it->second);
        if (v != nullptr) {
            vendedorSeleccionado = v;
            set<DTProducto> productosVendedor;
            for (const auto& p : v->retornarProductos()) {
                productosVendedor.insert(p);
            }
            return productosVendedor;
        }
    }
    return set<DTProducto>();  // Retorna set vacío si no encuentra el vendedor
}

string SistemaControlador::agregarProdProm(set<DTProdPromocion> productosDT) {
    for (const DTProdPromocion& dtPromo : productosDT) {
        auto it = productos.find(dtPromo.producto.codigo);
        if (it != productos.end()) {
            Producto* prod = it->second;
            if (!prod->productoEnPromo()) {
                promocionActual->agregarProdProm(prod, dtPromo.cantMinima, dtPromo.descuento);
            }else {
                return "Error: El producto ya se encuentra en otra Promocion";
            }
        } else {
            return "Error: No existe el Producto seleccionado";
        }
    }
    return "Promocion creada con exito";
}
set<string> SistemaControlador::listarClientes() {
    set<string> nicksClientes;
    for (const auto& par : usuarios) {
        if (dynamic_cast<Cliente*>(par.second) != nullptr) {
            nicksClientes.insert(par.first);
        }
    }
    return nicksClientes;
}

set<DTPromocion*> SistemaControlador::listarPromociones() {
    set<DTPromocion*> resultado;
    for (auto const& par : this->promociones) {
        Promocion* p = par.second;
        if (p->estaVigente()) {
            resultado.insert(p->retornarDTPromocion());
        }
    }
    return resultado;
}

set<DTProdPromocion*> SistemaControlador::selectPromo(string nombre) {
    auto it = promociones.find(nombre);
    if (it != promociones.end()) {
        Promocion* prom = it->second;
        return prom->retornarDTProdPromocion();
    } else {
        return {};
    }
}

set<DTProducto> SistemaControlador::seleccionarCliente(DTCliente cliente) {
    // Limpiar seleccion previa
    clienteSeleccionado = nullptr;
    delete compraActual;
    compraActual = nullptr;

    auto it = usuarios.find(cliente.nick);
    if (it == usuarios.end()) {
        throw runtime_error("Usuario no encontrado");
    }
    set<DTProducto> productosDisponibles;
    for (const auto& prod : productos) {
        Producto* p = prod.second;
        productosDisponibles.insert(p->retornarDTProducto());
    }
    return productosDisponibles;
}

void SistemaControlador::agregarProducto(DTProducto p) {
    if (clienteSeleccionado == nullptr) {
        throw runtime_error("No hay cliente seleccionado");
    }
    auto it = productos.find(p.codigo);
    if (compraActual == nullptr) {
        compraActual = new Compra();
    }
    compraActual->agregoProd(p);
}

// DTCompra SistemaControlador::verDetalleCompra(int idCompra) {
//     DTCompra detalle;
//
//     // Buscar la compra
//     auto it = compraActual.find()
//     if (compraIt == compras.end()) {
//         throw std::runtime_error("Compra no encontrada");
//     }
// }

set<string> SistemaControlador::listarNicknamesUsuario() {
    set<string> resultado;
    for (auto const& par: usuarios){
        Usuario* usuario = par.second;
        resultado.insert(usuario->getNickname());
    }
    return resultado;
}

set<DTProducto> SistemaControlador::seleccionarUsuario(string nick) {
    set<DTProducto> prods;
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        usuarioSeleccionado= it->second;
        for (const auto& prod : productos) {
            Producto* p = prod.second;
            prods.insert(p->retornarDTProducto());
        }
        return prods;
    }
    return prods;  // Retorna set vacío si no encuentra al usuario
}

bool SistemaControlador::seleccionarProducto(int codigo) {
    auto it = productos.find(codigo);
    if (it != productos.end()) {
        productoSeleccionado = it->second;
        return true;
    }
    return false;
}

string SistemaControlador::agregarComentario(string texto) {
    if (this->usuarioSeleccionado == nullptr) {
        return "Error: No hay usuario seleccionado.";
    }
    if (this->productoSeleccionado == nullptr) {
        return "Error: No hay producto seleccionado.";
    }
    int id = ++ultimoCodigoComentario;
    DTFecha* fechaActual = new DTFecha(DTFecha::obtenerFechaActual());
    Comentario * com = new Comentario(id,texto,fechaActual,productoSeleccionado);
    usuarioSeleccionado->asociarComentarioUsuario(com);
    productoSeleccionado->asociarComentarioProducto(com);
    return "Comentario creado con exito";
}

set<DTComentario*> SistemaControlador::listarComentario() {
    set<DTComentario*> resultado;
    if (this->productoSeleccionado == nullptr) {
        return resultado;
    }
    resultado=productoSeleccionado->getComentarios();
    return resultado;
}

bool SistemaControlador::seleccionarComentario(int id) {
    comentarioSeleccionado = this->productoSeleccionado->getComentario(id);
    if (this->comentarioSeleccionado == nullptr) {
        return false;
    }
    return true;
}

string SistemaControlador::agregarRespuesta(string texto) {
    if (this->productoSeleccionado == nullptr) {
        return "Error: No hay producto seleccionado.";
    }
    int id = ++ultimoCodigoComentario;
    DTFecha* fechaActual = new DTFecha(DTFecha::obtenerFechaActual());
    Comentario * com = new Comentario(id,texto,fechaActual,productoSeleccionado,comentarioSeleccionado);
    comentarioSeleccionado->agregarRespuesta(com);
    usuarioSeleccionado->asociarComentarioUsuario(com);
    productoSeleccionado->asociarComentarioProducto(com);
    return "Respuesta creada con exito";
}

set<DTComentario*> SistemaControlador::seleccionarUsuarioComentario(string nick) {
    set<DTComentario*> resultado;
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        usuarioSeleccionado= it->second;
        resultado=usuarioSeleccionado->getComentarios();
        return resultado;
    }
    return resultado;  // Retorna set vacío si no encuentra al usuario
}

void SistemaControlador::auxBorrarComentarioRecursivo(Comentario* com, Usuario* usuario, Producto* producto) {
    for (auto& par : com->getRespuestas()) {
        auxBorrarComentarioRecursivo(par.second, usuario, producto);
    }
    usuario->eliminarComentario(com->getId());
    producto->eliminarComentario(com->getId());
    delete com;
}

string SistemaControlador::borrarComentario(int id) {
    Comentario* com = usuarioSeleccionado->obtenerComentario(id);
    if (com == nullptr) {
        return "Error: No existe un comentario con ese ID";
    }
    Producto* prod = com->getProducto();
    auxBorrarComentarioRecursivo(com, usuarioSeleccionado, prod);
    return "Comentario borrado con exito";
}

set<DTCompra> SistemaControlador::seleccionarProductoC(int codigoProducto) {
    set<DTCompra> resultado;

    for (const auto& par : compras) {
        Compra* compra = par.second;
        for (ProdComprado* pc : compra->getProdComprado()) {
            if (pc->getProducto()->getCodigo() == codigoProducto && !pc->getEnviado()) {
                resultado.insert(compra->toDT()); // Asume que Compra tiene un método toDT()
            }
        }
    }
    return resultado;
}

string SistemaControlador::marcarProductoComoEnviado(int codigoProducto, int idCompra) {
    auto itCompra = compras.find(idCompra);
    if (itCompra != compras.end()) {
        Compra* compra = itCompra->second;
        for (ProdComprado* pc : compra->getProdComprado()) {
            if (pc->getProducto()->getCodigo() == codigoProducto && !pc->getEnviado()) {
                pc->setEnviado(true);
                return "Producto marcado como enviado correctamente en la compra " + to_string(idCompra) + ".";
            }
        }
        return "Error: El producto no se encontró pendiente de envío en la compra seleccionada.";
    }
    return "Error: No se encontró la compra con el ID especificado.";
}

set<DTProducto> SistemaControlador::obtenerProductosPendientesPorVendedor(string nickVendedor) {
    set<DTProducto> resultado;
    return resultado;
}