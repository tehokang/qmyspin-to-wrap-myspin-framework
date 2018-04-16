#include "BluetoothConnection.h"

BluetoothConnection::BluetoothConnection(ConnectionListener &listener)
  : Connection(listener) {

}

BluetoothConnection::~BluetoothConnection() {

}

bool BluetoothConnection::connect(const Device &device) {

  return false;
}

void BluetoothConnection::disconnect(const Device &device) {

}

bool BluetoothConnection::send(const Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

bool BluetoothConnection::receive(const Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

void BluetoothConnection::run() {

}