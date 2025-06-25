#include "SistemaControlador.h"
#include <iostream>
#include <string>
#include "dominio/Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include <map>
#include <stdexcept>

using namespace std;

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

set<DTProducto> SistemaControlador::listarProd() {
    set<DTProducto> resultado;
    for (const auto& par : productos) {
        Producto* p = par.second;
        DTProducto dto = p->retornarDTProducto();
        resultado.insert(dto);
    }

    return resultado;
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
    auto it = vendedores.find(nick);
    if (it != vendedores.end()) {
        vendedorSeleccionado = it->second;
        return "Vendedor " + nick + " seleccionado correctamente.";
    } else {
        return "Error: No se encontro un vendedor con nickname '" + nick + "'.";
    }
}

bool SistemaControlador::ingProducto(DTProducto producto) {
  Producto * prod = new Producto(producto.codigo, producto.nombre, producto.precio, producto.stock, producto.descripcion, producto.categoria);
    dynamic_cast<Producto*>(vendedorSeleccionado)->asociarProdVendedor(vendedorSeleccionado->getNick());
    int codigo = prod->getCodigo();
    auto result = productos.insert({codigo, prod});
    return result.second; // true si se insertó, false si ya existía
} // YO ME QUEDE ACA CON ESTA FUNCION NO SE SI FUNCA PERO ES LO QUE SALIO



