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
set (LIBUSB_INC /usr/include/)
set (LIBUSB_LIB /usr/lib/arm-linux-gnueabihf/)

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
