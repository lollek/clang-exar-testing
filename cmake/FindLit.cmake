find_program(LIT lit
  NAMES llvm-lit lit
)

if(NOT EXISTS "${LIT}")
  message(FATAL_ERROR "lit: Not installed. Can be installed from "
                      "https://pypi.python.org/pypi/lit")
endif()

