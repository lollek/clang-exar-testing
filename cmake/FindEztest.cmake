find_program(eztest
  eztest
  PATH "${CMAKE_SOURCE_DIR}/lib"
)

# TODO: Autofind the /libexar.so
function(eztest_add plugin_name test_path)
  file(GLOB eztest_subdirs
    RELATIVE "${test_path}" "${test_path}/*")

  foreach(subdir ${eztest_subdirs})
    if(IS_DIRECTORY "${test_path}/${subdir}")
      add_test("${plugin_name}/${subdir}"
        ${eztest}
        ${clang}
        "${CMAKE_BINARY_DIR}/libexar.so"
        ${plugin_name}
        "${test_path}/${subdir}"
      )
    endif()
  endforeach()

endfunction()
