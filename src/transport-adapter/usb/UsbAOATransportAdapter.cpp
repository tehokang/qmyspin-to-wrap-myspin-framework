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
  SAFE_DELETE(m_connection);
  SAFE_DELETE(m_scanner);
}

bool UsbAOATransportAdapter::init() {
  LOG_DEBUG("\n");

  return m_scanner->init();
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

bool UsbAOATransportAdapter::connect(Device &device) {
  LOG_DEBUG("\n");

  return m_connection->connect(device);
}

void UsbAOATransportAdapter::disconnect(Device &device) {
  LOG_DEBUG("\n");
  m_connection->disconnect(device);
}

bool UsbAOATransportAdapter::send(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->send(device, buffer, size);
}

unsigned int UsbAOATransportAdapter::receive(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return m_connection->receive(device, buffer, size);
}

void UsbAOATransportAdapter::onAttached(Device *device) {
  LOG_INFO("\n");
  m_connection->connect(*device);
}

void UsbAOATransportAdapter::onDettached(Device *device) {
  LOG_INFO("\n");
  m_connection->disconnect(*device);
}
