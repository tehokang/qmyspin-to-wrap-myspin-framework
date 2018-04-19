#ifndef __USB_IAP_CONNECTION_H__
#define __USB_IAP_CONNECTION_H__

#include "../Connection.h"

class UsbIAPConnection : public Connection {
public:
  UsbIAPConnection(ConnectionListener &listener);
  virtual ~UsbIAPConnection();

  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual unsigned int receive(Device &device, unsigned char *buffer, unsigned int size) override;

protected:
  virtual void run() override;
};

#endif