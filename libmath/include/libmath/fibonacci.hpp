# pragma once
#include <vector>
#include <optional>


namespace by_fibonacci {

	// O(n)
	uint64_t fibonacci_iterative(uint64_t n);
	// O(2^n)
	uint64_t fibonacci_recursive(uint64_t n);
	// O(n)
	uint64_t fibonacci_memoized(uint64_t n);
	// O(logn)
	uint64_t fibonacci_fast(uint64_t n);

}
