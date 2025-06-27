# quant-cpp-libs

A collection of finance‑oriented C++ libraries built with modern tooling (CMake, GoogleTest, Google Benchmark). Each module is self‑contained, unit‑tested and benchmarked.

---

## Modules

| Library    | Status  | Description                                                          |
| ---------- | ------- | -------------------------------------------------------------------- |
| libmath    | ready   | Fibonacci algorithms (iterative, recursive, memoized, fast‑doubling) |
| pricinglib | planned | Vanilla option pricing, greeks, hedging utilities                    |
| ...        | pending | Future quantitative utilities                                        |

---

## Build

### Linux / macOS

```bash
git clone https://github.com/boutaley/quant-cpp-libs.git
cd quant-cpp-libs
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

### Windows (Visual Studio 2022)

1. File > Open > Folder... and select the repository root.
2. Choose the `x64-Release` CMake preset in the toolbar.
3. Click **Generate**, then **Build**.
   All targets (`libmath`, tests, benchmarks) are produced in `out/build/<preset>`.

---

## Tests

```bash
ctest --test-dir build --output-on-failure
```

Or in Visual Studio: Test > Run All Tests.

---

## Benchmarks

```bash
# after building in Release
./build/bench/bench_fibo --benchmark_min_time=0.1
```

The executable prints nanosecond timings for each Fibonacci variant at several input sizes.

---

## Contributing

Issues and pull requests are welcome. Please follow the existing coding style (clang-format defaults) and ensure

```bash
cmake --build build --target check
```

passes before opening a PR.

---

## License

Distributed under the MIT License. See `LICENSE` for details.
