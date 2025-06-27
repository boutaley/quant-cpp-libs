#include <stdexcept>
#include <libmath/fibonacci.hpp>

namespace by_fibonacci {

	uint64_t fibonacci_recursive(uint64_t n) {
	
		if (n > 93) {
			throw std::overflow_error("F(n) exceeds 64-bit range");
		}
		if (n <= 1) {
			return n;
		}
		
		return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);

	}

	uint64_t fibonacci_iterative(uint64_t n) {

		if (n > 93) {
			throw std::overflow_error("F(n) exceeds 64-bit range");
		}
		if (n == 0) {
			return 0;
		}
	
		// prev = F(n-1)
		// curr = F(n)
		uint64_t prev = 0;
		uint64_t curr = 1;
		uint64_t tmp;
		for (int i=1; i<n; i++) {
			tmp = curr;
			curr += prev;
			prev = tmp;
		}
		// curr = F(n)
		return curr;

	}

	static uint64_t fibonacci_memoized(uint64_t n, std::optional<std::vector<uint64_t>>& memo) {

		if (n > 93) {
			throw std::overflow_error("F(n) exceeds 64-bit range");
		}

		if (!memo.has_value()) {
			memo = std::vector<uint64_t>(n + 1, -1);;
		}
		if (memo->size() <= n) {
			memo->resize(n + 1, -1);
		}

		if ((*memo)[n] == -1) {
			if (n <= 1) {
				(*memo)[n] = n;
			}
			else {
				(*memo)[n] = fibonacci_memoized(n - 1, memo) + fibonacci_memoized(n - 2, memo);
			}
		}

		return (*memo)[n];
	}

	uint64_t fibonacci_memoized(uint64_t n) {
		std::optional<std::vector<uint64_t>> memo;
		return fibonacci_memoized(n, memo);
	}

	static std::pair<uint64_t, uint64_t> fib_pair(uint64_t n) {

		if (n == 0) return std::pair(0, 1);

		uint64_t f_k, f_kp1; 

		std::tie(f_k, f_kp1) = fib_pair(n / 2);

		// F(2K) = F(k)*[2*F(k+1) - F(k)]
		uint64_t f_2k = f_k * (2 * f_kp1 - f_k);
		// F(2k+1) = F(k+1)**2 + F(k)**2
		uint64_t f_2kp1 = f_k * f_k + f_kp1 * f_kp1;

		if (n % 2 == 0) {
			return std::pair(f_2k, f_2kp1);
		}
		else {
			return std::pair(f_2kp1, f_2k + f_2kp1);
		}

	}

	uint64_t fibonacci_fast(uint64_t n){
		if (n > 93) {
			throw std::overflow_error("F(n) exceeds 64-bit range");
		}
		return fib_pair(n).first;
	}

}