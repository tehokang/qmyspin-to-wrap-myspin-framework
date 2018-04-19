#include "QmySPINImpl.h"
#include "ProjectionFactory.h"
#include "TransportAdapterFactory.h"
#include "Macro.h"

QmySPINImpl::QmySPINImpl()
  : QmySPIN()
  , m_projection_handler(ProjectionFactory::createProjection(
      ProjectionFactory::ProjectionType::MYSPIN))
  , m_usb_aoa_transport_adapter(TransportAdapterFactory::createTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::USB_AOA, *this))
  , m_usb_iap_transport_adapter(TransportAdapterFactory::createTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::USB_IAP, *this))
  , m_bluetooth_transport_adapter(TransportAdapterFactory::createTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::BLUETOOTH, *this))
  , m_tcp_transport_adapter(TransportAdapterFactory::createTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::TCP, *this)) {

  LOG_DEBUG("\n");
}

QmySPINImpl::~QmySPINImpl() {
  LOG_DEBUG("\n");

  TransportAdapterFactory::destroyTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::USB_AOA);

  TransportAdapterFactory::destroyTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::USB_IAP);

  TransportAdapterFactory::destroyTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::BLUETOOTH);

  TransportAdapterFactory::destroyTransportAdapter(
      TransportAdapterFactory::TransportAdapaterType::TCP);

  ProjectionFactory::destroyProjection(ProjectionFactory::ProjectionType::MYSPIN);
}

bool QmySPINImpl::init() {
  LOG_DEBUG("\n");

  RETURN_FALSE_IF_FALSE(m_projection_handler.init());
  m_projection_handler.setEventListener(this);

  m_usb_aoa_transport_adapter.setAccessoryManufacturerName(
      m_projection_handler.getAccessoryManufacturerName());
  m_usb_aoa_transport_adapter.setAccessoryDescription(
      m_projection_handler.getAccessoryDescription());
  m_usb_aoa_transport_adapter.setAccessoryModelName(
      m_projection_handler.getAccessoryModelName());
  m_usb_aoa_transport_adapter.setAccessoryVersion(
      m_projection_handler.getAccessoryVersion());
  m_usb_aoa_transport_adapter.setAccessoryUri(
      m_projection_handler.getAccessoryUri());
  m_usb_aoa_transport_adapter.setAccessorySerialNumber(
      m_projection_handler.getAccessorySerialNumber());

  RETURN_FALSE_IF_FALSE(m_usb_aoa_transport_adapter.init());

  return true;
}

bool QmySPINImpl::start() {
  LOG_DEBUG("\n");

  RETURN_FALSE_IF_FALSE(m_usb_aoa_transport_adapter.start());

  return true;
}

void QmySPINImpl::stop() {
  LOG_DEBUG("\n");

  m_usb_aoa_transport_adapter.stop();
  m_projection_handler.stop();
}

bool QmySPINImpl::scan() {
  LOG_DEBUG("\n");

  RETURN_FALSE_IF_FALSE(m_usb_aoa_transport_adapter.scan());

  return true;
}

void QmySPINImpl::setFrameBuffer(
    PIXEL_FORMAT format, unsigned char *frame_buffer,
    unsigned int width, unsigned height, unsigned int dpi) {
  LOG_DEBUG("\n");
  ProjectionHandler::PIXEL_FORMAT pixel_format =
      ProjectionHandler::PIXEL_FORMAT::ePIXELFORMAT_ARGB8888;

  switch ( format ) {
    case QmySPIN::PIXEL_FORMAT::ePIXELFORMAT_RGB888:
      pixel_format = ProjectionHandler::PIXEL_FORMAT::ePIXELFORMAT_RGB888;
      break;
    case QmySPIN::PIXEL_FORMAT::ePIXELFORMAT_RGB565:
      pixel_format = ProjectionHandler::PIXEL_FORMAT::ePIXELFORMAT_RGB565;
      break;
    case QmySPIN::PIXEL_FORMAT::ePIXELFORMAT_ARGB8888:
      pixel_format = ProjectionHandler::PIXEL_FORMAT::ePIXELFORMAT_ARGB8888;
      break;
    case QmySPIN::PIXEL_FORMAT::ePIXELFORMAT_RGBA8888:
      pixel_format = ProjectionHandler::PIXEL_FORMAT::ePIXELFORMAT_RGBA8888;
      break;
  }
  m_projection_handler.setFrameBuffer(pixel_format, frame_buffer, width, height, dpi);
  /**
   * @todo Do we need to pass frame buffer into PPCoordinator
   */
}

bool QmySPINImpl::select(Device *device) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_NULL(device);
  RETURN_FALSE_IF_FALSE(m_usb_aoa_transport_adapter.connect(*device));

  return true;
}

bool QmySPINImpl::unselect(Device *device) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_NULL(device);

  m_usb_aoa_transport_adapter.disconnect(*device);
  return true;
}

bool QmySPINImpl::sendKey(int key, int press) {
  LOG_DEBUG("\n");

  return true;
}

bool QmySPINImpl::sendTouch(int x, int y, int finger, int action) {
  LOG_DEBUG("\n");

  return true;
}

bool QmySPINImpl::sendVehicle(string message) {
  LOG_DEBUG("\n");

  return true;
}

void QmySPINImpl::onScan(list<Device*> devices) {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onScan(devices);
  }
}

void QmySPINImpl::onConnect(Device *device) {
  LOG_DEBUG("\n");

  RETURN_IF_FALSE(m_projection_handler.start((void*)device));

  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onSelect(device);
  }
}

void QmySPINImpl::onDisconnect(Device *device) {
  LOG_DEBUG("\n");

  m_projection_handler.stop();

  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onUnselect(device);
  }
}

void QmySPINImpl::onError(int error) {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onError(error);
  }
}

bool QmySPINImpl::onReqSend(unsigned char *buffer, unsigned int size, void *connection) {
  LOG_DEBUG("\n");
  Device *device = static_cast<Device*>(connection);
  return m_usb_aoa_transport_adapter.send(*device, buffer, size);
}

unsigned int QmySPINImpl::onReqReceive(unsigned char *buffer, unsigned int size, void *connection) {
  LOG_DEBUG("\n");
  Device *device = static_cast<Device*>(connection);
  return m_usb_aoa_transport_adapter.receive(*device, buffer, size);
}

void QmySPINImpl::onFrameUpdateStarted(unsigned int numOfRectangles) {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onFrameUpdateStarted(numOfRectangles);
  }
}

void QmySPINImpl::onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
  unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onFrameUpdating(currentNumber, x, y, width, height, buffer, bufferSize);
  }
}

void QmySPINImpl::onFrameUpdateEnded() {
  LOG_DEBUG("\n");
  for ( list<QmySPINListener*>::iterator it = m_listeners.begin();
      it != m_listeners.end(); ++it ) {
    (*it)->onFrameUpdateEnded();
  }
}