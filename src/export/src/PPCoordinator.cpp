#include "PPCoordinator.h"

ProjectionCoordinator::ProjectionCoordinator() {

}

ProjectionCoordinator::~ProjectionCoordinator() {

}

bool ProjectionCoordinator::init() {
  return true;
}

bool ProjectionCoordinator::start() {
  return true;
}

void ProjectionCoordinator::stop() {

}

void ProjectionCoordinator::setEventListener(ProjectionCoordinatorListener *listener) {
  m_listener = listener;
}

bool ProjectionCoordinator::scan() {
  return true;
}

bool ProjectionCoordinator::select(Device *device) {
  return true;
}

bool ProjectionCoordinator::unselect(Device *device) {
  return true;
}

bool ProjectionCoordinator::sendKey(int key, int press) {
  return true;
}

bool ProjectionCoordinator::sendTouch(int x, int y, int finger, int action) {
  return true;
}

bool ProjectionCoordinator::sendVehicle(string message) {
  return true;
}

bool ProjectionCoordinator::onReqSend(unsigned char *buffer, unsigned int size) {

  return true;
}

bool ProjectionCoordinator::onReqReceive(unsigned char *buffer, unsigned int size) {

  return true;
}

void ProjectionCoordinator::onFrameUpdated(unsigned char *buffer, unsigned int size) {

}

void ProjectionCoordinator::onScan(list<Device*> device) {

}

void ProjectionCoordinator::onConnect(Device* device) {

}

void ProjectionCoordinator::onDisconnect(Device* device) {

}

void ProjectionCoordinator::onError(int error) {

}
