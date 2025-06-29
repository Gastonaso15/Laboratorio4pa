
#include "Cliente.h"
#include <iostream>
#include <string>
#include "Usuario.h"
#include <iostream>
#include "../DTs/DTFecha.h"
#include "../DTs/DTDireccion.h"
#include "../DTs/DTCliente.h"
#include "../DTs/DTUsuario.h"
using namespace std;


Cliente::Cliente(string nick, string pass, DTFecha* fechaNac, string ciudad, Direccion* direccion)
 : Usuario(nick, pass, fechaNac),   // Llama al constructor de la clase base (Usuario).
   ciudad(ciudad),                   // Inicializa el miembro 'ciudad'.
   direccion(direccion)              // Inicializa el miembro 'direccion'.
{
    // NO HAGAS ESTO AQUÍ: this->direccion = direccion; this->ciudad = ciudad;
    // Ya se inicializaron en la lista de inicialización de miembros de arriba.
}

Cliente::~Cliente() {
    // Si 'Cliente' es el dueño de 'direccion' (lo creó con 'new' y nadie más lo usa),
    // entonces descomenta estas líneas para evitar fugas de memoria.
    // Si 'direccion' es una referencia a un objeto gestionado por otra parte del sistema
    // (que es lo más común en una arquitectura limpia), ¡NO lo elimines aquí!
    // delete direccion;
    // direccion = nullptr;
}

void Cliente::asociarProd() {
    // Implementación pendiente, no hay error aquí.
}

// --- Corrección del método `toDT()` ---
// Este es el método que solía darte "Cannot resolve symbol 'toDT'".
// El problema era intentar llamar a '.toDT()' en 'this->getFechaNac()',
// que ya devuelve un DTFecha*. No necesita convertirse a sí mismo.
//
// Asumo que el constructor de DTCliente en DTCliente.h tiene esta firma:
// DTCliente(string nick, string pass, DTFecha* fecha, string ciudad, DTDireccion* direccion);
DTCliente* Cliente::toDT() {
    return new DTCliente(
        this->getNickname(),    // Obtiene nickname de Usuario (usando getter, buena práctica).
        this->getContrasenia(), // Obtiene contraseña de Usuario (usando getter).
        this->getFechaNac(),    // ¡CORREGIDO! Ya es DTFecha*, no necesita '.toDT()'.
        this->getCiudad(),      // Getter implementado abajo.
        this->getDireccion()    // Getter implementado abajo, convierte 'Direccion*' a 'DTDireccion*'.
    );
}

// --- Corrección del método `getCliente()` ---
// Este método devuelve un DTCliente por valor.
// El error aquí es que estás intentando acceder a 'this->nick', 'this->contrasenia',
// y 'this->fechaNac' directamente. Si estos son miembros privados/protegidos de
// la clase base 'Usuario', ¡debes usar sus getters!
// Además, si 'this->direccion' es 'Direccion*', necesitas convertirlo a 'DTDireccion*' con '->toDT()'.
DTCliente Cliente::getCliente() const {
    return DTCliente(
        this->getNickname(),     // Usa el getter del Usuario.
        this->getContrasenia(),  // Usa el getter del Usuario.
        this->getFechaNac(),     // Usa el getter del Usuario.
        this->getCiudad(),       // Getter implementado abajo.
        this->getDireccion()     // Getter implementado abajo, retorna DTDireccion*.
    );
}

// --- Corrección del método `retornarDTUsuario()` ---
// Similar al anterior, necesita usar los getters para los miembros de Usuario
// y convertir la dirección al DTO correcto.
DTUsuario* Cliente::retornarDTUsuario() const {
    return new DTCliente(
        this->getNickname(),     // Usa el getter del Usuario.
        "",                      // La contraseña vacía es intencional aquí.
        this->getFechaNac(),     // Usa el getter del Usuario.
        this->getCiudad(),       // Getter implementado abajo.
        this->getDireccion()     // Getter implementado abajo, retorna DTDireccion*.
    );
}

// --- Getters de Cliente ---

std::string Cliente::getCiudad() const {
    return this->ciudad; // Correcto, asumiendo 'ciudad' es un miembro de Cliente.
}

DTDireccion* Cliente::getDireccion() const {
    // Si 'this->direccion' es de tipo 'Direccion*' (clase de dominio),
    // entonces necesitas que 'Direccion' tenga un método 'toDT()' que devuelva 'DTDireccion*'.
    // Si 'this->direccion' ya fuera 'DTDireccion*', simplemente devolverías 'this->direccion'.
    if (this->direccion != nullptr) {
        return this->direccion->toDT(); // Asumo que 'Direccion::toDT()' existe.
    }
    return nullptr; // Si no hay dirección asignada.
}