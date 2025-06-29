#include <benchmark/benchmark.h>
#include <libmath/combinatorics.hpp>

using namespace by_combinatorics;

/* --------------------------------------------------------------------
   1)  Appel isolé  C(n,k)
   ------------------------------------------------------------------ */
static void BM_BinomialSingle(benchmark::State& state)
{
    const std::uint32_t n = static_cast<std::uint32_t>(state.range(0));
    const std::uint32_t k = static_cast<std::uint32_t>(state.range(1));

    for (auto _ : state)
        benchmark::DoNotOptimize(binomial(n, k));
}

//              n    k         (n,k) choisis pour rester < 2^64
BENCHMARK(BM_BinomialSingle)->Args({ 20, 10 });
BENCHMARK(BM_BinomialSingle)->Args({ 40, 20 });
BENCHMARK(BM_BinomialSingle)->Args({ 60, 15 });

/* --------------------------------------------------------------------
   2)  Génération de toute la ligne  C(n,0..n)
       (on ré-utilise binomial pour chaque k, donc O(n^2) au total)
   ------------------------------------------------------------------ */
static void BM_BinomialRow(benchmark::State& state)
{
    const std::uint32_t n = static_cast<std::uint32_t>(state.range(0));

    for (auto _ : state)
    {
        for (std::uint32_t k = 0; k <= n; ++k)
            benchmark::DoNotOptimize(binomial(n, k));
    }
}

BENCHMARK(BM_BinomialRow)->Arg(20)->Arg(40)->Arg(60);

BENCHMARK_MAIN();
