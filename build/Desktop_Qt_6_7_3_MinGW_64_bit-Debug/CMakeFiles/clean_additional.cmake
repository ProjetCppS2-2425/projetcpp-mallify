# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\boutique1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\boutique1_autogen.dir\\ParseCache.txt"
  "boutique1_autogen"
  )
endif()
