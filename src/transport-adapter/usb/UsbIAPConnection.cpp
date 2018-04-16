#include "UsbIAPConnection.h"

UsbIAPConnection::UsbIAPConnection(ConnectionListener &listener)
  : Connection(listener) {

}

UsbIAPConnection::~UsbIAPConnection() {

}

bool UsbIAPConnection::connect(const Device &device) {

  return false;
}

void UsbIAPConnection::disconnect(const Device &device) {

}

bool UsbIAPConnection::send(const Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

bool UsbIAPConnection::receive(const Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

void UsbIAPConnection::run() {

  while ( m_running ) {

  };
}