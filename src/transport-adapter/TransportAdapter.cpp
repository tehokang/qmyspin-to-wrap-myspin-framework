#include "TransportAdapter.h"
#include "Scanner.h"
#include "Connection.h"

TransportAdapter::TransportAdapter(TransportAdapterListener &listener)
  : m_listener(listener) {
  /**
   * @note Assigning Scanner and Connection is up to child's constructor
   */
}

TransportAdapter::~TransportAdapter() {
  if ( m_scanner ) {
    delete m_scanner;
    m_scanner = nullptr;
  }

  if ( m_connection ) {
    delete m_connection;
    m_connection = nullptr;
  }
}

bool TransportAdapter::init() {
  return false;
}

bool TransportAdapter::start() {
  return false;
}

void TransportAdapter::stop() {

}

bool TransportAdapter::scan() {
  return false;
}

bool TransportAdapter::connect(const Device &device) {
  return false;
}

void TransportAdapter::disconnect(const Device &device) {

}

bool TransportAdapter::send(const Device &device, unsigned char *buffer, unsigned int size) {
  return false;
}

bool TransportAdapter::receive(const Device &device, unsigned char *buffer, unsigned int size) {
  return false;
}

void TransportAdapter::onConnect(Device *device) {
  m_listener.onConnect(device);
}

void TransportAdapter::onDisconnect(Device *device) {
  m_listener.onDisconnect(device);
}

void TransportAdapter::onError(int error) {
  m_listener.onError(error);
}

void TransportAdapter::onScan(list<Device*> devices) {
  m_listener.onScan(devices);
}

void TransportAdapter::onAttached(Device *device) {

}

void TransportAdapter::onDettached(Device *device) {

}