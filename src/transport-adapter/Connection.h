#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "QueueThread.h"
#include "Device.h"

class ConnectionListener {
public:
  virtual void onConnect(Device *device) = 0;
  virtual void onDisconnect(Device *device) = 0;
  virtual void onError(int error) = 0;
};

class Connection : public QueueThread {
public:
  Connection(ConnectionListener &listener);
  virtual ~Connection();

  virtual bool connect(Device &device) = 0;
  virtual void disconnect(Device &device) = 0;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) = 0;
  virtual bool receive(Device &device, unsigned char *buffer, unsigned int size) = 0;

protected:
  ConnectionListener &m_listener;
};


#endif