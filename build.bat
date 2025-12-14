@echo off
REM Build Script for SiJamBuApp - Windows Batch
REM This script compiles the project with g++ compiler
REM Usage: build.bat

echo.
echo ================================
echo SiJamBuApp - Build Script
echo ================================
echo.

REM Check if g++ is available
g++ --version >nul 2>&1
if errorlevel 1 (
    echo ERROR: g++ compiler not found in PATH
    echo Please install MinGW or configure your PATH environment variable
    pause
    exit /b 1
)

REM Create build directory if it doesn't exist
if not exist "build" mkdir build

REM Display compilation status
echo Building SiJamBuApp...
echo Compiler: g++ C++17
echo Source files: src/*.cpp
echo Header files: include/*.h
echo Output: build/SiJamBu.exe
echo.

REM Compile the project
g++ -std=c++17 -Wall -Wextra -I include src/*.cpp -o build/SiJamBu.exe 2>&1

REM Check compilation result
if errorlevel 1 (
    echo.
    echo BUILD FAILED - Compilation errors detected
    echo Please check the error messages above
    pause
    exit /b 1
) else (
    echo.
    echo ================================
    echo BUILD SUCCESSFUL!
    echo ================================
    echo.
    echo Executable created: build\SiJamBu.exe
    echo.
    echo To run the application:
    echo   build\SiJamBu.exe
    echo.
    pause
)
