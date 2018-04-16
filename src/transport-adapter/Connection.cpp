#include "Connection.h"

Connection::Connection(ConnectionListener &listener)
  : m_listener(listener) {

}

Connection::~Connection() {

}
