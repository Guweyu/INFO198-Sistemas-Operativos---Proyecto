# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -I../common

# Directorios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
COMMON_DIR = ../common

# Archivos fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(COMMON_DIR)/user_utils.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))
OBJECTS := $(OBJECTS:$(COMMON_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Ejecutable final
TARGET = $(BIN_DIR)/app2

# Regla principal
all: $(TARGET)

# Linkeo
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilación de entrega2/src
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de common/
$(OBJ_DIR)/%.o: $(COMMON_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Ejecutar
run: all
	./$(TARGET)
