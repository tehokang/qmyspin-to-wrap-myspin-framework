#include "ProjectionHandler.h"

ProjectionHandler::ProjectionHandler()
  : m_accessory_manufacturer_name("Please assign in your projection handler, not here")
  , m_accessory_model_name("Please assign in your projection handler, not here")
  , m_accessory_description("Please assign in your projection handler, not here")
  , m_accessory_version("Please assign in your projection handler, not here")
  , m_accessory_uri("Please assign in your projection handler, not here")
  , m_accessory_serial_number("Please assign in your projection handler, not here")
  , m_connected_device(nullptr) {
  /**
   * @note NOTHING TO DO
   */
}

ProjectionHandler::~ProjectionHandler() {
  m_connected_device = nullptr;
}

void ProjectionHandler::setEventListener(ProjectionListener *listener) {
  m_listener = listener;
}

bool ProjectionHandler::init() {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
  return false;
}

bool ProjectionHandler::start(void *connected_device) {
  m_connected_device = connected_device;
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
  return false;
}

void ProjectionHandler::stop() {
   m_connected_device = nullptr;
}

void ProjectionHandler::sendHomeKey(PRESS_TYPE press) {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
}

void ProjectionHandler::sendBackKey(PRESS_TYPE press) {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
}

void ProjectionHandler::sendMenuKey(PRESS_TYPE press) {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
}

void ProjectionHandler::sendSearchKey(PRESS_TYPE press) {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
}

void ProjectionHandler::sendCustomKey(PRESS_TYPE press, int key) {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
}

void ProjectionHandler::sendTouch(unsigned int x, unsigned int y, int finger, PRESS_TYPE action) {
  /**
   * @warning PLEASE OVERRIDE ON YOUR OWN PROJECT HANDLER
   * DO NOTHING HERE
   */
}

void ProjectionHandler::setFrameBuffer(
    ProjectionHandler::PIXEL_FORMAT format, unsigned char pixel_bytes,
    unsigned char *frame_buffer,
    unsigned int width, unsigned height, unsigned int dpi) {
  m_pixel_format = format;
  m_pixel_bytes = pixel_bytes;
  m_frame_buffer = frame_buffer;
  m_width = width;
  m_height = height;
  m_dpi = dpi;
}

void ProjectionHandler::requestFrameBuffer() {

}