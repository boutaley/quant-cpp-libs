#pragma once
#include <cstdint>
#include <initializer_list>



namespace by_combinatorics {

    /*==========================================================
      Factorial and classic counting helpers
      ==========================================================*/

      /** @brief n!  (0 <= n <= 20 fits into 64-bit) */
    [[nodiscard]] std::uint64_t factorial(std::uint32_t n);

    /** @brief Binomial coefficient “n choose k”.
        Valid for 0 <= k <= n <= 20 (64-bit safe). */
    [[nodiscard]] std::uint64_t binomial(std::uint32_t n, std::uint32_t k);

    /** @brief Permutations without repetition:  P(n,k) = n! / (n-k)! */
    [[nodiscard]] std::uint64_t permutations(std::uint32_t n, std::uint32_t k);

    /*==========================================================
      Advanced counts
      ========================================================== */

      /** @brief Multinomial coefficient
                (n1+n2+...+nm)! / (n1!*n2!*...*nm!)
          `counts` must sum to <= 20 to avoid 64-bit overflow. */
    [[nodiscard]] std::uint64_t multinomial(std::initializer_list<std::uint32_t> counts);

    /** @brief nth Catalan number (C_n) for small n (n <= 14 fits in 64-bit). */
    [[nodiscard]] std::uint64_t catalan(std::uint32_t n);

}
