# --- c++/benchmarks/CMakeLists.txt ---

# 3-1. R�cup�rer Google Benchmark 
include(FetchContent)
FetchContent_Declare(
    gbm
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG        v1.8.4           
)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)  
FetchContent_MakeAvailable(gbm)

# 3-2. D�clarer l�ex�cutable de bench
add_executable(bench_fibo
    bench_fibo.cpp      
)

# 3-3. Lier ta lib + Google Benchmark
target_link_libraries(bench_fibo
    PRIVATE
        libmath          
        benchmark        
)

# 3-4. On veut un ex�cutable Release par d�faut
set_target_properties(bench_fibo PROPERTIES
    CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bench
)
