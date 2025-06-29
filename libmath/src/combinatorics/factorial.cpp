#include <stdexcept>
#include <cstdint>
#include <libmath/combinatorics.hpp>

namespace by_combinatorics {

    [[nodiscard]]
    uint64_t factorial(uint32_t n) {
		if (n > 20) {
			throw std::overflow_error("Factorial exceeds 64-bit range");
		}
		if (n <= 1) {
			return 1; 
		}
		uint64_t result = 1;
		for (uint32_t i = 2; i <= n; ++i) {
			result *= i;
		}
		return result;
    }

}