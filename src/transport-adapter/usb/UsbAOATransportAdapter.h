#ifndef __USB_AOA_TRANSPORT_ADAPTER_H__
#define __USB_AOA_TRANSPORT_ADAPTER_H__

#include "../TransportAdapter.h"

class UsbAOATransportAdapter : public TransportAdapter {
public:
  UsbAOATransportAdapter(TransportAdapterListener &listener);
  virtual ~UsbAOATransportAdapter();

  virtual bool init() override;
  virtual bool start() override;
  virtual void stop() override;
  virtual bool scan() override;
  virtual list<Device*> getDevices() override;
  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual unsigned int receive(Device &device, unsigned char *buffer, unsigned int size) override;

  /**
   * @note Override events of TransportAdapter to hook
   */
  virtual void onAttached(Device *device) override;
  virtual void onDettached(Device *device) override;

protected:

};

#endif