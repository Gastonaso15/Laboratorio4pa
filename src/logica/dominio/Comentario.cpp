#include "Comentario.h"
#include <iostream>
using namespace std;

Comentario::Comentario(){}

Comentario::~Comentario(){

}

Comentario::Comentario(int id, string texto, DTFecha * fecEscrito,Producto * producto){
  this->id = id;
  this->texto = texto;
  this->fecEscrito = fecEscrito;
  this->producto = producto;
  this->padre=nullptr;
}

Comentario::Comentario(int id, string texto, DTFecha * fecEscrito,Producto * producto,Comentario * padre){
  this->id = id;
  this->texto = texto;
  this->fecEscrito = fecEscrito;
  this->producto = producto;
  this->padre = padre;
}

int Comentario::getId(){
  return this->id;
}

DTComentario * Comentario::retornarDTComentario(){
  DTComentario * dtPadre = nullptr;
  if (this->padre != nullptr) {
    dtPadre = this->padre->retornarDTComentario();
  }
  DTComentario * dtc = new DTComentario(this->id,this->texto,this->fecEscrito,dtPadre);
  return dtc;
}

DTComentario * Comentario::retornarDTComentarioPadre(){
  if (this->padre != nullptr) {
    return this->padre->retornarDTComentario();
  }
  return nullptr;
}

void Comentario::agregarRespuesta(Comentario * com){
  this->respuestas[com->getId()] = com;
}

bool Comentario::tieneRespuestas() {
  if (respuestas.empty()) {
    return false;
  }else {
    return true;
  }
}

Producto* Comentario::getProducto() {
  return this->producto;
}

map<int,Comentario*>& Comentario::getRespuestas() {
  return respuestas;
}