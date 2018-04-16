#include "UsbAOATransportAdapter.h"
#include "UsbScanner.h"
#include "UsbAOAConnection.h"
#include "Macro.h"

UsbAOATransportAdapter::UsbAOATransportAdapter(TransportAdapterListener &listener)
  : TransportAdapter(listener) {
  LOG_DEBUG("\n");
  m_scanner = new UsbScanner(static_cast<ScannerListener&>(*this));
  m_connection = new UsbAOAConnection(static_cast<ConnectionListener&>(*this));
}

UsbAOATransportAdapter::~UsbAOATransportAdapter() {
  LOG_DEBUG("\n");

}

bool UsbAOATransportAdapter::init() {
  LOG_DEBUG("\n");

  return true;
}

bool UsbAOATransportAdapter::start() {
  LOG_DEBUG("\n");

  RETURN_FALSE_IF_FALSE(m_scanner->start());
  RETURN_FALSE_IF_FALSE(m_connection->start());

  return true;
}

void UsbAOATransportAdapter::stop() {
  LOG_DEBUG("\n");

  m_scanner->join();
  m_connection->join();
}

bool UsbAOATransportAdapter::scan() {
  LOG_DEBUG("\n");

  return m_scanner->scan();
}

bool UsbAOATransportAdapter::connect(const Device &device) {
  LOG_DEBUG("\n");
  return m_connection->connect(device);
}

void UsbAOATransportAdapter::disconnect(const Device &device) {
  LOG_DEBUG("\n");
  m_connection->disconnect(device);
}

bool UsbAOATransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->send(device, buffer, size);
}

bool UsbAOATransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->receive(device, buffer, size);
}
