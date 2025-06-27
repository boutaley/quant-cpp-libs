# pragma once
#include <vector>
#include <optional>


namespace fibo {

	uint64_t fibonacci_iterative(int n);
	uint64_t fibonacci_recursive(int n);
	uint64_t fibonacci_memoized(int n);
	uint64_t fibonacci_memoized(int n, std::optional<std::vector<int>>& memo);
	uint64_t fibonacci_fast(int n);

}
