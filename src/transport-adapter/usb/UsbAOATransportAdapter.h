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
  virtual bool connect(const Device &device) override;
  virtual void disconnect(const Device &device) override;
  virtual bool send(const Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(const Device &device, unsigned char *buffer, unsigned int size) override;

protected:

};

#endif