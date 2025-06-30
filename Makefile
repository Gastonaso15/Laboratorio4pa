# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Isrc

# Archivos fuente
SRC = $(wildcard src/*.cpp src/DTs/*.cpp src/logica/controlador/*.cpp src/logica/dominio/*.cpp src/presentacion/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
TARGET = 5v_lab4

# Regla principal
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Cómo compilar cada archivo .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJ) $(TARGET)
