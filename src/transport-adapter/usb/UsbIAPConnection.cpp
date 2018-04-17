#include "UsbIAPConnection.h"
#include <unistd.h>

UsbIAPConnection::UsbIAPConnection(ConnectionListener &listener)
  : Connection(listener) {

}

UsbIAPConnection::~UsbIAPConnection() {

}

bool UsbIAPConnection::connect(Device &device) {

  return false;
}

void UsbIAPConnection::disconnect(Device &device) {

}

bool UsbIAPConnection::send(Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

bool UsbIAPConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

void UsbIAPConnection::run() {

  while ( m_running ) {
    usleep(100 * 1000);
  };
}