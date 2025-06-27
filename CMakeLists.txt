cmake_minimum_required(VERSION 3.25)

# Nom global de ton workspace CMake
project(quant_workspace LANGUAGES CXX)

# Demande le C++20 partout (ou 17 si tu préfères)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajoute chaque sous-librairie au build
add_subdirectory(libmath)
add_subdirectory(benchmarks)
add_subdirectory(tests)
