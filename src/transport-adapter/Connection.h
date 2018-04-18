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
  typedef enum _CONNECTION_MSG_TYPE_ {
    CONNECT,
    DISCONNECT,
    SEND,
    RECEIVE
  } ConnectionMsgType;

  class ConnectionMsg {
  public:
    ConnectionMsg(int type, void *msg)
      : m_type(type)
      , m_msg(msg) {

    }

    int getType() { return m_type; }
    void* getMsg() { return m_msg; }
  protected:
    int m_type;
    void *m_msg;
  };

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