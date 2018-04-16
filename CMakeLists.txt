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

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/out/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")

set(BIUILD_SRC_DIR ${CMAKE_SOURCE_DIR}/build/src)

#=====================================================================================
# Sub directories
#=====================================================================================
add_subdirectory(${CMAKE_SOURCE_DIR}/src/utility)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/transport-adapter)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/projection-handler)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/export)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/examples)

#=======================================================================================
# Build sources
#=======================================================================================


#=====================================================================================
# Install
#=====================================================================================
