#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include <map>
#include <set>
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
    Comentario * padre;
  public:
    Comentario();
    Comentario(int id, string texto, DTFecha * fecEscrito,Producto * producto);
    Comentario(int id, std::string texto, DTFecha * fecEscrito, Producto * producto, Comentario* padre);
    virtual ~Comentario();
    int getId();
    DTComentario* retornarDTComentario();
    DTComentario* retornarDTComentarioPadre();
    void agregarRespuesta(Comentario * com);
    bool tieneRespuestas();
    Producto* getProducto();
    map<int,Comentario*>& getRespuestas();

};



#endif //COMENTARIO_H
