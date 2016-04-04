cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER clang++)

project(exar CXX)
set(PROJECT_VERSION "0.1")

enable_testing()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Eztest REQUIRED)

## Configure flags from llvm-config. See cmake/Findllvm-config.cmake
# Sets CMAKE_CXX_FLAGS, CMAKE_SHARED_LINKER_FLAGS
# Adds LLVM_CONFIG_EXTRA_LIBRARIES
find_package(llvm-config REQUIRED)

add_subdirectory(plugins)
add_library(${PROJECT_NAME} SHARED ${PLUGINS})
target_link_libraries(${PROJECT_NAME} ${LLVM_CONFIG_EXTRA_LIBRARIES})
