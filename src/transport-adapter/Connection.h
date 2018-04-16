#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "Device.h"

class ConnectionListener {
public:
  virtual void onConnect(Device *device) = 0;
  virtual void onDisconnect(Device *device) = 0;
  virtual void onError(int error) = 0;
};

class Connection {
public:
  Connection(ConnectionListener &listener);
  virtual ~Connection();

  virtual bool connect(const Device &device) = 0;
  virtual void disconnect(const Device &device) = 0;
  virtual bool send(const Device &device, unsigned char *buffer, unsigned int size) = 0;
  virtual bool receive(const Device &device, unsigned char *buffer, unsigned int size) = 0;

protected:
  ConnectionListener &m_listener;
};


#endif