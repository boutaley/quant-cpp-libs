#include <benchmark/benchmark.h>
#include <libmath/combinatorics.hpp>

using namespace by_combinatorics;   

// Bench function for iterative version O(n)
static void BM_FactorialIterative(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(factorial(state.range(0)));
}

BENCHMARK(BM_FactorialIterative)->Arg(10)->Arg(15)->Arg(20);

BENCHMARK_MAIN();
