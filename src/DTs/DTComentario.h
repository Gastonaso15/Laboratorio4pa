#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <iostream>
#include "DTFecha.h"
using namespace std;

class DTComentario {
    public:
        int id;
        string texto;
        DTFecha *fecEscrito;
        DTComentario * padre;
        //--------------------------------------------------------------------------------------------------------------------
        DTComentario();
        DTComentario(int id, string texto, DTFecha *fecEscrito);
        DTComentario(int id, string texto, DTFecha *fecEscrito, DTComentario * padre);
        ~DTComentario();

        void borrarRespuesta();

};



#endif //DTCOMENTARIO_H
