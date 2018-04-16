#ifndef __BLUETOOTH_SCANNER_H__
#define __BLUETOOTH_SCANNER_H__

#include "../Scanner.h"

class BluetoothScanner : public Scanner {
public:
  BluetoothScanner(ScannerListener &listener);
  virtual ~BluetoothScanner();

  virtual bool scan() override;
  virtual void run() override;

protected:

};

#endif