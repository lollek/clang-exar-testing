file(GLOB LOCAL_SUBDIRECTORIES
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(subdir ${LOCAL_SUBDIRECTORIES})
  if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}")
    add_subdirectory(${subdir})
    list(APPEND PLUGINS "$<TARGET_OBJECTS:${subdir}>")
  endif()
endforeach()

set(PLUGINS ${PLUGINS} PARENT_SCOPE)
