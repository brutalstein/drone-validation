FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential cmake ninja-build git ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY . .
RUN cmake -S . -B build -G Ninja -DSENTINEL_BUILD_TESTS=ON \
    && cmake --build build \
    && ctest --test-dir build --output-on-failure

ENTRYPOINT ["/workspace/build/sentinel-cli"]
