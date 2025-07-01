#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "../../DTs/DTCliente.h"
#include "../../DTs/DTDireccion.h"
#include "../dominio/Compra.h"

class Cliente: public Usuario{
protected:
    string ciudad;
    DTDireccion * direccion;

    map<int,Compra*> compras;
public:
    Cliente(string nick, string pass, DTFecha *  fechaNac,DTDireccion* direccion, string ciudad);
    Cliente();
    ~Cliente();

    void asociarProd();
    void agregarCompra(Compra* compra);

    string getCiudad() const;

    DTCliente getCliente() const;
    DTUsuario* retornarDTUsuario() const override;
    DTDireccion* getDireccion() const;
    DTCliente* toDT();

    set<DTCompra*> retornarCompras();

};



#endif //CLIENTE_H
