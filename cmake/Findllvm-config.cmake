find_program(llvm-config llvm-config)
if(NOT EXISTS "${llvm-config}")
  message(FATAL_ERROR "llvm-config: Not found")
endif()

message(STATUS "Setting compiler flags from llvm-config --cxxflags")
execute_process(
  COMMAND ${llvm-config} --cxxflags
  OUTPUT_VARIABLE LLVM_CONFIG_CXXFLAGS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(llvm_config_cxxflags STREQUAL "")
  message(FATAL_ERROR "llvm-config: No CMAKE_CXX_FLAGS generated")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CONFIG_CXXFLAGS}")

message(STATUS "Setting linker flags from llvm-config --system-libs")
execute_process(
  COMMAND ${llvm-config} --system-libs
  OUTPUT_VARIABLE LLVM_CONFIG_LINKER_FLAGS
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(llvm_config_system_libs STREQUAL "")
  message(FATAL_ERROR "No CMAKE_SHARED_LINKER_FLAGS generated")
endif()
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LLVM_CONFIG_LINKER_FLAGS}")

## Manually add LLVM/clang libraries.
# There should be a better way of doing this. `llvm-config --libs seems to only
# include the LLVM*-libraries
set(LLVM_CONFIG_EXTRA_LIBRARIES
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
