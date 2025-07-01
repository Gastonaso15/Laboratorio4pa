#include "EliminarComentario.h"

EliminarComentario::EliminarComentario(SistemaControlador& controlador):controlador(controlador) {}

EliminarComentario::~EliminarComentario() {}

string EliminarComentario::eliminarComentario() {
  string respuesta;
  set<string> usuarios =controlador.listarNicknamesUsuario();
  if(usuarios.empty()){
    return "Error: No hay usuarios registrados.";
  } else {
    cout << "--- Usuarios registrados ---" << endl;
    for (string nick : usuarios) {
      cout << nick << endl;
      cout << "---------------------------" << endl;
    }
  }
  string nick;
  cout << endl << "--- Seleccionar Usuario ---" << endl;
  cout << "Ingrese nickname: ";
  cin >> nick;
  set<DTComentario*> comentarios = controlador.seleccionarUsuarioComentario(nick);
  if (comentarios.empty()) {
    respuesta= "Error: No hay comentarios registrados.";
    return respuesta;
  } else {
    cout << "--- Comentarios registrados ---" << endl;
    for (const DTComentario* com : comentarios) {
      cout << "Id: " << com->id << " Comentario: " << com->texto << endl << "Fecha Escrito: " << com->fecEscrito->toString() << endl;
    }
  }
  int id;
  cout << endl << "** Eliminar Comentario **" << endl;
  cout << "Ingrese id del Comentario: ";
  cin >> id;
  respuesta=controlador.borrarComentario(id);
  return respuesta;
}
