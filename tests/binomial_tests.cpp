#include <gtest/gtest.h>
#include <libmath/combinatorics.hpp>

using namespace by_combinatorics;

/* --------  Base cases  -------- */
TEST(Binomial, TrivialCases)
{
    for (std::uint32_t n = 0; n <= 20; ++n) {
        EXPECT_EQ(binomial(n, 0), 1);
        EXPECT_EQ(binomial(n, n), 1);
        if (n >= 1) {
            EXPECT_EQ(binomial(n, 1), n);
            EXPECT_EQ(binomial(n, n - 1), n);
        }
    }
}

/* --------  Golden values  -------- */
TEST(Binomial, KnownValues)
{
    EXPECT_EQ(binomial(5, 2), 10);
    EXPECT_EQ(binomial(10, 3), 120);
    EXPECT_EQ(binomial(20, 10), 184756);
}

/* --------  Symmetry check  -------- */
TEST(Binomial, SymmetrySmallRange)
{
    for (std::uint32_t n = 0; n <= 20; ++n)
        for (std::uint32_t k = 0; k <= n; ++k)
            EXPECT_EQ(binomial(n, k), binomial(n, n - k));
}

/* --------  Invalid input  -------- */
TEST(Binomial, InvalidInputThrows)
{
    EXPECT_THROW(binomial(6, 9), std::invalid_argument);   // k > n
}

/* --------  Overflow guard  -------- */
TEST(Binomial, OverflowThrows)
{
    EXPECT_THROW(binomial(68, 34), std::overflow_error);   // > 64-bit
}
