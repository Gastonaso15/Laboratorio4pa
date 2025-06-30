#include "CrearPromocion.h"
#include <iostream>
#include <string>
#include "../logica/controlador/SistemaControlador.h"
#include "../DTs/DTPromocion.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTProdPromocion.h"
using namespace std;

CrearPromocion::CrearPromocion(SistemaControlador& controlador):controlador(controlador) {}

CrearPromocion::~CrearPromocion() {}

string CrearPromocion::crearPromocion() {
  //ingDatos
  string nombre,descripcion,respuesta;
  int dia,mes,anio;
  cout << "--- Crear Promocion ---" << endl;
  cout << "Ingrese nombre de la Promocion: ";
  cin >> nombre;
  cout << "Ingrese descripcion: ";
  cin.ignore();
  getline(cin, descripcion);
  cout << "Ingrese fecha de vencimiento: " << endl;
  cout << "Dia: ";
  cin >> dia;
  cout << "Mes: ";
  cin >> mes;
  cout << "Anio: ";
  cin >> anio;
  DTFecha* fecha = new DTFecha(anio, mes, dia);
  DTPromocion * promocion = new DTPromocion(nombre,descripcion,fecha);
  set<string> vendedores=controlador.ingDatos(*promocion);
  if (vendedores.empty()) {
    respuesta= "Error: No hay vendedores registrados.";
    return respuesta;
  } else {
    cout << "--- Vendedores registrados ---" << endl;
    for (const string& nick : vendedores) {
      cout << "- " << nick << endl;
    }
  }
  string nick;
  cout << "--- Seleccionar Vendedor ---" << endl;
  cout << "Ingrese nick del Vendedor: ";
  cin >> nick;
  set<DTProducto> productos = controlador.seleccionarVendedor(nick);
  if (productos.empty()) {
    respuesta= "Error: No hay productos registrados.";
    return respuesta;
  } else {
    cout << "--- Productos registrados ---" << endl;
    for (const DTProducto& prod : productos) {
      cout << "Codigo: " << prod.codigo << " Nombre: " << prod.nombre << endl;
    }
  }
  set<DTProdPromocion> productosParaPromo;
  string continuar = "Si";
  int codigo, cantidad, descuento;
  cout << endl << "** Ingresar Datos **" << endl;
  while(continuar=="Si" || continuar=="SI" || continuar=="si") {
    cout << "Ingrese codigo del Producto: ";
    cin >> codigo;
    DTProducto dtProdEncontrado;
    bool encontrado = false;
    for (const DTProducto& p : productos) {
      if (p.codigo == codigo) {
        dtProdEncontrado = p;
        encontrado = true;
        break;
      }
    }
    if (!encontrado) {
      cout << "Error: Producto con codigo " << codigo << " no encontrado." << endl;
      continue;
    }
    cout << "Ingrese cantidad minima para la Promocion: ";
    cin >> cantidad;
    cout << "Ingrese el porcentaje de descuento: ";
    cin >> descuento;
    productosParaPromo.insert(DTProdPromocion(cantidad, descuento, dtProdEncontrado));
    cout << "Desea agregar mas Productos?: ";
    cin >> continuar;
    }
    respuesta=controlador.agregarProdProm(productosParaPromo);
    return respuesta;
}