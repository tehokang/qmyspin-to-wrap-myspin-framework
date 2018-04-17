#include "TransportAdapter.h"
#include "Scanner.h"
#include "Connection.h"
#include "Macro.h"

TransportAdapter::TransportAdapter(TransportAdapterListener &listener)
  : m_listener(listener) {
  /**
   * @note Assigning Scanner and Connection is up to child's constructor
   */
}

TransportAdapter::~TransportAdapter() {
  SAFE_DELETE(m_scanner);
  SAFE_DELETE(m_connection);
}

bool TransportAdapter::init() {
  LOG_DEBUG("\n");
  return false;
}

bool TransportAdapter::start() {
  LOG_DEBUG("\n");
  return false;
}

void TransportAdapter::stop() {
  LOG_DEBUG("\n");

}

bool TransportAdapter::scan() {
  LOG_DEBUG("\n");
  return false;
}

bool TransportAdapter::connect(const Device &device) {
  LOG_DEBUG("\n");
  return false;
}

void TransportAdapter::disconnect(const Device &device) {
  LOG_DEBUG("\n");

}

bool TransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return false;
}

bool TransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return false;
}

void TransportAdapter::onConnect(Device *device) {
  LOG_DEBUG("\n");
  m_listener.onConnect(device);
}

void TransportAdapter::onDisconnect(Device *device) {
  LOG_DEBUG("\n");
  m_listener.onDisconnect(device);
}

void TransportAdapter::onError(int error) {
  LOG_DEBUG("\n");
  m_listener.onError(error);
}

void TransportAdapter::onScan(list<Device*> devices) {
  LOG_DEBUG("\n");
  m_listener.onScan(devices);
}

void TransportAdapter::onAttached(Device *device) {
  LOG_DEBUG("\n");
}

void TransportAdapter::onDettached(Device *device) {
  LOG_DEBUG("\n");
}