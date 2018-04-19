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
  SAFE_DELETE(m_connection);
  SAFE_DELETE(m_scanner);
}

bool UsbIAPTransportAdapter::init() {
  LOG_DEBUG("\n");

  return m_scanner->init();
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

bool UsbIAPTransportAdapter::connect(Device &device) {
  LOG_DEBUG("\n");
  return m_connection->connect(device);
}

void UsbIAPTransportAdapter::disconnect(Device &device) {
  LOG_DEBUG("\n");
  m_connection->disconnect(device);
}

bool UsbIAPTransportAdapter::send(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->send(device, buffer, size);
}

unsigned int UsbIAPTransportAdapter::receive(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->receive(device, buffer, size);
}
