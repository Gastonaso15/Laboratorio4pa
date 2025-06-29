#ifndef ELIMINARCOMENTARIO_H
#define ELIMINARCOMENTARIO_H

#include "../logica/controlador/SistemaControlador.h"
#include <string>

class EliminarComentario {
    private:
       SistemaControlador& controlador;
    public:
        EliminarComentario(SistemaControlador& controlador);
        ~EliminarComentario();
        string eliminarComentario();
};



#endif //ELIMINARCOMENTARIO_H
