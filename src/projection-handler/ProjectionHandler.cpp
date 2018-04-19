#include "ProjectionHandler.h"

ProjectionHandler::ProjectionHandler()
  : m_accessory_manufacturer_name("Please assign in your projection handler, not here")
  , m_accessory_model_name("Please assign in your projection handler, not here")
  , m_accessory_description("Please assign in your projection handler, not here")
  , m_accessory_version("Please assign in your projection handler, not here")
  , m_accessory_uri("Please assign in your projection handler, not here")
  , m_accessory_serial_number("Please assign in your projection handler, not here") {
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