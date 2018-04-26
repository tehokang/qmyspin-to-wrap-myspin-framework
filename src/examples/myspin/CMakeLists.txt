cmake_minimum_required(VERSION 2.8)

#=====================================================================================
# Version
#=====================================================================================

#=====================================================================================
# Build Options
#=====================================================================================

#=====================================================================================
# Sub directories
#=====================================================================================
set(INCPATHS
  ${CMAKE_SOURCE_DIR}/src/export/include
  ${CMAKE_SOURCE_DIR}/src/utility/
)

include_directories(
    ${INCPATHS}
)

link_directories(
    ${BIUILD_SRC_DIR}/export
    ${BIUILD_SRC_DIR}/projection-handler
    ${BIUILD_SRC_DIR}/transport-adapter
    ${BIUILD_SRC_DIR}/utility
    ${LIBUSB_LIB}
    ${MYSPIN_LIB}
)

set(SOURCE_FILES ${SOURCE_FILES} main.cpp)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")

#=======================================================================================
# Build sources
#=======================================================================================

add_executable(example-myspin ${SOURCE_FILES})

target_link_libraries(example-myspin
  projection-export
  projection-handler
  transport-adapter
  utility
  mySPIN-Core
)

#=====================================================================================
# Install
#=====================================================================================
