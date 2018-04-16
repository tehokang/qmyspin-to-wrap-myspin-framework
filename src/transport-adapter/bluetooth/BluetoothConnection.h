#ifndef __BLUETOOTH_CONNECTION_H__
#define __BLUETOOTH_CONNECTION_H__

#include "../Connection.h"

class BluetoothConnection : public Connection {
public:
  BluetoothConnection(ConnectionListener &listener);
  virtual ~BluetoothConnection();

  virtual bool connect(const Device &device) override;
  virtual void disconnect(const Device &device) override;
  virtual bool send(const Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(const Device &device, unsigned char *buffer, unsigned int size) override;

protected:

};

#endif