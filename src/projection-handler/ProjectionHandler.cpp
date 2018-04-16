#include "ProjectionHandler.h"

ProjectionHandler::ProjectionHandler() {
  /**
   * @note NOTHING TO DO
   */
}

ProjectionHandler::~ProjectionHandler() {
  /**
   * @note NOTHING TO DO
   */
}

void ProjectionHandler::setEventListener(ProjectionListener *listener) {
  m_listener = listener;
}

bool ProjectionHandler::init() {

  return false;
}

bool ProjectionHandler::start() {

  return false;
}

void ProjectionHandler::stop() {

}

bool ProjectionHandler::sendKey(int key, int press) {
  return false;
}

bool ProjectionHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  return false;
}