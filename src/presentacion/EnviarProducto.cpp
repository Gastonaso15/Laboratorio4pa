#include "EnviarProducto.h"
#include <iostream>
#include <limits>
using namespace std;

EnviarProducto::EnviarProducto(SistemaControlador& controlador)
    : controlador(controlador) {}

EnviarProducto::~EnviarProducto() {}

string EnviarProducto::enviarProducto() {
    cout << "--- Iniciar Envio de Producto ---" << endl;
    cout << "Listando vendedores disponibles:" << endl;
    set<string> nicknamesVendedores = controlador.listarNickVendedor();

    if (nicknamesVendedores.empty()) {
        return "No hay vendedores registrados en el sistema.";
    }

    int i = 1;
    for (const string& nick : nicknamesVendedores) {
        cout << i++ << ". " << nick << endl;
    }

    string nickVendedorSeleccionado;
    cout << "Ingrese el nickname del vendedor para ver sus productos pendientes: ";
    cin >> nickVendedorSeleccionado;

    if (nicknamesVendedores.find(nickVendedorSeleccionado) == nicknamesVendedores.end()) {
        return "El nickname de vendedor ingresado no es valido.";
    }

    cout << "\nListando productos del vendedor '" << nickVendedorSeleccionado << "' con compras pendientes de envio:" << endl;
    set<DTProducto> productosConEnvioPendiente = controlador.obtenerProductosPendientesPorVendedor(nickVendedorSeleccionado);

    if (productosConEnvioPendiente.empty()) {
        return "No hay productos con compras pendientes de envio para el vendedor seleccionado.";
    }

    i = 1;
    for (const DTProducto& prod : productosConEnvioPendiente) {
        cout << i++ << ". Codigo: " << prod.codigo
             << ", Nombre: " << prod.nombre
             << ", Stock: " << prod.stock << endl;
    }

    int codigoProductoSeleccionado;
    cout << "Ingrese el codigo del producto a enviar: ";
    cin >> codigoProductoSeleccionado;

    if (cin.fail()) {
        cin.clear(); // Limpiar banderas de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return "Entrada invalida. Por favor, ingrese un numero para el codigo del producto.";
    }

    bool productoEncontrado = false;
    for (const DTProducto& prod : productosConEnvioPendiente) {
        if (prod.codigo == codigoProductoSeleccionado) {
            productoEncontrado = true;
            break;
        }
    }

    if (!productoEncontrado) {
        return "El codigo de producto ingresado no es valido o no tiene envios pendientes para este vendedor.";
    }

    cout << "\nListando compras pendientes para el producto Codigo " << codigoProductoSeleccionado << ":" << endl;
    set<DTCompra> comprasPendientesParaProducto = controlador.seleccionarProductoC(codigoProductoSeleccionado);

    if (comprasPendientesParaProducto.empty()) {
        return "Error: No se encontraron compras pendientes para el producto seleccionado.";
    }

    i = 1;
       for (const auto& compra : comprasPendientesParaProducto) {
            cout << i++ << ". ID Compra: " << compra.getIdCompra()
                 << ", Cliente: " << compra.getCliente()->getNickname()
                 << ", Fecha: " << compra.getFecha().toString() << endl;
        }

    int idCompraSeleccionada;
    cout << "Ingrese el ID de la compra a la que desea marcar el producto como enviado: ";
    cin >> idCompraSeleccionada;

    if (cin.fail()) {
        cin.clear(); // Limpiar banderas de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return "Entrada invalida. Por favor, ingrese un numero para el ID de la compra.";
    }

    bool compraEncontrada = false;
    for (const DTCompra& compra : comprasPendientesParaProducto) {
        if (compra.getIdCompra() == idCompraSeleccionada) {
            compraEncontrada = true;
            break;
        }
    }

    if (!compraEncontrada) {
        return "El ID de compra ingresado no es valido o el producto no esta pendiente en esa compra.";
    }

    try {
        string mensaje = controlador.marcarProductoComoEnviado(codigoProductoSeleccionado, idCompraSeleccionada);
        return mensaje;
    } catch (const exception& e) {
        return string("Error al marcar como enviado: ") + e.what();
    }
}