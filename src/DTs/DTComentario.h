#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <iostream>
#include "DTFecha.h"
using namespace std;

class DTComentario {
  private:
    int id;
    string texto;
    DTFecha fecEscrito;

  public:

    DTComentario();
    ~DTComentario();
    DTComentario(int id, string texto, DTFecha fecEscrito);
    void borrarRespuesta();

};



#endif //DTCOMENTARIO_H
