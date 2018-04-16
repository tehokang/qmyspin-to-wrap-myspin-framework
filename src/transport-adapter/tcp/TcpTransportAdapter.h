#ifndef __TCP_TRANSPORT_ADAPTER_H__
#define __TCP_TRANSPORT_ADAPTER_H__

#include "../TransportAdapter.h"

class TcpTransportAdapter : public TransportAdapter {
public:
  TcpTransportAdapter(TransportAdapterListener &listener);
  virtual ~TcpTransportAdapter();

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