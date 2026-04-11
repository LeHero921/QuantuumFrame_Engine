CXX      = g++
CXXFLAGS = -std=c++20 -Iinclude 

# --- NEU: Linker Flags für den Sandbox-Test ---
# Die brauchen wir, um aus dem Test ein startbares Fenster zu machen
LDFLAGS  = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -Llib -lquantuum -lraylib

SRC_DIR   = src
BUILD_DIR = build
LIB_DIR   = lib
DIST_DIR  = dist

# --- NEU: Sandbox Konfiguration ---
SANDBOX_DIR = test
SANDBOX_SRC = $(SANDBOX_DIR)/test.cpp
TEST_TARGET = $(BUILD_DIR)/engine_test

# Sucht alle Engine-Dateien
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))
TARGET = $(LIB_DIR)/libquantuum.a

# run hinzugefügt
.PHONY: all clean export run 

all: $(TARGET)

# Baut die statische Bibliothek
$(TARGET): $(OBJS)
	@mkdir -p $(LIB_DIR)
	@echo "Archiving QuantuumFrame Engine into $@..."
	@ar rcs $@ $(OBJS)
	@echo "Engine Build Success!"

# Kompiliert die Engine .cpp zu .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling Engine: $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# --- NEU: Baut die Test-Ausführungsdatei ---
# Dieses Ziel hängt davon ab, dass $(TARGET) (die Engine) fertig gebaut ist!
$(TEST_TARGET): $(TARGET) $(SANDBOX_SRC)
	@mkdir -p $(BUILD_DIR)
	@echo "Building Sandbox Test..."
	@$(CXX) $(CXXFLAGS) $(SANDBOX_SRC) $(LDFLAGS) -o $@
	@echo "Sandbox Build Success!"

# --- NEU: Das 'run' Target ---
run: $(TEST_TARGET)
	@echo "Starting Sandbox..."
	@./$(TEST_TARGET)

# dist Ordner beim aufräumen mit löschen
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR) $(DIST_DIR)

export: all
	@echo "Packaging QuantuumFrame Engine..."
	@mkdir -p $(DIST_DIR)/lib
	@mkdir -p $(DIST_DIR)/include/QuantuumFrame
	@cp $(LIB_DIR)/libquantuum.a $(DIST_DIR)/lib/
	@find include -name '*.h' -exec cp {} $(DIST_DIR)/include/QuantuumFrame/ \;
	@echo "Export ready in folder 'dist/'!"