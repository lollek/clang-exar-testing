file(GLOB LOCAL_SUBDIRECTORIES
  RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(subdir ${LOCAL_SUBDIRECTORIES})
  if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}")

    add_subdirectory(${subdir})
    list(APPEND PLUGINS "$<TARGET_OBJECTS:${subdir}>")

  endif()
endforeach()

add_library(${PROJECT_NAME} SHARED ${PLUGINS})
target_link_libraries(${PROJECT_NAME} ${LLVM_CONFIG_EXTRA_LIBRARIES})
