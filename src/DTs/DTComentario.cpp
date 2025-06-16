#include "DTComentario.h"
#include <iostream>
#include "DTFecha.h"
using namespace std;

DTComentario::DTComentario();{

}


DTComentario::DTComentario(int id, string texto, DTFecha fecEscrito){
  this->id=id;
  this->texto=texto;
  this->fecEscrito=fecEscrito;
  }
DTComentario::~DTComentario() {

}
void DTComentario::borrarRespuesta() {

}