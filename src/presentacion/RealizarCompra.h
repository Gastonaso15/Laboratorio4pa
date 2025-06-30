#ifndef REALIZARCOMPRA_H
#define REALIZARCOMPRA_H

#include "../logica/controlador/SistemaControlador.h"
#include <string>

class RealizarCompra {
    private:
        SistemaControlador& controlador;
    public:
        RealizarCompra(SistemaControlador& controlador);
        ~RealizarCompra();
        string realizarCompra();
};
//Falta tener en cuenta promocion y stock, hacer confirmarCompra y arreglar verDetalleCompra


#endif //REALIZARCOMPRA_H
