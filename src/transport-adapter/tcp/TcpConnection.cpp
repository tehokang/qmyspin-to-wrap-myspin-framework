#include "TcpConnection.h"

TcpConnection::TcpConnection(ConnectionListener &listener)
  : Connection(listener) {

}

TcpConnection::~TcpConnection() {

}

bool TcpConnection::connect(Device &device) {

  return false;
}

void TcpConnection::disconnect(Device &device) {

}

bool TcpConnection::send(Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

unsigned int TcpConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {

  return 0;
}

void TcpConnection::run() {

}