#include "../include/QmySPIN.h"
#include "QmySPINImpl.h"

QmySPIN* QmySPIN::m_instance = nullptr;

const QmySPIN* QmySPIN::createInstance() {
  if ( m_instance == nullptr ) {
    m_instance = new QmySPINImpl();
  }
  return m_instance;
}

void QmySPIN::destroyInstance() {
  if ( m_instance != nullptr ) {
    delete m_instance;
    m_instance = nullptr;
  }
}

QmySPIN::QmySPIN() {

}

QmySPIN::~QmySPIN() {

}

void QmySPIN::addEventListener(QmySPINListener *listener) {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    if ( (*it) == listener ) {
      return;
    }
  }
  m_listeners.push_back(listener);
}

void QmySPIN::removeEventListener(QmySPINListener *listener) {
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    if ( (*it) == listener ) {
      m_listeners.remove(*it);
    }
  }
}

void QmySPIN::setFrameBuffer(
    PIXEL_FORMAT format, unsigned char *frame_buffer, unsigned int width, unsigned height) {
  m_pixel_format = format;
  m_frame_buffer = frame_buffer;
  m_width = width;
  m_height = height;
}