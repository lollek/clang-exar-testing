cmake_minimum_required(VERSION 3.0)

project(exar CXX)
set(PROJECT_VERSION "0.1")

## Set llvm-config
find_program(llvm-config llvm-config)
if(NOT EXISTS "${llvm-config}")
  message(FATAL_ERROR "Could not find llvm-config")
endif()


message(STATUS "Settings compiler flags from llvm-config --cxxflags")
execute_process(
  COMMAND ${llvm-config} --cxxflags
  OUTPUT_VARIABLE llvm_config_cxxflags
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${llvm_config_cxxflags}")
if(llvm_config_cxxflags STREQUAL "")
  message(FATAL_ERROR "No CMAKE_CXX_FLAGS generated")
endif()


message(STATUS "Settings linker flags from llvm-config --system-libs")
execute_process(
  COMMAND ${llvm-config} --system-libs
  OUTPUT_VARIABLE llvm_config_system_libs
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${llvm_config_system_libs}")
if(llvm_config_system_libs STREQUAL "")
  message(FATAL_ERROR "No CMAKE_SHARED_LINKER_FLAGS generated")
endif()


file(GLOB_RECURSE PROJECT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/source/*.cc")
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES})


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
