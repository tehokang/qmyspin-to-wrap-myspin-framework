#ifndef __USB_IAP_TRANSPORT_ADAPTER_H__
#define __USB_IAP_TRANSPORT_ADAPTER_H__

#include "../TransportAdapter.h"

class UsbIAPTransportAdapter : public TransportAdapter {
public:
  UsbIAPTransportAdapter(TransportAdapterListener &listener);
  virtual ~UsbIAPTransportAdapter();

  virtual bool init() override;
  virtual bool start() override;
  virtual void stop() override;
  virtual bool scan() override;
  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual unsigned int receive(Device &device, unsigned char *buffer, unsigned int size) override;

protected:

};

#endif