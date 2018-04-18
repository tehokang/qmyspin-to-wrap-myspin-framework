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
    ${CMAKE_SOURCE_DIR}/src/utility
    ${CMAKE_SOURCE_DIR}/3rdparty/myspin/1.2.3/arm/32bit/debug/include
)

include_directories(
    ${INCPATHS}
)

set(SOURCE_FILES ${SOURCE_FILES} ProjectionHandler.cpp ProjectionFactory.cpp)
set(SOURCE_FILES ${SOURCE_FILES} abalta/AbaltaHandler.cpp)
set(SOURCE_FILES ${SOURCE_FILES} cinemo/CinemoHandler.cpp)
set(SOURCE_FILES ${SOURCE_FILES} myspin/mySPINHandler.cpp)
set(SOURCE_FILES ${SOURCE_FILES} sdl/SdlHandler.cpp)

link_directories(
    ${BIUILD_SRC_DIR}/utility
)

#=======================================================================================
# Build sources
#=======================================================================================
add_library(projection-handler SHARED ${SOURCE_FILES})

target_link_libraries(projection-handler
    utility
)
#=====================================================================================
# Install
#=====================================================================================
