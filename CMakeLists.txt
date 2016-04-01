cmake_minimum_required(VERSION 3.0)

project(exar CXX)
set(PROJECT_VERSION "0.1")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## Configure flags from llvm-config. See cmake/Findllvm-config.cmake
find_package(llvm-config REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CONFIG_CXXFLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LLVM_CONFIG_LINKER_FLAGS}")

## All plugins here
add_subdirectory(print-fns)
add_subdirectory(exar-lower)
add_library(${PROJECT_NAME} SHARED
  $<TARGET_OBJECTS:print-fns>
  $<TARGET_OBJECTS:exar-lower>
)


## Manually add LLVM/clang libraries.
# There should be a better way of doing this. `llvm-config --libs seems to only
# include the LLVM*-libraries
target_link_libraries(${PROJECT_NAME} ${LLVM_CONFIG_EXTRA_LIBRARIES})
