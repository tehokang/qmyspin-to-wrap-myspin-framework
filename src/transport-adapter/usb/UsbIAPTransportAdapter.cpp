#include "UsbIAPTransportAdapter.h"
#include "UsbScanner.h"
#include "UsbIAPConnection.h"
#include "Macro.h"

UsbIAPTransportAdapter::UsbIAPTransportAdapter(TransportAdapterListener &listener)
  : TransportAdapter(listener) {
  LOG_DEBUG("\n");
  m_scanner = new UsbScanner(static_cast<ScannerListener&>(*this));
  m_connection = new UsbIAPConnection(static_cast<ConnectionListener&>(*this));
}

UsbIAPTransportAdapter::~UsbIAPTransportAdapter() {
  LOG_DEBUG("\n");

}

bool UsbIAPTransportAdapter::init() {
  LOG_DEBUG("\n");

  return true;
}

bool UsbIAPTransportAdapter::start() {
  LOG_DEBUG("\n");

  return true;
}

void UsbIAPTransportAdapter::stop() {
  LOG_DEBUG("\n");

}

bool UsbIAPTransportAdapter::scan() {
  LOG_DEBUG("\n");

  return m_scanner->scan();
}

bool UsbIAPTransportAdapter::connect(const Device &device) {
  LOG_DEBUG("\n");
  return m_connection->connect(device);
}

void UsbIAPTransportAdapter::disconnect(const Device &device) {
  LOG_DEBUG("\n");
  m_connection->disconnect(device);
}

bool UsbIAPTransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->send(device, buffer, size);
}

bool UsbIAPTransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->receive(device, buffer, size);
}
