#!/bin/bash
# Build Script for SiJamBuApp - Linux/macOS Bash
# This script compiles the project with g++ compiler
# Usage: ./build.sh

echo ""
echo "================================"
echo "SiJamBuApp - Build Script"
echo "================================"
echo ""

# Check if g++ is available
if ! command -v g++ &> /dev/null
then
    echo "ERROR: g++ compiler not found"
    echo "Please install GCC/G++ compiler:"
    echo "  Ubuntu/Debian: sudo apt-get install g++"
    echo "  macOS: brew install gcc"
    exit 1
fi

# Create build directory if it doesn't exist
mkdir -p build

# Display compilation status
echo "Building SiJamBuApp..."
echo "Compiler: g++ C++17"
echo "Source files: src/*.cpp"
echo "Header files: include/*.h"
echo "Output: build/SiJamBu"
echo ""

# Compile the project
g++ -std=c++17 -Wall -Wextra -I include src/*.cpp -o build/SiJamBu 2>&1

# Check compilation result
if [ $? -ne 0 ]; then
    echo ""
    echo "================================"
    echo "BUILD FAILED - Compilation errors detected"
    echo "================================"
    exit 1
else
    echo ""
    echo "================================"
    echo "BUILD SUCCESSFUL!"
    echo "================================"
    echo ""
    echo "Executable created: build/SiJamBu"
    echo ""
    echo "To run the application:"
    echo "  ./build/SiJamBu"
    echo ""
fi
