#ifndef __USB_AOA_CONNECTION_H__
#define __USB_AOA_CONNECTION_H__

#include "Connection.h"

class UsbAOAConnection : public Connection {
public:
  UsbAOAConnection(ConnectionListener &listener);
  virtual ~UsbAOAConnection();

  virtual bool connect(const Device &device) override;
  virtual void disconnect(const Device &device) override;
  virtual bool send(const Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(const Device &device, unsigned char *buffer, unsigned int size) override;

protected:
  virtual void run() override;

};

#endif