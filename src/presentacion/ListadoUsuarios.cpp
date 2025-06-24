
#include "ListadoUsuarios.h"
#include <iostream>
#include <string>
#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include "../dominio/Usuario.h"
#include "../dominio/Vendedor.h"
#include "../dominio/Cliente.h"
using namespace std;

ListadoUsuarios::ListadoUsuarios(SistemaControlador& controlador):controlador(controlador){}

ListadoUsuarios::~ListadoUsuarios(){}

void ListadoUsuarios::listarUsuarios() {
  set<DTUsuario*> usuarios =controlador.listarUsuarios();
  if(usuarios.empty()){
      cout << "No hay usuarios registrados." << endl;
  } else {
      cout << "--- Usuarios registrados ---" << endl;
          for (DTUsuario* dt : usuarios) {
              cout << "--- " << dt->getTipo() << " ---" << endl;
              cout << dt->obtenerInfo() << endl;
              cout << "---------------------------" << endl;
            delete dt;
          }
  }
}