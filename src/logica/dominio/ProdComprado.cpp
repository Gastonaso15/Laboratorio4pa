#include "ProdComprado.h"
#include <iostream>
using namespace std;

ProdComprado::ProdComprado(){}

ProdComprado::~ProdComprado(){}

ProdComprado::ProdComprado(int cantidad,bool enviado){
  this->cantidad=cantidad;
  this->enviado=enviado;
}

