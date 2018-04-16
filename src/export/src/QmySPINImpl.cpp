#include "QmySPINImpl.h"

QmySPINImpl::QmySPINImpl()
  : QmySPIN() {

  m_pp_coordinator = new ProjectionCoordinator();
}

QmySPINImpl::~QmySPINImpl() {
  if ( m_pp_coordinator ) {
    delete m_pp_coordinator;
    m_pp_coordinator = nullptr;
  }
}

bool QmySPINImpl::init() {
  if ( m_pp_coordinator == nullptr ) return false;

  return m_pp_coordinator->init();
}

bool QmySPINImpl::start() {
  return m_pp_coordinator->start();
}

void QmySPINImpl::stop() {
  m_pp_coordinator->stop();
}

bool QmySPINImpl::scan() {
  return m_pp_coordinator->scan();
}

void QmySPINImpl::setFrameBuffer(
    PIXEL_FORMAT format, unsigned char *frame_buffer, unsigned int width, unsigned height) {

  QmySPIN::setFrameBuffer(format, frame_buffer, width, height);

  /**
   * @todo Do we need to pass frame buffer into PPCoordinator
   */
}

bool QmySPINImpl::select(Device *device) {
  return m_pp_coordinator->select(device);
}

bool QmySPINImpl::unselect(Device *device) {
  return m_pp_coordinator->unselect(device);
}

bool QmySPINImpl::sendKey(int key, int press) {
  return m_pp_coordinator->sendKey(key, press);
}

bool QmySPINImpl::sendTouch(int x, int y, int finger, int action) {
  return m_pp_coordinator->sendTouch(x, y, finger, action);
}

bool QmySPINImpl::sendVehicle(string message) {
  return m_pp_coordinator->sendVehicle(message);
}

void QmySPINImpl::onScan(list<Device*> devices) {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onScan(devices);
  }
}

void QmySPINImpl::onSelect(Device *device) {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onSelect(device);
  }
}

void QmySPINImpl::onUnselect(Device *device) {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onUnselect(device);
  }
}

void QmySPINImpl::onError(int error) {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onError(error);
  }
}

void QmySPINImpl::onReady() {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onReady();
  }
}

void QmySPINImpl::onStop() {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onStop();
  }
}

void QmySPINImpl::onFrameUpdate() {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onFrameUpdate();
  }
}

