#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "../../DTs/DTCliente.h"


class Compra;

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
    DTCliente getCliente() const;
    DTUsuario* retornarDTUsuario() const override;
};



#endif //CLIENTE_H
