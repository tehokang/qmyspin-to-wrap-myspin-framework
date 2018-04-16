#include "TcpTransportAdapter.h"
#include "TcpScanner.h"
#include "TcpConnection.h"

TcpTransportAdapter::TcpTransportAdapter(TransportAdapterListener &listener)
  : TransportAdapter(listener) {
    m_scanner = new TcpScanner(static_cast<ScannerListener&>(*this));
    m_connection = new TcpConnection(static_cast<ConnectionListener&>(*this));
}

TcpTransportAdapter::~TcpTransportAdapter() {

}

bool TcpTransportAdapter::init() {

  return true;
}

bool TcpTransportAdapter::start() {

  return true;
}

void TcpTransportAdapter::stop() {

}

bool TcpTransportAdapter::scan() {

  return m_scanner->scan();
}

bool TcpTransportAdapter::connect(const Device &device) {
  return m_connection->connect(device);
}

void TcpTransportAdapter::disconnect(const Device &device) {
  m_connection->disconnect(device);
}

bool TcpTransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->send(device, buffer, size);
}

bool TcpTransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->receive(device, buffer, size);
}
