#ifndef __QMYSPIN_IMPL_H__
#define __QMYSPIN_IMPL_H__

#include <list>
using namespace std;

#include "QmySPIN.h"
#include "ProjectionHandler.h"
#include "TransportAdapter.h"

class QmySPINImpl : public QmySPIN, public ProjectionListener, public TransportAdapterListener {
public:
  QmySPINImpl();
  virtual ~QmySPINImpl();

  /**
   * @note QmySPIN implementation
   */
  virtual bool init() override;
  virtual bool start() override;
  virtual void stop() override;
  virtual bool scan() override;
  virtual bool select(Device *device) override;
  virtual bool unselect(Device *device) override;
  virtual list<Device*> getDevices() override;

  virtual void setFrameBuffer(
      PIXEL_FORMAT format, unsigned char *frame_buffer,
      unsigned int width, unsigned height, unsigned int dpi) override;

  virtual void requestFrameBuffer() override;
  virtual void sendHomeKey(PRESS_TYPE press) override;
  virtual void sendBackKey(PRESS_TYPE press) override;
  virtual void sendMenuKey(PRESS_TYPE press) override;
  virtual void sendSearchKey(PRESS_TYPE press) override;
  virtual void sendCustomKey(PRESS_TYPE press, int key) override;
  virtual void sendTouch(int x, int y, int finger, PRESS_TYPE action) override;

  virtual bool sendVehicle(string message) override;

  /**
   * @note ProjectionListener implementation
   */
  virtual bool onReqSend(unsigned char *buffer, unsigned int size, void *connection) override;
  virtual unsigned int onReqReceive(unsigned char *buffer, unsigned int size, void *connection) override;
  virtual void onFrameUpdateStarted(unsigned int numOfRectangles) override;
  virtual void onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
      unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) override;
  virtual void onFrameUpdateEnded() override;
  virtual void onReady() override;

  /**
   * @note TransportAdapterListener implmentation
   */
  virtual void onScan(list<Device*> devices) override;
  virtual void onConnect(Device *device) override;
  virtual void onDisconnect(Device *device) override;
  virtual void onError(int error) override;
  virtual void onAttached(Device *device) override;
  virtual void onDettached(Device *device) override;


protected:
  ProjectionHandler &m_projection_handler;
  TransportAdapter &m_usb_aoa_transport_adapter;
  TransportAdapter &m_usb_iap_transport_adapter;
  TransportAdapter &m_bluetooth_transport_adapter;
  TransportAdapter &m_tcp_transport_adapter;
};

#endif