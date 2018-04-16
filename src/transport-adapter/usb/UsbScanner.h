#ifndef __USB_SCANNER_H__
#define __USB_SCANNER_H__

#include "../Scanner.h"

class UsbScanner : public Scanner {
public:
  UsbScanner(ScannerListener &listener);
  virtual ~UsbScanner();

  virtual bool scan() override;
  virtual void run() override;

protected:
};



#endif