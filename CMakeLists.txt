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
        src/logica/dominio/Sistema.cpp
        src/logica/dominio/Sistema.h
        src/logica/dominio/Usuario.cpp
        src/logica/dominio/Usuario.h
    src/presentacion/Login.cpp
    src/presentacion/Login.h
    src/Principal.cpp
        src/presentacion/AltaUsuario.cpp
        src/presentacion/AltaUsuario.h
        src/logica/DTs/DTUsuario.cpp
        src/logica/DTs/DTUsuario.h
        src/logica/DTs/DTVendedor.cpp
        src/logica/DTs/DTVendedor.h
        src/logica/DTs/DTCliente.cpp
        src/logica/DTs/DTCliente.h
        src/logica/DTs/DTDireccion.cpp
        src/logica/DTs/DTDireccion.h
        src/logica/DTs/DTFecha.cpp
        src/logica/DTs/DTFecha.h)
