# Nombre del ejecutable
TARGET = Dis_EjemploArquitecturaLogin

# Compilador
CXX = g++

# Flags
CXXFLAGS = -std=c++17 -Wall -g -I./src -I./src/DTs -I./src/logica/controlador -I./src/logica/dominio -I./src/presentacion

# Todos los archivos fuente
SRCS = $(wildcard src/*.cpp) \
       $(wildcard src/DTs/*.cpp) \
       $(wildcard src/logica/controlador/*.cpp) \
       $(wildcard src/logica/dominio/*.cpp) \
       $(wildcard src/presentacion/*.cpp)

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla principal
all: $(TARGET)

# Compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar cada archivo fuente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar objetos y binario
clean:
	rm -f $(TARGET) $(OBJS)
