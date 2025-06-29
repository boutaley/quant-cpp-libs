#include <gtest/gtest.h>
#include <libmath/combinatorics.hpp>   

using namespace by_combinatorics;

/* --------  Cas de base  -------- */
TEST(FactorialIterative, BaseCases)
{
    EXPECT_EQ(factorial(0), 1);
    EXPECT_EQ(factorial(1), 1);
}

/* --------  Invalid input (overflow) -------- */
TEST(FactorialOverFlow, OverflowThrows)
{
    EXPECT_THROW(factorial(21), std::overflow_error);
    EXPECT_THROW(factorial(30), std::overflow_error);
    EXPECT_THROW(factorial(100), std::overflow_error);
}


/* --------  Valeur connue « golden »  -------- */
TEST(FactorialGoldenValue, KnownValue)
{
    EXPECT_EQ(factorial(10), 3628800ull);
    EXPECT_EQ(factorial(20), 2432902008176640000ull);
}
