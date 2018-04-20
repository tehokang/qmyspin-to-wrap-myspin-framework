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
set (LIBUSB_LIB
  # For Raspberry pi3
  #${CMAKE_SOURCE_DIR}/3rdparty/libusb/1.0/pi3/32bit/lib
  # For Telechips
  ${CMAKE_SOURCE_DIR}/3rdparty/libusb/1.0/tcc/lib
  # For x86 linux like Ubutun
  #${CMAKE_SOURCE_DIR}/3rdparty/libusb/1.0/x86/64bit/lib
)

set (MYSPIN_LIB
  # For Raspberry pi3
  #${CMAKE_SOURCE_DIR}/3rdparty/myspin/1.2.3/arm/32bit/debug/lib
  # For Telechips 
  ${CMAKE_SOURCE_DIR}/3rdparty/myspin/1.2.3/tcc/32bit/debug/lib
)

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
