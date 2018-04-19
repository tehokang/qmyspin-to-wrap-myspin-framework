#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__

#include "../Connection.h"

class TcpConnection : public Connection {
public:
  TcpConnection(ConnectionListener &listener);
  virtual ~TcpConnection();

  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual unsigned int receive(Device &device, unsigned char *buffer, unsigned int size) override;

protected:
  virtual void run() override;
};

#endif