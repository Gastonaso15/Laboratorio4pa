#include "DejarComentario.h"

DejarComentario::DejarComentario(SistemaControlador& controlador):controlador(controlador) {}

DejarComentario::~DejarComentario() {}

string DejarComentario::dejarComentario() {
  string respuesta;
  set<string> usuarios =controlador.listarNicknamesUsuario();
  if(usuarios.empty()){
    return respuesta="Error: No hay usuarios registrados.";
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
  set<DTProducto> productos = controlador.seleccionarUsuario(nick);
  if (productos.empty()) {
    respuesta= "Error: No hay productos registrados.";
    return respuesta;
  } else {
    cout << "--- Productos registrados ---" << endl;
    for (const DTProducto& prod : productos) {
      cout << "Codigo: " << prod.codigo << " Nombre: " << prod.nombre << endl;
    }
  }
  int codigo;
  cout << endl << "--- Seleccionar Producto ---" << endl;
  cout << "Ingrese codigo del Producto: ";
  cin >> codigo;
  if(!controlador.seleccionarProducto(codigo)){
    return respuesta="Error: No se encontro el Producto.";
  }
  cout <<endl << "Seleccione opcion deseada: " << endl;
  cout <<endl << "1- Realizar comentario nuevo" << endl;
  cout <<endl << "2- Responder a comentario existente" << endl;
  cin >> codigo;
  if(codigo<1 || codigo>2){
    respuesta="Error: Opcion invalida";
  }
  if(codigo==1){
    string texto;
    cout << endl << "** Dejar Comentario **" << endl;
    cout << "Escriba su comentario: ";
    cin.ignore();
    getline(cin, texto);
    respuesta=controlador.agregarComentario(texto);
    return respuesta;
  }
  if(codigo==2){
    set<DTComentario*> comentarios = controlador.listarComentario();
    if (comentarios.empty()) {
      respuesta= "Error: No hay comentarios registrados.";
      return respuesta;
    } else {
      cout << "--- Comentarios registrados ---" << endl;
      for (const DTComentario* com : comentarios) {
          cout << "Id: " << com->id << " Comentario: " << com->texto << endl << "Fecha Escrito: " << com->fecEscrito->toString() << endl;
          if (com->padre!=nullptr) {
            cout << "Id de comentario respondido: " << com->padre->id << endl;
          }
          cout << "---------------------------" << endl;
      }
    }
    int id;
    cout << endl << "--- Seleccionar Comentario ---" << endl;
    cout << "Ingrese id del Comentario: ";
    cin >> id;
    if(!controlador.seleccionarComentario(id)){
      return respuesta="Error: No se encontro el Comentario.";
    }
    string texto;
    cout << endl << "** Dejar Respuesta **" << endl;
    cout << "Escriba su respuesta: ";
    cin.ignore();
    getline(cin, texto);
    respuesta=controlador.agregarRespuesta(texto);
    return respuesta;
  }
  return respuesta;
}