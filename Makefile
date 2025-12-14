# Makefile for SiJamBuApp - Linux/macOS/Windows (with MinGW)
# Usage: make          (build the project)
#        make run      (build and run)
#        make clean    (remove build artifacts)
#        make help     (show this help)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
INCLUDES = -I include
SOURCES = src/*.cpp
OUTPUT = build/SiJamBu
OUTPUT_WIN = build/SiJamBu.exe

# Detect OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    TARGET = $(OUTPUT)
endif
ifeq ($(UNAME_S),Darwin)
    TARGET = $(OUTPUT)
endif
ifeq ($(OS),Windows_NT)
    TARGET = $(OUTPUT_WIN)
endif

# Default target
.PHONY: all
all: $(TARGET)
	@echo ""
	@echo "================================"
	@echo "BUILD SUCCESSFUL!"
	@echo "================================"
	@echo ""
	@echo "To run the application:"
ifeq ($(OS),Windows_NT)
	@echo "  $(OUTPUT_WIN)"
else
	@echo "  ./$(OUTPUT)"
endif
	@echo ""

# Build target
$(TARGET): src/*.cpp include/*.h
	@echo "Building SiJamBuApp..."
	@echo "Compiler: $(CXX) $(CXXFLAGS)"
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET)
	@echo "Executable created: $(TARGET)"

# Run target
.PHONY: run
run: $(TARGET)
	@echo ""
	@echo "Running SiJamBuApp..."
	@echo ""
ifeq ($(OS),Windows_NT)
	$(OUTPUT_WIN)
else
	./$(OUTPUT)
endif

# Clean target
.PHONY: clean
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf build/
	@echo "Clean complete"

# Help target
.PHONY: help
help:
	@echo "SiJamBuApp - Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Build the project"
	@echo "  make run          - Build and run the application"
	@echo "  make clean        - Remove build artifacts"
	@echo "  make help         - Show this help message"
	@echo ""
	@echo "Requirements:"
	@echo "  - g++ compiler with C++17 support"
	@echo "  - make (make or mingw32-make)"
	@echo ""
