#include "Connection.h"
#include "Macro.h"
using namespace std;

Connection::Connection(ConnectionListener &listener)
  : m_listener(listener) {
  LOG_DEBUG("\n");
}

Connection::~Connection() {
  LOG_DEBUG("\n");
}

void Connection::setAccessoryManufacturerName(string accessory_manufacturer_name) {
  m_accessory_manufacturer_name = accessory_manufacturer_name;
}

void Connection::setAccessoryModelName(string accessory_model_name) {
  m_accessory_model_name = accessory_model_name;
}

void Connection::setAccessoryDescription(string accessory_description) {
  m_accessory_description = accessory_description;
}

void Connection::setAccessoryVersion(string accessory_version) {
  m_accessory_version = accessory_version;
}

void Connection::setAccessoryUri(string accessory_uri) {
  m_accessory_uri = accessory_uri;
}

void Connection::setAccessorySerialNumber(string accessory_serial_number) {
  m_accessory_serial_number = accessory_serial_number;
}

void Connection::__logging_buffer__(unsigned char *buffer, unsigned int size) {
#if 1
  fprintf(stdout, "Buffering data(%d) : \n", size);
  for ( unsigned int i = 0 ; i < size ; i++ ) {
    fprintf(stdout, "%02x ", buffer[i]);
  }
  fprintf(stdout, "\n");
#endif
}