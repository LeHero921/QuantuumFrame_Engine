CXX      = g++
# Hier inkludieren wir nur den Engine-Include-Ordner (und Raylib)
CXXFLAGS = -std=c++20 -Iinclude 

SRC_DIR   = src
BUILD_DIR = build
LIB_DIR   = lib

# Sucht alle Engine-Dateien
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(LIB_DIR)/libquantuum.a

.PHONY: all clean

all: $(TARGET)

# Baut die statische Bibliothek
$(TARGET): $(OBJS)
	@mkdir -p $(LIB_DIR)
	@echo "Archiving QuantuumFrame Engine into $@..."
	@ar rcs $@ $(OBJS)
	@echo "Engine Build Success!"

# Kompiliert die .cpp zu .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling Engine: $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)