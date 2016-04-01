file(GLOB_RECURSE LOCAL_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(exar-lower OBJECT ${LOCAL_SOURCE_FILES})
