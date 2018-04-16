#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <list>
#include "Device.h"
#include "../utility/Thread.h"

using namespace std;

class ScannerListener {
public:
  virtual void onScan(list<Device*> devices) = 0;
  virtual void onAttached(Device* device) = 0;
  virtual void onDettached(Device* device) = 0;
};

class Scanner : public Thread {
public:
  Scanner(ScannerListener &listener);
  virtual ~Scanner();

  virtual bool scan() = 0;

protected:
  list<Device*> m_devices;
  ScannerListener &m_listener;
};


#endif