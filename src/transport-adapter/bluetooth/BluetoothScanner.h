#ifndef __BLUETOOTH_SCANNER_H__
#define __BLUETOOTH_SCANNER_H__

#include "../Scanner.h"

class Device;
class BluetoothScanner : public Scanner {
public:
  BluetoothScanner(ScannerListener &listener);
  virtual ~BluetoothScanner();

  virtual bool init() override;
  virtual bool scan() override;
  virtual void run() override;
  virtual list<Device*> getDevices() override;
  virtual void removeUsbDevice(Device *device) override;
protected:

};

#endif