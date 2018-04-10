cmake_minimum_required(VERSION 2.8)

project(phoneproject-qmyspin)

#=====================================================================================
# Version
#=====================================================================================
set(VERSION_MAJOR "0")
set(VERSION_MINOR "1")
set(VERSION_PATCH "0")
set(VERSION "${SDK_VERSION_MAJOR}.${SDK_VERSION_MINOR}.${SDK_VERSION_PATCH}")

#=====================================================================================
# Build Options
#=====================================================================================
message(STATUS "CMAKE_TOOLCHAIN_FILE='${CMAKE_TOOLCHAIN_FILE}'")

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")

set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/out/")
SET(CMAKE_INSTALL_PREFIX "${OUTPUT_DIR}")
message (STATUS "CMAKE_INSTALL_PREFIX='${CMAKE_INSTALL_PREFIX}'")

#=====================================================================================
# Sub directories
#=====================================================================================
add_subdirectory(${CMAKE_SOURCE_DIR}/device)
add_subdirectory(${CMAKE_SOURCE_DIR}/export)
add_subdirectory(${CMAKE_SOURCE_DIR}/example)
add_subdirectory(${CMAKE_SOURCE_DIR}/projection_handler)

#=======================================================================================
# Build sources
#=======================================================================================


#=====================================================================================
# Install
#=====================================================================================
