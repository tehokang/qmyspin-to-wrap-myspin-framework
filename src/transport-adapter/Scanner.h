#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <list>
#include "Device.h"
#include "QueueThread.h"

using namespace std;

class ScannerListener {
public:
  virtual void onScan(list<Device*> devices) = 0;
  virtual void onAttached(Device* device) = 0;
  virtual void onDettached(Device* device) = 0;
};

class Scanner : public QueueThread {
public:
  class ScannerMsg {
  public:
    ScannerMsg(int type, void *msg)
      : m_type(type)
      , m_msg(msg) {

    }

    int getType() { return m_type; }
    void* getMsg() { return m_msg; }
  protected:
    int m_type;
    void *m_msg;
  };

  Scanner(ScannerListener &listener);
  virtual ~Scanner();

  virtual bool init() = 0;
  virtual bool scan() = 0;

protected:
  list<Device*> m_devices;
  ScannerListener &m_listener;
};


#endif