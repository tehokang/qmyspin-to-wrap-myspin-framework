#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__

#include "../Connection.h"

class TcpConnection : public Connection {
public:
  TcpConnection(ConnectionListener &listener);
  virtual ~TcpConnection();

  virtual bool connect(const Device &device) override;
  virtual void disconnect(const Device &device) override;
  virtual bool send(const Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(const Device &device, unsigned char *buffer, unsigned int size) override;

protected:

};

#endif