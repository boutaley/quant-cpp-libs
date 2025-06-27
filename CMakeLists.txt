cmake_minimum_required(VERSION 3.25)

# Global project name
project(quant_workspace LANGUAGES CXX)

# C++20 is required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Enable CTest so add_test() actually registers tests
include(CTest)

# Add subdirectories
add_subdirectory(libmath)
add_subdirectory(benchmarks)
add_subdirectory(tests)
