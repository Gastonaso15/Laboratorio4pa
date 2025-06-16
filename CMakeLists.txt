cmake_minimum_required(VERSION 3.30)
project(Dis_EjemploArquitecturaLogin)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/logica)
include_directories(src/logica/controlador)
include_directories(src/logica/interfaceSistema)
include_directories(src/presentacion)

add_executable(Dis_EjemploArquitecturaLogin
    src/logica/controlador/SistemaControlador.cpp
    src/logica/controlador/SistemaControlador.h
    src/logica/interfaceSistema/ISistema.h
        src/logica/dominio/Usuario.cpp
        src/logica/dominio/Usuario.h
        src/Principal.cpp
        src/presentacion/AltaUsuario.cpp
        src/presentacion/AltaUsuario.h
        src/DTs/DTUsuario.cpp
        src/DTs/DTUsuario.h
        src/DTs/DTVendedor.cpp
        src/DTs/DTVendedor.h
        src/DTs/DTCliente.cpp
        src/DTs/DTCliente.h
        src/DTs/DTDireccion.cpp
        src/DTs/DTDireccion.h
        src/DTs/DTFecha.cpp
        src/DTs/DTFecha.h
        src/logica/dominio/Cliente.cpp
        src/logica/dominio/Cliente.h
        src/logica/dominio/Vendedor.cpp
        src/logica/dominio/Vendedor.h)
