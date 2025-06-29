#include "EnviarProducto.h"
#include <iostream>
#include <limits> // Necesario para numeric_limits

using namespace std;

EnviarProducto::EnviarProducto(SistemaControlador& controlador)
    : controlador(controlador) {}

EnviarProducto::~EnviarProducto() {}

std::string EnviarProducto::enviarProducto() {
    cout << "--- Iniciar Envio de Producto ---" << endl;

    // 1. El Sistema lista los nicknames de todos los vendedores
    cout << "Listando vendedores disponibles:" << endl;
    set<string> nicknamesVendedores = controlador.listarNickVendedor();

    if (nicknamesVendedores.empty()) {
        return "No hay vendedores registrados en el sistema.";
    }

    int i = 1;
    for (const string& nick : nicknamesVendedores) {
        cout << i++ << ". " << nick << endl;
    }

    // 2. El Administrador selecciona uno
    string nickVendedorSeleccionado;
    cout << "Ingrese el nickname del vendedor para ver sus productos pendientes: ";
    cin >> nickVendedorSeleccionado;

    // Validar si el nickname seleccionado existe en el conjunto
    if (nicknamesVendedores.find(nickVendedorSeleccionado) == nicknamesVendedores.end()) {
        return "El nickname de vendedor ingresado no es valido.";
    }

    // 3. se listan los productos que vende ese vendedor que tienen al menos una compra pendiente de envío.
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

    // 4. Luego el Administrador selecciona el producto
    int codigoProductoSeleccionado;
    cout << "Ingrese el codigo del producto a enviar: ";
    cin >> codigoProductoSeleccionado;

    // Validación básica de la entrada. Limpiar el buffer por seguridad.
    if (cin.fail()) {
        cin.clear(); // Limpiar banderas de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada inválida
        return "Entrada invalida. Por favor, ingrese un numero para el codigo del producto.";
    }

    // Verificar si el código de producto seleccionado está en la lista de productos con envíos pendientes
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

    // 5. el Sistema lista todas las compras como parejas (nickname del cliente, fecha de compra),
    // para aquellas compras que tienen pendientes de enviar el producto.
    cout << "\nListando compras pendientes para el producto Codigo " << codigoProductoSeleccionado << ":" << endl;
    set<DTCompra> comprasPendientesParaProducto = controlador.seleccionarProductoC(codigoProductoSeleccionado);

    if (comprasPendientesParaProducto.empty()) {
        // Esto no debería pasar si el paso anterior fue correcto, pero es una buena verificación de seguridad.
        return "Error: No se encontraron compras pendientes para el producto seleccionado.";
    }

    i = 1;
       for (const auto& compra : comprasPendientesParaProducto) {
            cout << i++ << ". ID Compra: " << compra.getIdCompra()
                 << ", Cliente: " << compra.getCliente()->getNickname() // <-- Error here
                 << ", Fecha: " << compra.getFecha().toString() << endl;
        }

    // 6. Finalmente, el Administrador selecciona un elemento de esa lista
    int idCompraSeleccionada;
    cout << "Ingrese el ID de la compra a la que desea marcar el producto como enviado: ";
    cin >> idCompraSeleccionada;

    // Validación básica de la entrada. Limpiar el buffer por seguridad.
    if (cin.fail()) {
        cin.clear(); // Limpiar banderas de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar entrada inválida
        return "Entrada invalida. Por favor, ingrese un numero para el ID de la compra.";
    }

    // Validar si el ID de compra seleccionado existe en la lista de compras pendientes para el producto
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

    // 7. el Sistema marca el producto en la compra como enviado.
    try {
        string mensaje = controlador.marcarProductoComoEnviado(codigoProductoSeleccionado, idCompraSeleccionada);
        return mensaje;
    } catch (const exception& e) {
        return string("Error al marcar como enviado: ") + e.what();
    }
}