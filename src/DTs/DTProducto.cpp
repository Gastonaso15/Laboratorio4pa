
#include "DTProducto.h"
#include "../../DTs/Definiciones.h"
#include <iostream>
using namespace std;

DTProducto::~DTProducto(){}
DTProducto::DTProducto(){}
DTProducto::DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria)
    : codigo(codigo), nombre(nombre), precio(precio), stock(stock), descripcion(descripcion), categoria(categoria){
    //por que la declaracion esta asi?
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    this->descripcion = descripcion;
    this->categoria = categoria;
}

bool DTProducto::operator<(const DTProducto& other) const {
    return codigo < other.codigo; // o lo que uses como clave única
}

DTProducto::DTProducto(int codigo, string nombre, int precio, int stock, string descripcion, cat categoria,DTVendedor * vendedor) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->vendedor = vendedor;
}

string DTProducto::catToString(cat categoria) {
    switch (categoria) {
        case Electrodomestico: return "Electrodomestico";
        case Ropa: return "Ropa";
        case Otro: return "Otro";
        default: return "Categoria desconocida";
    }
}