#include "Connection.h"
#include "Macro.h"

Connection::Connection(ConnectionListener &listener)
  : m_listener(listener) {
  LOG_DEBUG("\n");
}

Connection::~Connection() {
  LOG_DEBUG("\n");
}