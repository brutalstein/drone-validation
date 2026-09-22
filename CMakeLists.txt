cmake_minimum_required(VERSION 3.25)
project(sentinel_twin VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(SENTINEL_BUILD_TESTS "Build SENTINEL-TWIN tests" ON)
option(SENTINEL_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

add_library(sentinel_core src/core/engine.cpp)
add_library(sentinel::core ALIAS sentinel_core)
set_target_properties(sentinel_core PROPERTIES EXPORT_NAME core)

target_include_directories(sentinel_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
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

install(TARGETS sentinel_core
  EXPORT SentinelTwinTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(TARGETS sentinel-cli RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_package_config_file(
  cmake/SentinelTwinConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/SentinelTwinConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SentinelTwin
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/SentinelTwinConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(EXPORT SentinelTwinTargets
  FILE SentinelTwinTargets.cmake
  NAMESPACE sentinel::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SentinelTwin
)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/SentinelTwinConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/SentinelTwinConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SentinelTwin
)
