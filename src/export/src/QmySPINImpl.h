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

  virtual void setFrameBuffer(
      PIXEL_FORMAT format, unsigned char *frame_buffer, unsigned int width, unsigned height) override;

  virtual bool sendKey(int key, int press) override;
  virtual bool sendTouch(int x, int y, int finger, int action) override;
  virtual bool sendVehicle(string message) override;

  /**
   * @note ProjectionListener implementation
   */
  virtual bool onReqSend(unsigned char *buffer, unsigned int size) override;
  virtual bool onReqReceive(unsigned char *buffer, unsigned int size) override;
  virtual void onFrameUpdated(unsigned char *buffer, unsigned int size) override;

  /**
   * @note TransportAdapterListener implmentation
   */
  virtual void onScan(list<Device*> devices) override;
  virtual void onConnect(Device *device) override;
  virtual void onDisconnect(Device *device) override;
  virtual void onError(int error) override;

protected:
  ProjectionHandler &m_projection_handler;
  TransportAdapter &m_usb_aoa_transport_adapter;
  TransportAdapter &m_usb_iap_transport_adapter;
  TransportAdapter &m_bluetooth_transport_adapter;
  TransportAdapter &m_tcp_transport_adapter;
};

#endif