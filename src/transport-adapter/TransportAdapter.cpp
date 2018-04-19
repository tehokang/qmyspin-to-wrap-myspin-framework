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

bool TransportAdapter::connect(Device &device) {
  LOG_DEBUG("\n");
  return false;
}

void TransportAdapter::disconnect(Device &device) {
  LOG_DEBUG("\n");

}

bool TransportAdapter::send(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  return false;
}

bool TransportAdapter::receive(Device &device, unsigned char *buffer, unsigned int size) {
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

void TransportAdapter::setAccessoryManufacturerName(string accessory_manufacturer_name) {
  RETURN_IF_NULL(m_connection);
  m_connection->setAccessoryManufacturerName(accessory_manufacturer_name);
}

void TransportAdapter::setAccessoryModelName(string accessory_model_name) {
  RETURN_IF_NULL(m_connection);
  m_connection->setAccessoryModelName(accessory_model_name);
}

void TransportAdapter::setAccessoryDescription(string accessory_description) {
  RETURN_IF_NULL(m_connection);
  m_connection->setAccessoryDescription(accessory_description);
}

void TransportAdapter::setAccessoryVersion(string accessory_version) {
  RETURN_IF_NULL(m_connection);
  m_connection->setAccessoryVersion(accessory_version);
}

void TransportAdapter::setAccessoryUri(string accessory_uri) {
  RETURN_IF_NULL(m_connection);
  m_connection->setAccessoryUri(accessory_uri);
}

void TransportAdapter::setAccessorySerialNumber(string accessory_serial_number) {
  RETURN_IF_NULL(m_connection);
  m_connection->setAccessorySerialNumber(accessory_serial_number);
}
