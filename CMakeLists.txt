cmake_minimum_required(VERSION 3.25)
project(sentinel_twin VERSION 0.1.0 LANGUAGES CXX)

option(SENTINEL_BUILD_TESTS "Build SENTINEL-TWIN tests" ON)
option(SENTINEL_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

add_library(sentinel_core src/core/engine.cpp)
add_library(sentinel::core ALIAS sentinel_core)

target_include_directories(sentinel_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_compile_features(sentinel_core PUBLIC cxx_std_20)

if(MSVC)
  target_compile_options(sentinel_core PRIVATE /W4)
  if(SENTINEL_WARNINGS_AS_ERRORS)
    target_compile_options(sentinel_core PRIVATE /WX)
  endif()
else()
  target_compile_options(sentinel_core PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
  if(SENTINEL_WARNINGS_AS_ERRORS)
    target_compile_options(sentinel_core PRIVATE -Werror)
  endif()
endif()

add_executable(sentinel-cli src/cli/main.cpp)
target_link_libraries(sentinel-cli PRIVATE sentinel::core)

if(SENTINEL_BUILD_TESTS)
  enable_testing()
  add_executable(sentinel-core-tests tests/test_engine.cpp)
  target_link_libraries(sentinel-core-tests PRIVATE sentinel::core)
  add_test(NAME sentinel-core-tests COMMAND sentinel-core-tests)
endif()

install(TARGETS sentinel_core sentinel-cli
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)
