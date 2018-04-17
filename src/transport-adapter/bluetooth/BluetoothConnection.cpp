#include "BluetoothConnection.h"

BluetoothConnection::BluetoothConnection(ConnectionListener &listener)
  : Connection(listener) {

}

BluetoothConnection::~BluetoothConnection() {

}

bool BluetoothConnection::connect(Device &device) {

  return false;
}

void BluetoothConnection::disconnect(Device &device) {

}

bool BluetoothConnection::send(Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

bool BluetoothConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {

  return false;
}

void BluetoothConnection::run() {

}