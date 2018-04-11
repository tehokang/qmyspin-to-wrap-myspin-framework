#include "SdlHandler.h"

SdlHandler::SdlHandler()
{

}

SdlHandler::~SdlHandler()
{

}

bool SdlHandler::init() {

  return true;
}

bool SdlHandler::start() {

  return true;
}

void SdlHandler::stop() {

}

bool SdlHandler::sendKey(int key, int press) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  m_listener->onReqSend(buffer, buffer_size);
}

bool SdlHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  m_listener->onReqSend(buffer, buffer_size);
}