#include <gtest/gtest.h>
#include <libmath/fibonacci.hpp>   

using namespace by_fibonacci;

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
    for (uint64_t n = 0; n <= 15; ++n)
    {
        EXPECT_EQ(fibonacci_iterative(n), fibonacci_recursive(n));
        EXPECT_EQ(fibonacci_iterative(n), fibonacci_memoized(n));
        EXPECT_EQ(fibonacci_iterative(n), fibonacci_fast(n));
    }
}

/* --------  Invalid input (overflow) -------- */
TEST(Fibonacci, OverflowThrows)
{
    EXPECT_THROW(fibonacci_iterative(94), std::overflow_error);
    EXPECT_THROW(fibonacci_recursive(94), std::overflow_error);
    EXPECT_THROW(fibonacci_memoized(94), std::overflow_error);
    EXPECT_THROW(fibonacci_fast(94), std::overflow_error);
}


/* --------  Valeur connue « golden »  -------- */
TEST(FibonacciIterative, KnownValue)
{
    // F(30) = 832040
    EXPECT_EQ(fibonacci_iterative(30), 832040);
}
