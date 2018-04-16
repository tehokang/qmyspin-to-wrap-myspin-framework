#include "AbaltaHandler.h"

AbaltaHandler::AbaltaHandler()
{

}

AbaltaHandler::~AbaltaHandler()
{

}

bool AbaltaHandler::init() {

  return true;
}

bool AbaltaHandler::start() {

  return true;
}

void AbaltaHandler::stop() {

}

bool AbaltaHandler::sendKey(int key, int press) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  m_listener->onReqSend(buffer, buffer_size);
}

bool AbaltaHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */

  m_listener->onReqSend(buffer, buffer_size);
}