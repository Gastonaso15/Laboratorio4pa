#include "DTComentario.h"
#include <iostream>
#include "DTFecha.h"
using namespace std;

DTComentario::DTComentario(){

}

DTComentario::DTComentario(int id, string texto, DTFecha* fecEscrito){
  this->id=id;
  this->texto=texto;
  this->fecEscrito=fecEscrito;
}

DTComentario::DTComentario(int id, string texto, DTFecha* fecEscrito, DTComentario * padre){
  this->id=id;
  this->texto=texto;
  this->fecEscrito=fecEscrito;
  this->padre=padre;
}

DTComentario::~DTComentario() {

}

void DTComentario::borrarRespuesta() {

}