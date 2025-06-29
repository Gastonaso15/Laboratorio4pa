#include "Comentario.h"
#include <iostream>
using namespace std;

Comentario::Comentario(){}

Comentario::~Comentario(){

}

Comentario::Comentario(int id, string texto, DTFecha * fecEscrito){
  this->id = id;
  this->texto = texto;
  this->fecEscrito = fecEscrito;
}