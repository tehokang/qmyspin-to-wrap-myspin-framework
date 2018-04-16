#include "CinemoHandler.h"

CinemoHandler::CinemoHandler()
{

}

CinemoHandler::~CinemoHandler()
{

}

bool CinemoHandler::init() {

  return true;
}

bool CinemoHandler::start() {

  return true;
}

void CinemoHandler::stop() {

}

bool CinemoHandler::sendKey(int key, int press) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  m_listener->onReqSend(buffer, buffer_size);
}

bool CinemoHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  m_listener->onReqSend(buffer, buffer_size);
}