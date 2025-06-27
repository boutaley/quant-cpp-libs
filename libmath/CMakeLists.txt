# --- c++/libmath/CMakeLists.txt ---

# Static lib 
add_library(libmath STATIC
    src/fibonacci.cpp    
)

# Public headers
target_include_directories(libmath
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>          
)


target_compile_features(libmath PUBLIC cxx_std_20)
set_target_properties(libmath PROPERTIES POSITION_INDEPENDENT_CODE ON)
