#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <map>
#include "../DTs/DTFecha.h"
#include "../DTs/DTComentario.h"
using namespace std;

class Producto;

class Comentario {
  private:
    int id;
    string texto;
    DTFecha * fecEscrito;
    map<int,Comentario*> respuestas;
    Producto * producto;
  public:
    Comentario();
    Comentario(int id, string texto, DTFecha * fecEscrito,Producto * producto);
    virtual ~Comentario();
    int getId();
    DTComentario* retornarDTComentario();
    void agregarRespuesta(Comentario * com);
};



#endif //COMENTARIO_H
