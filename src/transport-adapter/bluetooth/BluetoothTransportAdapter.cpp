#include "BluetoothTransportAdapter.h"
#include "BluetoothScanner.h"
#include "BluetoothConnection.h"

BluetoothTransportAdapter::BluetoothTransportAdapter(TransportAdapterListener &listener)
  : TransportAdapter(listener) {
    m_scanner = new BluetoothScanner(static_cast<ScannerListener&>(*this));
    m_connection = new BluetoothConnection(static_cast<ConnectionListener&>(*this));
}

BluetoothTransportAdapter::~BluetoothTransportAdapter() {

}

bool BluetoothTransportAdapter::init() {

  return true;
}

bool BluetoothTransportAdapter::start() {

  return true;
}

void BluetoothTransportAdapter::stop() {

}

bool BluetoothTransportAdapter::scan() {

  return m_scanner->scan();
}

bool BluetoothTransportAdapter::connect(const Device &device) {
  return m_connection->connect(device);
}

void BluetoothTransportAdapter::disconnect(const Device &device) {
  m_connection->disconnect(device);
}

bool BluetoothTransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->send(device, buffer, size);
}

bool BluetoothTransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->receive(device, buffer, size);
}
