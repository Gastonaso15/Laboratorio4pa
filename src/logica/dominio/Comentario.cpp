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
}

int Comentario::getId(){
  return this->id;
}

DTComentario * Comentario::retornarDTComentario(){
  DTComentario * dtc = new DTComentario(this->id,this->texto,this->fecEscrito);
  return dtc;
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

