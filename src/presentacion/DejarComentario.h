#ifndef DEJARCOMENTARIO_H
#define DEJARCOMENTARIO_H

#include "../logica/controlador/SistemaControlador.h"
#include <string>

class DejarComentario {
private:
    SistemaControlador& controlador;
public:
    DejarComentario(SistemaControlador& controlador);
    ~DejarComentario();
    string dejarComentario();
};



#endif //DEJARCOMENTARIO_H
