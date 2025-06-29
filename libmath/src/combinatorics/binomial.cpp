#include <cstdint>
#include <stdexcept>
#include <numeric>          
#include <limits>
#include <libmath/combinatorics.hpp>

namespace by_combinatorics {

    
    constexpr std::uint64_t U64_MAX = std::numeric_limits<std::uint64_t>::max();

    /* ===================================================================
       Binomial coefficient C(n,k) –  64 bit version
       =================================================================== */
    [[nodiscard]]
    std::uint64_t binomial(std::uint32_t n, std::uint32_t k)
    {
        if (k > n)
            throw std::invalid_argument("k > n in binomial");

        /* symetrical : C(n,k) = C(n,n-k)  ->  less iterations  */
        k = std::min(k, n - k);
        if (k == 0) return 1;
        if (k == 1) return n;

        std::uint64_t result = 1;

        for (std::uint32_t i = 1; i <= k; ++i)
        {
            std::uint32_t num = n - k + i;   // (n-k+1) ... n
            std::uint32_t den = i;           // 1 ... k

            /* ------------------------------------------------------------
			   using the pgcd to reduce num/den
               ------------------------------------------------------------ */
            auto g1 = std::gcd(num, den); num /= g1; den /= g1;
            auto g2 = std::gcd(result, den); result /= g2; den /= g2;

            /* ------------------------------------------------------------
               Overflow check : result * num  <= UINT64_MAX
               ------------------------------------------------------------ */
#if defined(__SIZEOF_INT128__)
               // Compilos GCC/Clang/MSVC supporting __int128
            unsigned __int128 tmp = static_cast<unsigned __int128>(result) * num;
            if (tmp > U64_MAX)
                throw std::overflow_error("binomial exceeds 64-bit range");
            result = static_cast<std::uint64_t>(tmp);
#else
               // Fallback 
            if (result > U64_MAX / num)
                throw std::overflow_error("binomial exceeds 64-bit range");
            result *= num;
#endif
            result /= den;  
        }
        return result;
    }

} 
