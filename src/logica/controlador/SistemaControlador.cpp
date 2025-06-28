#include "SistemaControlador.h"
#include <iostream>
#include <string>
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
#include <map>
#include <stdexcept>

using namespace std;
set<Vendedor*> vendedores;
set<Promocion*> promociones;
Promocion* promocionActual = nullptr;

SistemaControlador::SistemaControlador() {}

SistemaControlador::~SistemaControlador() {
    // Liberar memoria de los usuarios
    for (auto& par : usuarios) {
        delete par.second;
    }
    usuarios.clear();
}

string SistemaControlador::altaUsuario(DTUsuario* usuario) { //cambiar a string
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
    return respuesta;  // <<--- esto te faltaba
}

set<string> SistemaControlador::listarNickVendedor() {
    set <string> nicks;
    for (auto& par : usuarios) {
        Usuario* u = par.second;
        Vendedor* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) {
            nicks.insert(v->getNick());
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


bool SistemaControlador::ingProducto(DTProducto producto) {
    int cod = ++ultimoCodigoProducto;
    Producto * prod = new Producto(cod, producto.nombre, producto.precio, producto.stock, producto.descripcion, producto.categoria);
    //dynamic_cast<Producto*>(vendedorSeleccionado)->asociarProdVendedor(vendedorSeleccionado); Por que el cast?
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
    promociones.insert({nuevaPromo->getNom(), nuevaPromo});
    set<string> nicks;
    for (const auto& v : vendedores) {
        nicks.insert(v.second->getNick());
    }
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
/*
bool SistemaControlador::agregarProdProm(const set<DTProducto>& productosDT) {
    for (const auto& p : productosDT) {}
    auto it = productos.find(nick);
    bool todosAgregados = true;

    // Recorrer cada producto a agregar
    for (const auto& dtProd : productosDT) {
        // Buscar el producto real en el vendedor
        Producto* producto = vendedorSeleccionado->buscarProducto(dtProd.codigo);

        if (producto != nullptr) {
            // Intentar agregar a la promoción (asumiendo cantidad mínima y descuento por defecto)
            if (!promocionActual->agregarProducto(producto, 1, 0.0f)) { // 1 unidad mínima, 0% descuento por defecto
                todosAgregados = false;
            }
        } else {
            todosAgregados = false;
        }
    }

    return todosAgregados;
}
*/