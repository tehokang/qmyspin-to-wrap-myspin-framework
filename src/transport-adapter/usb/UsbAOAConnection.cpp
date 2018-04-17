#include "UsbAOAConnection.h"
#include "UsbDevice.h"
#include <unistd.h>

UsbAOAConnection::UsbAOAConnection(ConnectionListener &listener)
  : Connection(listener) {

}

UsbAOAConnection::~UsbAOAConnection() {

}

bool UsbAOAConnection::connect(Device &device) {
  UsbDevice *chosen = static_cast<UsbDevice*>(&device);

  return true;
}

void UsbAOAConnection::disconnect(Device &device) {

}

bool UsbAOAConnection::send(Device &device, unsigned char *buffer, unsigned int size) {

  return true;
}

bool UsbAOAConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {

  return true;
}

void UsbAOAConnection::run() {

  while( m_running ) {
    usleep(100 * 1000);
  };
}