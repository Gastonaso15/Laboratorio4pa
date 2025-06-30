#include "SistemaControlador.h"
#include <iostream>
#include <stdexcept>
#include <string>

#include "DTProdComprado.h"
using namespace std;

#include "../dominio/Producto.h"
#include "../DTs/DTFecha.h"
#include "../DTs/DTProducto.h"
#include "../DTs/DTUsuario.h"
#include "../DTs/DTVendedor.h"
#include "../DTs/DTCliente.h"
#include "../dominio/Usuario.h"
#include "../dominio/Cliente.h"
#include "../dominio/Vendedor.h"
#include "../dominio/Promocion.h"
#include "../dominio/Compra.h"
#include "../dominio/Comentario.h"
#include "../dominio/ProdComprado.h"
#include <map>
#include "../presentacion/EnviarProducto.h"


SistemaControlador* SistemaControlador::instancia = nullptr;

SistemaControlador::SistemaControlador() {}

SistemaControlador::~SistemaControlador() {
    for (auto& par : usuarios) {
        delete par.second;
    }
    usuarios.clear();
    for (auto& par : productos) {
        delete par.second;
    }
    productos.clear();
    for (auto& par : promociones) {
        delete par.second;
    }
    promociones.clear();
    for (auto& par : compras) {
        delete par.second;
    }
    compras.clear();
}

SistemaControlador& SistemaControlador::getInstancia() {
    if (instancia == nullptr) {
        instancia = new SistemaControlador();
    }
    return *instancia;
}

string SistemaControlador::altaUsuario(DTUsuario* usuario) {
    Usuario* nuevoUsuario = nullptr;
    string respuesta;
    if (DTCliente* dtoCli = dynamic_cast<DTCliente*>(usuario)) {
        DTFecha* fechaNac = new DTFecha(*dtoCli->fechaNac);
        nuevoUsuario = new Cliente(
            dtoCli->nick,
            dtoCli->pass,
            fechaNac,
            dtoCli->direccion,
            dtoCli->ciudad
        );

    } else if (DTVendedor* dtoVen = dynamic_cast<DTVendedor*>(usuario)) {
        DTFecha* fechaNac = new DTFecha(*dtoVen->fechaNac);

        nuevoUsuario = new Vendedor(
            dtoVen->nick,
            dtoVen->pass,
            fechaNac,
            dtoVen->rut
        );
    }

    if (nuevoUsuario != nullptr) {
        string nick = usuario->nick;
        if (usuarios.find(nick) == usuarios.end()) {
            usuarios[nick] = nuevoUsuario;
            respuesta="Alta Usuario realizada con exito";
        } else {
            delete nuevoUsuario;
            respuesta="El usuario con ese nick ya existe.";
        }
    } else {
        respuesta="Tipo de usuario desconocido.";
    }
    return respuesta;
}

set<string> SistemaControlador::listarNickVendedor() {
    set <string> nicks;
    for (auto& par : usuarios) {
        Usuario* u = par.second;
        Vendedor* v = dynamic_cast<Vendedor*>(u);
        if (v != nullptr) {
            nicks.insert(v->getNickname());
        }
    }
    return nicks;
}

set<DTUsuario*> SistemaControlador::listarUsuarios() {
    set<DTUsuario*> resultado;
    for (auto const& par: usuarios){
        Usuario* usuario = par.second;
        resultado.insert(usuario->retornarDTUsuario());
    }
    return resultado;
}

string SistemaControlador::selectVendedor(string nick) {
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        Vendedor* v = dynamic_cast<Vendedor*>(it->second);
        if (v != nullptr) {
            vendedorSeleccionado = v;
            return "Vendedor " + nick + " seleccionado correctamente.";
        } else {
            return "Error: El usuario no es un vendedor.";
        }
    } else {
        return "Error: No se encontro un usuario con ese nick.";
    }
}

Producto* SistemaControlador::buscarProductoPorDT(const DTProducto* dtp) {
    auto it = productos.find(dtp->codigo);
    if (it != productos.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

bool SistemaControlador::ingProducto(const DTProducto& producto) {
    int cod = ++ultimoCodigoProducto;
    Producto * prod = new Producto(cod, producto.nombre, producto.precio, producto.stock, producto.descripcion, producto.categoria);
    prod->asociarProdVendedor(vendedorSeleccionado);
    vendedorSeleccionado->aniadirProdListaVendedor(prod);
    int codigo = prod->getCodigo();
    auto result = productos.insert({codigo, prod});
    return result.second;
}

set<DTProducto> SistemaControlador::listarProd() {
    set<DTProducto> resultado;
    for (const auto& par : productos) {
        Producto* p = par.second;
        DTProducto* dtProdPuntero = p->retornarDTProducto();
        DTProducto dto = *dtProdPuntero;
        delete dtProdPuntero;
        resultado.insert(dto);
    }
    return resultado;
}

DTProducto* SistemaControlador::selectProd(int codigo) {
    auto it = productos.find(codigo);
    if (it != productos.end()) {
        Producto* prod = it->second;
        return new DTProducto(*prod->retornarDTProducto());
    } else {
        return nullptr;
    }
}

set<string> SistemaControlador::ingDatos(DTPromocion prom) {
    Promocion* nuevaPromo = new Promocion(prom.nom, prom.desc, prom.fecVencimiento);
    promocionActual = nuevaPromo;
    this->promociones[nuevaPromo->getNom()] = nuevaPromo;
    set<string> nicks=listarNickVendedor();
    return nicks;
}

set<DTProducto> SistemaControlador::seleccionarVendedor(string nick) {
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        Vendedor* v = dynamic_cast<Vendedor*>(it->second);
        if (v != nullptr) {
            vendedorSeleccionado = v;
            set<DTProducto> productosVendedor;
            for (const auto& p : v->retornarProductos()) {
                productosVendedor.insert(p);
            }
            return productosVendedor;
        }
    }
    return set<DTProducto>();  // Retorna set vacío si no encuentra el vendedor
}

string SistemaControlador::agregarProdProm(set<DTProdPromocion> productosDT) {
    for (const DTProdPromocion& dtPromo : productosDT) {
        auto it = productos.find(dtPromo.producto.codigo);
        if (it != productos.end()) {
            Producto* prod = it->second;
            if (!prod->productoEnPromo()) {
                promocionActual->agregarProdProm(prod, dtPromo.cantMinima, dtPromo.descuento);
            }else {
                return "Error: El producto ya se encuentra en otra Promocion";
            }
        } else {
            return "Error: No existe el Producto seleccionado";
        }
    }
    return "Promocion creada con exito";
}
set<string> SistemaControlador::listarClientes() {
    set<string> nicksClientes;
    for (const auto& par : usuarios) {
        if (dynamic_cast<Cliente*>(par.second) != nullptr) {
            nicksClientes.insert(par.first);
        }
    }
    return nicksClientes;
}

set<DTPromocion*> SistemaControlador::listarPromociones() {
    set<DTPromocion*> resultado;
    for (auto const& par : this->promociones) {
        Promocion* p = par.second;
        if (p->estaVigente()) {
            resultado.insert(p->retornarDTPromocion());
        }
    }
    return resultado;
}

set<DTProdPromocion*> SistemaControlador::selectPromo(string nombre) {
    auto it = promociones.find(nombre);
    if (it != promociones.end()) {
        Promocion* prom = it->second;
        return prom->retornarDTProdPromocion();
    } else {
        return {};
    }
}

set<DTProducto> SistemaControlador::seleccionarCliente(string nick) {
    clienteSeleccionado = nullptr;
    delete compraActual;
    compraActual = nullptr;
    auto it = usuarios.find(nick);
    if (it == usuarios.end()) {
        throw runtime_error("Usuario no encontrado");
    }
    clienteSeleccionado=dynamic_cast<Cliente*>(it->second);
    set<DTProducto> productosDisponibles;
    for (const auto& par : productos) {
        Producto* p = par.second;
        DTProducto* dtProdPuntero = p->retornarDTProducto();
        DTProducto dto = *dtProdPuntero;
        delete dtProdPuntero;
        productosDisponibles.insert(dto);
    }
    return productosDisponibles;
}

void SistemaControlador::agregarProducto(DTProdComprado p) {
    if (compraActual == nullptr) {
        compraActual = new Compra(-1,0,nullptr,0,nullptr);
    }
    compraActual->agregoProd(p);
}

DTCompra* SistemaControlador::verDetalleCompra() {
    if (clienteSeleccionado == nullptr) {
        throw runtime_error("Error: No hay cliente seleccionado para confirmar la compra.");
    }
    if (compraActual == nullptr || compraActual->getProdComprado().empty()) {
        throw runtime_error("Error: No hay productos en el carrito de compra para confirmar.");
    }
    float montoTotalCalculado = 0;
    for (ProdComprado* pc : compraActual->getProdComprado()) {
        Producto* prod = pc->getProducto();
        int cantidadDeseada = pc->getCantidad();

        if (prod->getStock() < cantidadDeseada) {
            throw runtime_error("Error: Stock insuficiente para el producto " + prod->getNombre() + ". Stock disponible: " + to_string(prod->getStock()));
        }
        float precioUnitarioProducto = prod->getPrecio();
        float precioConDescuento = precioUnitarioProducto;
        for (ProdPromocion* pp : prod->getProdPromociones()) {
            if (pp->retornarPromocion()->estaVigente()) {
                if (cantidadDeseada >= pp->getCantMinima()) {
                    precioConDescuento = precioUnitarioProducto * (100.0 - pp->getDescuento()) / 100.0;
                    break;
                }
            }
        }
        montoTotalCalculado += precioConDescuento * cantidadDeseada;
    }
    for (ProdComprado* pc : compraActual->getProdComprado()) {
        Producto* prod = pc->getProducto();
        int cantidadDeseada = pc->getCantidad();
        prod->restarStock(cantidadDeseada);
    }
    compraActual->setId(++ultimoCodigoCompra);
    compraActual->setFecCompra(new DTFecha(DTFecha::obtenerFechaActual()));
    compraActual->setMontoTotal(montoTotalCalculado);
    compraActual->setCliente(clienteSeleccionado);

    DTCompra * detalle = compraActual->getCompra();
    return detalle;
}

string SistemaControlador::confirmarCompra(){
    clienteSeleccionado->agregarCompra(compraActual);
    this->compras[compraActual->getId()] = compraActual;
    compraActual = nullptr;
    return "Compra confirmada con exito";

}

set<string> SistemaControlador::listarNicknamesUsuario() {
    set<string> resultado;
    for (auto const& par: usuarios){
        Usuario* usuario = par.second;
        resultado.insert(usuario->getNickname());
    }
    return resultado;
}

set<DTProducto> SistemaControlador::seleccionarUsuario(string nick) {
    set<DTProducto> prods;
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        usuarioSeleccionado= it->second;
        for (const auto& par : productos) {
            Producto* p = par.second;
            DTProducto* dtProdPuntero = p->retornarDTProducto();
            DTProducto dto = *dtProdPuntero;
            delete dtProdPuntero;
            prods.insert(dto);
        }
        return prods;
    }
    return prods;  // Retorna set vacío si no encuentra al usuario
}

bool SistemaControlador::seleccionarProducto(int codigo) {
    auto it = productos.find(codigo);
    if (it != productos.end()) {
        productoSeleccionado = it->second;
        return true;
    }
    return false;
}

string SistemaControlador::agregarComentario(string texto) {
    if (this->usuarioSeleccionado == nullptr) {
        return "Error: No hay usuario seleccionado.";
    }
    if (this->productoSeleccionado == nullptr) {
        return "Error: No hay producto seleccionado.";
    }
    int id = ++ultimoCodigoComentario;
    DTFecha* fechaActual = new DTFecha(DTFecha::obtenerFechaActual());
    Comentario * com = new Comentario(id,texto,fechaActual,productoSeleccionado);
    usuarioSeleccionado->asociarComentarioUsuario(com);
    productoSeleccionado->asociarComentarioProducto(com);
    return "Comentario creado con exito";
}

set<DTComentario*> SistemaControlador::listarComentario() {
    set<DTComentario*> resultado;
    if (this->productoSeleccionado == nullptr) {
        return resultado;
    }
    resultado=productoSeleccionado->getComentarios();
    return resultado;
}

bool SistemaControlador::seleccionarComentario(int id) {
    comentarioSeleccionado = this->productoSeleccionado->getComentario(id);
    if (this->comentarioSeleccionado == nullptr) {
        return false;
    }
    return true;
}

string SistemaControlador::agregarRespuesta(string texto) {
    if (this->productoSeleccionado == nullptr) {
        return "Error: No hay producto seleccionado.";
    }
    if (this->comentarioSeleccionado==nullptr) {
        return "Error: No hay comentario seleccionado.";
    }
    int id = ++ultimoCodigoComentario;
    DTFecha* fechaActual = new DTFecha(DTFecha::obtenerFechaActual());
    Comentario * com = new Comentario(id,texto,fechaActual,productoSeleccionado,comentarioSeleccionado);
    comentarioSeleccionado->agregarRespuesta(com);
    usuarioSeleccionado->asociarComentarioUsuario(com);
    productoSeleccionado->asociarComentarioProducto(com);
    return "Respuesta creada con exito";
}

set<DTComentario*> SistemaControlador::seleccionarUsuarioComentario(string nick) {
    set<DTComentario*> resultado;
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        usuarioSeleccionado= it->second;
        resultado=usuarioSeleccionado->getComentarios();
        return resultado;
    }
    return resultado;
}

void SistemaControlador::auxBorrarComentarioRecursivo(Comentario* com, Usuario* usuario, Producto* producto) {
    for (auto& par : com->getRespuestas()) {
        auxBorrarComentarioRecursivo(par.second, usuario, producto);
    }
    usuario->eliminarComentario(com->getId());
    producto->eliminarComentario(com->getId());
    delete com;
}

string SistemaControlador::borrarComentario(int id) {
    Comentario* com = usuarioSeleccionado->obtenerComentario(id);
    if (com == nullptr) {
        return "Error: No existe un comentario con ese ID";
    }
    Producto* prod = com->getProducto();
    auxBorrarComentarioRecursivo(com, usuarioSeleccionado, prod);
    return "Comentario borrado con exito";
}

set<DTCompra> SistemaControlador::seleccionarProductoC(int codigoProducto) {
    set<DTCompra> resultado;

    for (const auto& par : compras) {
        Compra* compra = par.second;
        for (ProdComprado* pc : compra->getProdComprado()) {
            if (pc->getProducto()->getCodigo() == codigoProducto && !pc->getEnviado()) {
                resultado.insert(compra->toDT());
            }
        }
    }
    return resultado;
}

string SistemaControlador::marcarProductoComoEnviado(int codigoProducto, int idCompra) {
    auto itCompra = compras.find(idCompra);
    if (itCompra != compras.end()) {
        Compra* compra = itCompra->second;
        for (ProdComprado* pc : compra->getProdComprado()) {
            if (pc->getProducto()->getCodigo() == codigoProducto && !pc->getEnviado()) {
                pc->setEnviado(true);
                return "Producto marcado como enviado correctamente en la compra " + to_string(idCompra) + ".";
            }
        }
        return "Error: El producto no se encontró pendiente de envío en la compra seleccionada.";
    }
    return "Error: No se encontró la compra con el ID especificado.";
}

set<DTProducto> SistemaControlador::obtenerProductosPendientesPorVendedor(string nickVendedor) {
    set<DTProducto> resultado;
    return resultado;
}


void SistemaControlador::cargarDatosPrueba() {
    string resultado;
    DTFecha *fechaNac1 = new DTFecha(2000, 6, 22);
    DTVendedor* dtVendedor1 = new DTVendedor("Agustin", "abc123",fechaNac1, "12345");
    altaUsuario(dtVendedor1);
    delete dtVendedor1,fechaNac1;
    DTFecha *fechaNac2 = new DTFecha(2000, 6, 22);
    DTVendedor* dtVendedor2 = new DTVendedor("Gaston", "ghi789",fechaNac2, "54321");
    altaUsuario(dtVendedor2);
    delete dtVendedor2,fechaNac2;
    DTFecha *fechaNac3 = new DTFecha(2003, 10, 7);
    DTVendedor* dtVendedor3 = new DTVendedor("Luca", "jkl012",fechaNac3, "74923");
    altaUsuario(dtVendedor3);
    delete dtVendedor3,fechaNac3;
    DTFecha *fechaNac4 = new DTFecha(2005, 5, 13);
    DTDireccion * direccion1 = new DTDireccion("Alvariza", 1498);
    DTCliente* dtCliente1 = new DTCliente("Martin", "def456", fechaNac4, "San Carlos", direccion1);
    altaUsuario(dtCliente1);
    delete dtCliente1;
    delete fechaNac4;
    DTFecha *fechaNac5 = new DTFecha(1914, 1, 6);
    DTDireccion * direccion2 = new DTDireccion("Calle 7", 1692);
    DTCliente* dtCliente2 = new DTCliente("Juan", "mno345", fechaNac5, "Maldonado", direccion2);
    altaUsuario(dtCliente2);
    delete dtCliente2;
    delete fechaNac5;
    DTFecha *fechaNac6 = new DTFecha(1998, 11, 30);
    DTDireccion * direccion3 = new DTDireccion("Gorlero", 1133);
    DTCliente* dtCliente3 = new DTCliente("Santiago", "pqr678", fechaNac6, "Punta del Este", direccion3);
    altaUsuario(dtCliente3);
    delete dtCliente3;
    delete fechaNac6;

    DTProducto * prod;
    selectVendedor("Agustin");
    prod = new DTProducto(0,"Pico",777,64,"Pica piedra",static_cast<cat>(2));
    ingProducto(*prod);
    delete prod;
    selectVendedor("Gaston");
    prod = new DTProducto(0,"Heladera",16200,30,"Enfria cosas",static_cast<cat>(0));
    resultado=ingProducto(*prod);
    delete prod;
    selectVendedor("Gaston");
    prod = new DTProducto(0,"Campera",1300,120,"Protege del frio",static_cast<cat>(1));
    resultado=ingProducto(*prod);
    delete prod;
    selectVendedor("Luca");
    prod = new DTProducto(0,"Ropero",2500,25,"Guarda ropa",static_cast<cat>(2));
    ingProducto(*prod);
    delete prod;


    DTPromocion promo1("Picos 2x1", "2 picos por el valor de 1", new DTFecha(2025, 8, 25));
    set<string> vendedores = ingDatos(promo1);
    set<DTProducto> productosVend = seleccionarVendedor("Agustin");
    set<DTProdPromocion> productosParaPromo;
    DTProducto producto;
    bool encontrado = false;
    for (const DTProducto& produ : productosVend) {
        if (produ.codigo == 1) {
            producto = produ;
            encontrado = true;
            break;
        }
    }
    productosParaPromo.insert(DTProdPromocion(2, 50, producto));
    agregarProdProm(productosParaPromo);

    DTPromocion promo3("Mucha Ropa?", "Roperos para toda la familia", new DTFecha(2025, 9, 21));
    vendedores = ingDatos(promo3);
    productosVend = seleccionarVendedor("Luca");
    set<DTProdPromocion> productosParaPromo3;
    encontrado = false;
    for (const DTProducto& prod : productosVend) {
        if (prod.codigo == 4) {
            producto = prod;
            encontrado = true;
            break;
        }
    }
    productosParaPromo.insert(DTProdPromocion(3, 20, producto));
    agregarProdProm(productosParaPromo);


    seleccionarUsuario("Martin");
    seleccionarProducto(1);
    agregarComentario("Pica mucho");

    seleccionarUsuario("Gaston");
    seleccionarProducto(1);
    agregarComentario("Hay mejores");

    seleccionarUsuario("Juan");
    seleccionarProducto(2);
    agregarComentario("Enfria mucho");

    seleccionarUsuario("Agustin");
    seleccionarProducto(3);
    agregarComentario("Abriga mucho");

    seleccionarUsuario("Santiago");
    seleccionarProducto(1);
    seleccionarComentario(1);
    agregarRespuesta("Mentira, no pica nada");

    seleccionarUsuario("Martin");
    seleccionarProducto(1);
    seleccionarComentario(5);
    agregarRespuesta("Si pica");

    seleccionarUsuario("Luca");
    seleccionarProducto(1);
    seleccionarComentario(5);
    agregarRespuesta("Toda la razon");

    seleccionarUsuario("Gaston");
    seleccionarProducto(2);
    seleccionarComentario(3);
    agregarRespuesta("La mia calienta");

}

/*DTUsuario* SistemaControlador::seleccionarNickname(const std::string& nick) {
    // Buscar el usuario en el mapa
    auto it = usuarios.find(nick);
    Usuario* usuario = it->second;

    // Crear copia de la fecha de nacimiento
    DTFecha* fechaNacCopy = new DTFecha(*usuario->getFechaNac());

    // Determinar si es vendedor o cliente
    if (Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario)) {
        set<DTProducto> productosSet;
        for (Producto* prod : vendedor->retornarProductos()) {
            productosSet.insert(DTProducto{
                prod->getCodigo(),
                prod->getNombre(),
                prod->getDescripcion(),
                prod->getPrecio(),
                prod->getStock(),
                prod->catToString()
            });
        }

        std::set<DTPromocion> promocionesSet;
        time_t ahora = time(nullptr);
        for (Promocion* promo : vendedor->getPromociones()) {
            if (promo->getFechaVencimiento() > ahora) {
                std::set<DTProductoPromo> productosPromoSet;
                for (ProdPromocion* pp : promo->getProductos()) {
                    Producto* prod = pp->getProducto();
                    productosPromoSet.insert(DTProductoPromo{
                        prod->getCodigo(),
                        prod->getNombre(),
                        prod->getPrecio(),
                        pp->getDescuentoAplicado()
                    });
                }

                promocionesSet.insert(DTPromocion{
                    promo->getNombre(),
                    promo->getDescripcion(),
                    promo->getFechaVencimientoAsString(),
                    promo->getDescuento(),
                    productosPromoSet
                });
            }
        }

        return new DTVendedorCompleto(
            nick,
            usuario->getPassword(),
            fechaNacCopy,
            vendedor->getRUT(),
            productosSet,
            promocionesSet
        );
    }
    else if (Cliente* cliente = dynamic_cast<Cliente*>(usuario)) {
        std::set<DTCompra> comprasSet;
        for (Compra* compra : cliente->getCompras()) {
            std::set<DTProductoCompra> productosCompraSet;
            for (ProdComprado* item : compra->getProductos()) {
                Producto* prod = item->getProducto();
                productosCompraSet.insert(DTProductoCompra{
                    prod->getCodigo(),
                    prod->getNombre(),
                    item->getCantidad(),
                    item->getPrecioUnitario(),
                    item->isEnviado()
                });
            }

            comprasSet.insert(DTCompra{
                compra->getId(),
                compra->getMontoTotal(),
                compra->getFechaAsString(),
                productosCompraSet
            });
        }

        return new DTClienteCompleto(
            nick,
            usuario->getPassword(),
            fechaNacCopy,
            comprasSet
        );
    }
    else {
        delete fechaNacCopy;
        throw std::runtime_error("Tipo de usuario desconocido");
    }
}*/