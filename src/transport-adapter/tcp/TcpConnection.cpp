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

bool TcpConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

void TcpConnection::run() {

}