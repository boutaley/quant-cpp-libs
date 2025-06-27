#include <benchmark/benchmark.h>
#include <libmath/fibonacci.hpp>

using namespace fibo;   // raccourci

// Fonction de bench pour la version itérative
static void BM_FiboIterative(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_iterative(state.range(0)));
}

// Fonction de bench pour la version recursive
static void BM_FiboRecursive(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_recursive(state.range(0)));
}

// Fonction de bench pour la version memoized
static void BM_FiboMemoized(benchmark::State& state)
{
    for (auto _ : state)
        benchmark::DoNotOptimize(fibonacci_memoized(state.range(0)));
}
// Fonction de bench pour la version fast
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
