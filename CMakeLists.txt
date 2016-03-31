cmake_minimum_required(VERSION 3.0)

project(exar CXX)
set(PROJECT_VERSION "0.1")

### I have compiled clang myself here.
# TODO: Fix for general installations
set(LLVM_SRC_DIR "${PROJECT_SOURCE_DIR}/llvm_src")
set(CLANG_SRC_DIR "${LLVM_SRC_DIR}/tools/clang")
set(LLVM_BUILD_DIR "${PROJECT_SOURCE_DIR}/llvm_build")
set(CLANG_BUILD_DIR "${LLVM_BUILD_DIR}/tools/clang")
include_directories(
  "${LLVM_SRC_DIR}/include"
  "${CLANG_SRC_DIR}/include"
  "${LLVM_BUILD_DIR}/include"
  "${CLANG_BUILD_DIR}/include"
  )
link_directories(
  "${LLVM_BUILD_DIR}/lib"
  )


## Set llvm-config
find_program(llvm-config
  NAMES llvm-config
  PATHS "${LLVM_BUILD_DIR}/bin"
  )
if(NOT EXISTS "${llvm-config}")
  message(FATAL_ERROR "Could not find llvm-config")
endif()

## Set compiler flags flags from `llvm-config --cxxflags`
execute_process(
  COMMAND ${llvm-config} --cxxflags
  OUTPUT_VARIABLE llvm_config_cxxflags
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${llvm_config_cxxflags}")
if(llvm_config_cxxflags STREQUAL "")
  message(FATAL_ERROR "No CMAKE_CXX_FLAGS generated")
endif()

add_library(${PROJECT_NAME} SHARED
  PrintFunctionNames.cpp
  NoLowerCaseClassNames.cpp
  )

## Set linker flags from `llvm-config --system-libs`
execute_process(
  COMMAND ${llvm-config} --system-libs
  OUTPUT_VARIABLE llvm_config_system_libs
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${llvm_config_system_libs}")
if(llvm_config_system_libs STREQUAL "")
  message(FATAL_ERROR "No CMAKE_SHARED_LINKER_FLAGS generated")
endif()

## Manually add loads of libraries.
# There should be a better way of doing this. `llvm-config --libs seems to only
# include the LLVM*-libraries
target_link_libraries(${PROJECT_NAME}
  LLVMMCParser
  LLVMMC
  LLVMSupport
  LLVMBitReader
  LLVMOption
  clangFrontend
  clangAST
  clangAnalysis
  clangBasic
  clangDriver
  clangLex
  clangParse
  clangSema
  clangEdit
  clangSerialization
  )
