#ifndef __USB_AOA_CONNECTION_H__
#define __USB_AOA_CONNECTION_H__

#include "Connection.h"

class UsbAOAConnection : public Connection {
public:
  UsbAOAConnection(ConnectionListener &listener);
  virtual ~UsbAOAConnection();

  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(Device &device, unsigned char *buffer, unsigned int size) override;

protected:
  virtual void run() override;

};

#endif