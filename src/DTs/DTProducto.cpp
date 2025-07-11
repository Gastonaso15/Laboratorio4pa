#include "DTProducto.h"
#include "../../DTs/Definiciones.h"
#include "DTVendedor.h"
#include <iostream>
using namespace std;

DTProducto::~DTProducto() {

}

DTProducto::DTProducto() {
    this->vendedor = nullptr;
}

int DTProducto::getCodDTProd() const {
    return this->codigo;
}

DTProducto::DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria){
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    this->descripcion = descripcion;
    this->categoria = categoria;
}

ostream& operator<<(std::ostream& os, const DTProducto& dtProducto) {
    os  << "Codigo: " << dtProducto.codigo << endl
        << "Nombre: " << dtProducto.nombre << endl
        << "Descripcion: " << dtProducto.descripcion << endl
        << "Precio: $" << dtProducto.precio << endl;
    return os;
}

bool DTProducto::operator<(const DTProducto& other) const {
    return codigo < other.codigo;
}

DTProducto::DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria, DTVendedor * vendedor)
    : codigo(codigo), nombre(nombre), precio(precio), stock(stock), descripcion(descripcion), categoria(categoria) {
    if (vendedor != nullptr) {
        this->vendedor = new DTVendedor(*vendedor);
    } else {
        this->vendedor = nullptr;
    }
}


string DTProducto::getNombreDTProd() {
    return this->nombre;
}

string DTProducto::catToString(cat categoria) {
    switch (categoria) {
        case Electrodomestico: return "Electrodomestico";
        case Ropa: return "Ropa";
        case Otro: return "Otro";
        default: return "Categoria desconocida";
    }
}

DTProducto::DTProducto(int codigo, int descuento, int cantidad) {
    this->codigo = codigo;
    this->precio = descuento;
    this->stock = cantidad;
}

DTProducto::DTProducto(const DTProducto& other)
    : codigo(other.codigo), nombre(other.nombre), precio(other.precio),
      stock(other.stock), descripcion(other.descripcion), categoria(other.categoria) {
    if (other.vendedor != nullptr) {
        this->vendedor = new DTVendedor(*other.vendedor);
    } else {
        this->vendedor = nullptr;
    }
}

DTProducto& DTProducto::operator=(const DTProducto& other) {
    if (this != &other) {
        delete this->vendedor;
        this->codigo = other.codigo;
        this->nombre = other.nombre;
        this->precio = other.precio;
        this->stock = other.stock;
        this->descripcion = other.descripcion;
        this->categoria = other.categoria;
        if (other.vendedor != nullptr) {
            this->vendedor = new DTVendedor(*other.vendedor);
        } else {
            this->vendedor = nullptr;
        }
    }
    return *this;
}