# Compiler
CXX = g++

# C++ standard
CXXSTANDARD = -std=c++17

# Source directories
SRCDIR = src
DTSDIR = $(SRCDIR)/DTs
LOGICADIR = $(SRCDIR)/logica
CONTROLADORDIR = $(LOGICADIR)/controlador
DOMINIODIR = $(LOGICADIR)/dominio
PRESENTACIONDIR = $(SRCDIR)/presentacion

# Include paths
INCLUDE_PATHS = \
    -I$(SRCDIR) \
    -I$(DTSDIR) \
    -I$(CONTROLADORDIR) \
    -I$(DOMINIODIR) \
    -I$(PRESENTACIONDIR)

# All source files (simplified - in a real Makefile, you might list them explicitly or use wildcards)
# [cite_start]This list is derived directly from your CMakeLists.txt [cite: 1, 2, 3, 4, 5, 6, 7]
SRCS = \
    $(SRCDIR)/main.cpp \
    $(CONTROLADORDIR)/SistemaControlador.cpp \
    $(DOMINIODIR)/Compra.cpp \
    $(DOMINIODIR)/Usuario.cpp \
    $(DOMINIODIR)/Cliente.cpp \
    $(DOMINIODIR)/Producto.cpp \
    $(DOMINIODIR)/Vendedor.cpp \
    $(PRESENTACIONDIR)/AltaUsuario.cpp \
    $(PRESENTACIONDIR)/ListadoUsuarios.cpp \
    $(PRESENTACIONDIR)/AltaProducto.cpp \
    $(DTSDIR)/DTVendedor.cpp \
    $(DTSDIR)/DTUsuario.cpp \
    $(DTSDIR)/DTPromocion.cpp \
    $(DTSDIR)/DTProducto.cpp \
    $(DTSDIR)/DTProdPromocion.cpp \
    $(DTSDIR)/DTProdComprado.cpp \
    $(DTSDIR)/DTFecha.cpp \
    $(DTSDIR)/DTDireccion.cpp \
    $(DTSDIR)/DTCompra.cpp \
    $(DTSDIR)/DTComentario.cpp \
    $(DTSDIR)/DTCliente.cpp \
    $(PRESENTACIONDIR)/Menu.cpp \
    $(PRESENTACIONDIR)/ConsultarProducto.cpp \
    $(PRESENTACIONDIR)/CrearPromocion.cpp \
    $(PRESENTACIONDIR)/ConsultarPromocion.cpp \
    $(DOMINIODIR)/ProdPromocion.cpp \
    $(DOMINIODIR)/ProdComprado.cpp \
    $(DOMINIODIR)/Comentario.cpp \
    $(DOMINIODIR)/Promocion.cpp \
    $(PRESENTACIONDIR)/EnviarProducto.cpp \
    $(PRESENTACIONDIR)/RealizarCompra.cpp \
    $(PRESENTACIONDIR)/DejarComentario.cpp \
    $(PRESENTACIONDIR)/EliminarComentario.cpp \
    $(PRESENTACIONDIR)/ExpedienteUsuario.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = Dis_EjemploArquitecturaLogin

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXSTANDARD) $(INCLUDE_PATHS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)