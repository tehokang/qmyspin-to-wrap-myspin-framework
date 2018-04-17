#ifndef __TRANSPORT_ADAPTER_H__
#define __TRANSPORT_ADAPTER_H__

#include <list>
using namespace std;

#include "Scanner.h"
#include "Connection.h"

class TransportAdapterListener {
public:
  virtual void onScan(list<Device*> device) = 0;
  virtual void onConnect(Device* device) = 0;
  virtual void onDisconnect(Device* device) = 0;
  virtual void onError(int error) = 0;
};

class TransportAdapter : public ScannerListener, public ConnectionListener {
public:
  TransportAdapter(TransportAdapterListener &listener);
  virtual ~TransportAdapter();

  virtual bool init();
  virtual bool start();
  virtual void stop();
  virtual bool scan();
  virtual bool connect(Device &device);
  virtual void disconnect(Device &device);
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size);
  virtual bool receive(Device &device, unsigned char *buffer, unsigned int size);

  virtual void onConnect(Device *device) override;
  virtual void onDisconnect(Device *device) override;
  virtual void onError(int error) override;
  virtual void onScan(list<Device*> devices) override;
  virtual void onAttached(Device *device) override;
  virtual void onDettached(Device *device) override;

protected:
  int m_type;
  Scanner *m_scanner;
  Connection *m_connection;
  TransportAdapterListener &m_listener;
};

#endif