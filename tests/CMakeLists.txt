include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Single test executable with all features
add_executable(unit_tests
    fibo_tests.cpp
    factorial_tests.cpp
    binomial_tests.cpp
)

target_link_libraries(unit_tests
    PRIVATE
        libmath
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
