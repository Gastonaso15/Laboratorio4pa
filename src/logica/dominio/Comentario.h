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

    Producto * producto;
    Comentario * padre;
    map<int,Comentario*> respuestas;
  public:
    Comentario();
    Comentario(int id, string texto, DTFecha * fecEscrito,Producto * producto);
    Comentario(int id, std::string texto, DTFecha * fecEscrito, Producto * producto, Comentario* padre);
    virtual ~Comentario();

    bool tieneRespuestas();

    int getId();

    void agregarRespuesta(Comentario * com);

    DTComentario* retornarDTComentario();
    DTComentario* retornarDTComentarioPadre();
    Producto* getProducto();

    map<int,Comentario*>& getRespuestas();

};



#endif //COMENTARIO_H
