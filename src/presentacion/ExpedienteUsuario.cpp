#include "ExpedienteUsuario.h"

#include "DTVendedor.h"

ExpedienteUsuario::ExpedienteUsuario(SistemaControlador& controlador):controlador(controlador) {}

ExpedienteUsuario::~ExpedienteUsuario() {}

string ExpedienteUsuario::expedienteUsuario() {
    //solicitarNicknames
    set<DTUsuario*> usuarios =controlador.listarUsuarios();
    if(usuarios.empty()){
        return "Error: No hay usuarios registrados.";
    } else {
        cout << "--- Usuarios registrados ---" << endl;
        for (DTUsuario* dt : usuarios) {
            cout << "         " << dt->nick << "         " << endl;
            cout << "---------------------------" << endl;
            delete dt;
        }
    }
    //seleccionarNickname(nick:str):DTUsuario
    string nick;
    cout << endl << "--- Seleccionar Usuario ---" << endl;
    cout << "Ingrese nickname: ";
    cin >> nick;
    DTUsuario * usu = controlador.seleccionarUsuarioExpediente(nick);
    if (usu==nullptr) {
        return "Error: Usuario no encontrado";
    }
    cout<< usu->obtenerInfo() << endl;
    if (DTCliente* dtoCli = dynamic_cast<DTCliente*>(usu)) {
        cout << endl << "--- Compras del Cliente ---" << endl;
        if (dtoCli->setCompras.empty()) {
            cout << "El cliente no tiene compras registradas";
        }
        for (auto compra : dtoCli->setCompras) {
            cout << "Precio total $: " << compra->montoTotal << endl << "Fecha de Compra: " << compra->fecCompra->toString() << endl;
            cout << "--- Productos Comprados ---" << endl;
            set<DTProdComprado*> productoscom = compra->getProductosComprados();
            for (DTProdComprado* prodComprado : productoscom){
                cout << "Nombre: " << prodComprado->producto->nombre << endl;
                cout << "Precio: $" << prodComprado->producto->precio << endl;
                cout << "Descripcion: " << prodComprado->producto->descripcion << endl;
                cout << "Cantidad: " << prodComprado->cantidad << endl;
                cout << "------------------------" <<endl<<endl;
            }
        }
    }else if (DTVendedor* dtoVen = dynamic_cast<DTVendedor*>(usu)){
        cout << endl << "--- Productos del Vendedor ---" << endl;
        if (dtoVen->setProductos.empty()) {
            cout << "El vendedor no tiene productos registrados";
        }
        for (auto producto : dtoVen->setProductos) {
            cout << endl << "Codigo: " << producto->codigo << " Nombre: " << producto->nombre << endl;
            cout << "Precio: " << producto->precio << endl << "Stock: " << producto->stock << endl
           << "Descripcion: " << producto->descripcion << endl << "Categoria: " << DTProducto::catToString(producto->categoria) << endl;
        }
        cout << endl << "--- Promociones del Vendedor ---" << endl;
        if (dtoVen->setPromos.empty()) {
            cout << endl<<"El vendedor no tiene promociones registradas"<<endl;
        }
        for (auto promocion : dtoVen->setPromos) {
            if (!promocion->estaVigente()) {
                cout << endl << "El vendedor no tiene promociones vigentes registradas" << endl;
            }
            cout <<endl<< promocion->obtenerInfo() << endl;
            cout <<"Productos de la promocion: "<<endl;
            for (auto prodprom : promocion->prodsprom) {
                cout << "Cantidad Minima: " << prodprom->cantMinima << endl
                     << "Descuento: " << prodprom->descuento << "%" << endl;
                cout << "Codigo: " << prodprom->producto.codigo << endl
                         << "Nombre: " << prodprom->producto.nombre << endl;
            }
        }
    }
    return "Informacion mostrada con exito";
}
