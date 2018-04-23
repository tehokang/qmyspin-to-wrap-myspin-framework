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
if ( ${TARGET_PLATFORM} EQUAL "pi-arm" )
set (LIBUSB_LIB
  # For Raspberry pi3
  ${CMAKE_SOURCE_DIR}/3rdparty/libusb/1.0/pi3/32bit/lib
)
elseif ( ${TARGET_PLATFORM} EQUAL "tcc-arm" )
set (LIBUSB_LIB
  # For Telechips
  ${CMAKE_SOURCE_DIR}/3rdparty/libusb/1.0/tcc/lib
)
elseif ( ${TARGET_PLATFORM} EQUAL "brcm-arm" )
set (LIBUSB_LIB
  # For x86 linux like Ubutun
  ${CMAKE_SOURCE_DIR}/3rdparty/libusb/1.0/x86/64bit/lib
)
endif()

set(INCPATHS
    ${CMAKE_SOURCE_DIR}/src/export/include
    ${CMAKE_SOURCE_DIR}/src/utility
    ${CMAKE_SOURCE_DIR}/src/transport-adapter
    ${LIBUSB_INC}
)

include_directories(
    ${INCPATHS}
)

set(SOURCE_FILES ${SOURCE_FILES}
    Connection.cpp Scanner.cpp TransportAdapter.cpp TransportAdapterFactory.cpp)

set (SOURCE_FILES ${SOURCE_FILES}
    usb/UsbAndroidDevice.cpp usb/UsbAOAConnection.cpp usb/UsbAOATransportAdapter.cpp
    usb/UsbAppleDevice.cpp usb/UsbIAPConnection.cpp usb/UsbIAPTransportAdapter.cpp
    usb/UsbDevice.cpp usb/UsbScanner.cpp)

set (SOURCE_FILES ${SOURCE_FILES}
    tcp/TcpDevice.cpp tcp/TcpConnection.cpp tcp/TcpScanner.cpp tcp/TcpTransportAdapter.cpp)

set (SOURCE_FILES ${SOURCE_FILES}
    bluetooth/BluetoothDevice.cpp bluetooth/BluetoothConnection.cpp
    bluetooth/BluetoothScanner.cpp bluetooth/BluetoothTransportAdapter.cpp)

link_directories(
    ${BIUILD_SRC_DIR}/utility
    ${LIBUSB_LIB}
)

#=======================================================================================
# Build sources
#=======================================================================================
add_library(transport-adapter SHARED ${SOURCE_FILES})

target_link_libraries(transport-adapter
    utility usb-1.0
)
#=====================================================================================
# Install
#=====================================================================================
