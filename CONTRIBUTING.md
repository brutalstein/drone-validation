# Contributing

Read AGENTS.md and relevant ADRs before architectural work.

Local checks:

cmake -S . -B build -DSENTINEL_BUILD_TESTS=ON
cmake --build build -j
ctest --test-dir build --output-on-failure

Pull requests should explain:
- engineering problem;
- behavior change;
- evidence/schema impact;
- replay/determinism impact;
- tests;
- compatibility.

New middleware, simulator, autopilot or hardware integrations must be adapters.
