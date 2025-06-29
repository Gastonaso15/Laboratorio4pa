#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "../../DTs/DTCliente.h"
#include "../../DTs/DTDireccion.h"
#include "../dominio/Compra.h"

class Cliente: public Usuario{
protected:

    DTDireccion * direccion;
    string ciudad;

    map<int,Compra*> compras;

public:
    Cliente(string nick, string pass, DTFecha *  fechaNac,DTDireccion* direccion, string ciudad);
    Cliente getCliente();
    Cliente();
    ~Cliente();

    void asociarProd();

    std::string getCiudad() const;

    DTCliente getCliente() const;
    DTUsuario* retornarDTUsuario() const override;
    DTDireccion* getDireccion() const;
    DTCliente* toDT();
};



#endif //CLIENTE_H
