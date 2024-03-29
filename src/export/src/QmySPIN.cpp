#include "QmySPIN.h"
#include "QmySPINImpl.h"
#include "Macro.h"

QmySPIN* QmySPIN::m_instance = nullptr;
QmySPIN* QmySPIN::createInstance() {
  if ( m_instance == nullptr ) {
    m_instance = new QmySPINImpl();
  }
  LOG_DEBUG("Created QmySPIN \n");
  return m_instance;
}

QmySPIN* QmySPIN::getInstance() {
  return createInstance();
}

void QmySPIN::destroyInstance() {
  if ( m_instance != nullptr ) {
    m_instance->stop();

    delete m_instance;
    m_instance = nullptr;
  }
  LOG_DEBUG("Destoryed QmySPIN \n");
}

QmySPIN::QmySPIN() {
  LOG_DEBUG("\n");
}

QmySPIN::~QmySPIN() {
  LOG_DEBUG("\n");
}

void QmySPIN::addEventListener(QmySPINListener *listener) {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    if ( (*it) == listener ) {
      return;
    }
  }
  m_listeners.push_back(listener);
}

void QmySPIN::removeEventListener(QmySPINListener *listener) {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    if ( (*it) == listener ) {
      m_listeners.remove(*it);
    }
  }
}

void QmySPIN::setLogLevel(bool info, bool debug, bool warn, bool error) {
  Logger::setLogLevel(info, debug, warn, error);
}