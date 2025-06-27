#include <stdexcept>
#include <libmath/fibonacci.hpp>

namespace fibo {

	uint64_t fibonacci_recursive(int n) {
	
		if (n < 0) {
			throw std::invalid_argument("fibonacci's input should be >= 0");
		}
		if (n <= 1) {
			return n;
		}
		
		return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);

	}

	uint64_t fibonacci_iterative(int n) {

		if (n < 0) {
			throw std::invalid_argument("fibonacci's input should be >= 0");
		}
		if (n == 0) {
			return 0;
		}
	
		// prev = F(n-1)
		// curr = F(n)
		int prev = 0;
		int curr = 1;
		int tmp;
		for (int i=1; i<n; i++) {
			tmp = curr;
			curr += prev;
			prev = tmp;
		}
		// curr = F(n)
		return curr;

	}

	uint64_t fibonacci_memoized(int n) {
		std::optional<std::vector<int>> memo;
		return fibonacci_memoized(n, memo);
	}

	uint64_t fibonacci_memoized(int n, std::optional<std::vector<int>>& memo) {

		if(n<0) throw std::invalid_argument("fibonacci's input should be >= 0");

		if (!memo.has_value()) {
			memo = std::vector<int>(n + 1, -1);;
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

	static std::pair<uint64_t, uint64_t> fib_pair(int n) {

		if (n == 0) return std::pair(0, 1);

		uint64_t a, b; // a=F(k), b=F(k+1)

		std::tie(a, b) = fib_pair(n / 2);

		// c = F(2K) = F(k)*[2*F(k+1) - F(k)]
		uint64_t c = a * (2 * b - a);
		// d = F(2k+1) = F(k+1)**2 + F(k)**2
		uint64_t d = a * a + b * b;

		if (n % 2 == 0) {
			return std::pair(c, d);
		}
		else {
			return std::pair(d, c + d);
		}

	}

	uint64_t fibonacci_fast(int n){
		if (n < 0) throw std::invalid_argument("fibonacci's input should be >= 0");
		return fib_pair(n).first;
	}

}