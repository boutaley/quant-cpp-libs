#include <benchmark/benchmark.h>
#include <libmath/fibonacci.hpp>

using namespace by_fibonacci;   

// Bench function for iterative version O(n)
static void BM_FiboIterative(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_iterative(state.range(0)));
}

// Bench function for recursive version O(2^n)
static void BM_FiboRecursive(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_recursive(state.range(0)));
}

// Bench function for memoized version O(n)
static void BM_FiboMemoized(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_memoized(state.range(0)));
}
// Bench function for fast version O(logn)
static void BM_FiboFast(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_fast(state.range(0)));
}

BENCHMARK(BM_FiboIterative)->Arg(30)->Arg(40)->Arg(45);
BENCHMARK(BM_FiboRecursive)->Arg(30)->Arg(40)->Arg(45);
BENCHMARK(BM_FiboMemoized)->Arg(30)->Arg(40)->Arg(45);
BENCHMARK(BM_FiboFast)->Arg(30)->Arg(40)->Arg(45);

BENCHMARK_MAIN();
