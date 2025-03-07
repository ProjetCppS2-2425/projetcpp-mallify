# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Reclamation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Reclamation_autogen.dir\\ParseCache.txt"
  "Reclamation_autogen"
  )
endif()
