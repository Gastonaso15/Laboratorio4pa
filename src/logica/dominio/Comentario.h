#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <map>
#include "../DTs/DTFecha.h"
using namespace std;

class Producto;

class Comentario {
  private:
    int id;
    string texto;
    DTFecha * fecEscrito;
    map<string,Comentario*> respuestas;
  public:
    Comentario();
    Comentario(int id, string texto, DTFecha * fecEscrito);
    ~Comentario();
};



#endif //COMENTARIO_H
