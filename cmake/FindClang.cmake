find_program(clang clang)
if(NOT EXISTS "${clang}")
  message(FATAL_ERROR "clang: Not found")
endif()

message(STATUS "Setting compiler to ${clang}")
set(CMAKE_CXX_COMPILER ${clang})
