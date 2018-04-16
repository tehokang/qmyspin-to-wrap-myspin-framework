#include "UsbIAPTransportAdapter.h"
#include "UsbScanner.h"
#include "UsbIAPConnection.h"

UsbIAPTransportAdapter::UsbIAPTransportAdapter(TransportAdapterListener &listener)
  : TransportAdapter(listener) {
    m_scanner = new UsbScanner(static_cast<ScannerListener&>(*this));
    m_connection = new UsbIAPConnection(static_cast<ConnectionListener&>(*this));
}

UsbIAPTransportAdapter::~UsbIAPTransportAdapter() {

}

bool UsbIAPTransportAdapter::init() {

  return true;
}

bool UsbIAPTransportAdapter::start() {

  return true;
}

void UsbIAPTransportAdapter::stop() {

}

bool UsbIAPTransportAdapter::scan() {

  return m_scanner->scan();
}

bool UsbIAPTransportAdapter::connect(const Device &device) {
  return m_connection->connect(device);
}

void UsbIAPTransportAdapter::disconnect(const Device &device) {
  m_connection->disconnect(device);
}

bool UsbIAPTransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->send(device, buffer, size);
}

bool UsbIAPTransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->receive(device, buffer, size);
}
