#include "UsbAOAConnection.h"

UsbAOAConnection::UsbAOAConnection(ConnectionListener &listener)
  : Connection(listener) {

}

UsbAOAConnection::~UsbAOAConnection() {

}

bool UsbAOAConnection::connect(const Device &device) {

  return true;
}

void UsbAOAConnection::disconnect(const Device &device) {

}

bool UsbAOAConnection::send(const Device &device, unsigned char *buffer, unsigned int size) {

  return true;
}

bool UsbAOAConnection::receive(const Device &device, unsigned char *buffer, unsigned int size) {

  return true;
}

void UsbAOAConnection::run() {

  while( m_running ) {

  };
}