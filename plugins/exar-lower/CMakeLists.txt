file(GLOB_RECURSE LOCAL_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(LIBRARY_NAME "exar-lower")

add_library(${LIBRARY_NAME} OBJECT ${LOCAL_SOURCE_FILES})

eztest_add(${LIBRARY_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/test")
