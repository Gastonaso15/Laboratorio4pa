
#include "DTProducto.h"
#include <iostream>
using namespace std;

DTProducto::~DTProducto(){}
DTProducto::DTProducto(){}
DTProducto::DTProducto(int codigo, string nombre, int precio,int stock, string descripcion, cat categoria){
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
    this->stock = stock;
    this->descripcion = descripcion;
    this->categoria = categoria;
}