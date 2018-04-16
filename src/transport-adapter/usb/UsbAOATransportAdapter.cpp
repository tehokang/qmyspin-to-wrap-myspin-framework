#include "UsbAOATransportAdapter.h"
#include "UsbScanner.h"
#include "UsbAOAConnection.h"

UsbAOATransportAdapter::UsbAOATransportAdapter(TransportAdapterListener &listener)
  : TransportAdapter(listener) {
    m_scanner = new UsbScanner(static_cast<ScannerListener&>(*this));
    m_connection = new UsbAOAConnection(static_cast<ConnectionListener&>(*this));
}

UsbAOATransportAdapter::~UsbAOATransportAdapter() {

}

bool UsbAOATransportAdapter::init() {

  return true;
}

bool UsbAOATransportAdapter::start() {

  return true;
}

void UsbAOATransportAdapter::stop() {

}

bool UsbAOATransportAdapter::scan() {

  return m_scanner->scan();
}

bool UsbAOATransportAdapter::connect(const Device &device) {
  return m_connection->connect(device);
}

void UsbAOATransportAdapter::disconnect(const Device &device) {
  m_connection->disconnect(device);
}

bool UsbAOATransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->send(device, buffer, size);
}

bool UsbAOATransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  return m_connection->receive(device, buffer, size);
}
