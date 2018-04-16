#ifndef __USB_IAP_CONNECTION_H__
#define __USB_IAP_CONNECTION_H__

#include "../Connection.h"

class UsbIAPConnection : public Connection {
public:
  UsbIAPConnection(ConnectionListener &listener);
  virtual ~UsbIAPConnection();

  virtual bool connect(const Device &device) override;
  virtual void disconnect(const Device &device) override;
  virtual bool send(const Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(const Device &device, unsigned char *buffer, unsigned int size) override;

protected:

};

#endif