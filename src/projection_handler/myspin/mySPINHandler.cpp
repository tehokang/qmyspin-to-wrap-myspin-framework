#include "mySPINHandler.h"

MySPINHandler::MySPINHandler()
{

}

MySPINHandler::~MySPINHandler()
{

}

bool MySPINHandler::init() {

  return true;
}

bool MySPINHandler::start() {

  return true;
}

void MySPINHandler::stop() {

}

bool MySPINHandler::sendKey(int key, int press) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  return m_listener->onReqSend(buffer, buffer_size);
}

bool MySPINHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  return m_listener->onReqSend(buffer, buffer_size);
}