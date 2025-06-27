#include <gtest/gtest.h>
#include <libmath/fibonacci.hpp>   

using namespace fibo;              

/* --------  Cas de base  -------- */
TEST(FibonacciIterative, BaseCases)
{
    EXPECT_EQ(fibonacci_iterative(0), 0);
    EXPECT_EQ(fibonacci_iterative(1), 1);
}

TEST(FibonacciRecursive, BaseCases)
{
    EXPECT_EQ(fibonacci_recursive(0), 0);
    EXPECT_EQ(fibonacci_recursive(1), 1);
}

TEST(FibonacciMemoized, BaseCases)
{
    EXPECT_EQ(fibonacci_memoized(0), 0);
    EXPECT_EQ(fibonacci_memoized(1), 1);
}

TEST(FibonacciFast, BaseCases)
{
    EXPECT_EQ(fibonacci_fast(0), 0);
    EXPECT_EQ(fibonacci_fast(1), 1);
}

/* --------  Valeurs petites / croisées  -------- */
TEST(FibonacciCrossCheck, SmallValues)
{
    for (int n = 0; n <= 15; ++n)
    {
        EXPECT_EQ(fibonacci_iterative(n), fibonacci_recursive(n));
        EXPECT_EQ(fibonacci_iterative(n), fibonacci_memoized(n));
        EXPECT_EQ(fibonacci_iterative(n), fibonacci_fast(n));
    }
}

/* --------  Gestion des entrées invalides  -------- */
TEST(Fibonacci, NegativeInputThrows)
{
    EXPECT_THROW(fibonacci_iterative(-3), std::invalid_argument);
    EXPECT_THROW(fibonacci_recursive(-3), std::invalid_argument);
    EXPECT_THROW(fibonacci_memoized(-3), std::invalid_argument);
    EXPECT_THROW(fibonacci_fast(-3), std::invalid_argument);
}

/* --------  Valeur connue « golden »  -------- */
TEST(FibonacciIterative, KnownValue)
{
    // F(30) = 832040
    EXPECT_EQ(fibonacci_iterative(30), 832040);
}
