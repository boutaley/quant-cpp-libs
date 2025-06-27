include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0   
)
FetchContent_MakeAvailable(googletest)

add_executable(fibo_tests
    fibo_tests.cpp       
)

target_link_libraries(fibo_tests
    PRIVATE
        libmath
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(fibo_tests)

