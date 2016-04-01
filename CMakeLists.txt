cmake_minimum_required(VERSION 3.0)

project(exar CXX)
set(PROJECT_VERSION "0.1")

## Testing. Enable with `cmake -Dtest=ON`
if (test)
  find_package(Lit REQUIRED)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## Configure flags from llvm-config. See cmake/Findllvm-config.cmake
# Sets CMAKE_CXX_FLAGS, CMAKE_SHARED_LINKER_FLAGS
# Adds LLVM_CONFIG_EXTRA_LIBRARIES
find_package(llvm-config REQUIRED)

## Find and use clang compiler
find_package(Clang REQUIRED)

add_subdirectory(plugins)
