cmake_minimum_required(VERSION 3.10)
project(SiJamBuApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/Buku.cpp
    src/User.cpp
    src/Admin.cpp
    src/SistemPeminjaman.cpp
    src/TransaksiPeminjaman.cpp
    src/Controller.cpp
    src/PenyimpananFile.cpp
)

# Create executable
add_executable(SiJamBu ${SOURCES})

# Set output directory
set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
)

# Print build info
message(STATUS "SiJamBuApp Build Configuration")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
