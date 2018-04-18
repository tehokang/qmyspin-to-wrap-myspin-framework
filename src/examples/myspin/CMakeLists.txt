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
    ${CMAKE_SOURCE_DIR}/3rdparty/myspin/1.2.3/arm/32bit/debug/lib
)

set(SOURCE_FILES ${SOURCE_FILES} main.cpp)

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
