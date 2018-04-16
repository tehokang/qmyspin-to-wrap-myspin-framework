#include "TcpConnection.h"

TcpConnection::TcpConnection(ConnectionListener &listener)
  : Connection(listener) {

}

TcpConnection::~TcpConnection() {

}

bool TcpConnection::connect(const Device &device) {

  return false;
}

void TcpConnection::disconnect(const Device &device) {

}

bool TcpConnection::send(const Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

bool TcpConnection::receive(const Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}
