cmake_minimum_required(VERSION 3.25)

# Global project name
project(quant_workspace LANGUAGES CXX)

# C++20 is required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(libmath)
add_subdirectory(benchmarks)
add_subdirectory(tests)
