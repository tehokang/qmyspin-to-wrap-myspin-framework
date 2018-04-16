#ifndef __TCP_SCANNER_H__
#define __TCP_SCANNER_H__

#include "../Scanner.h"

class TcpScanner : public Scanner {
public:
  TcpScanner(ScannerListener &listener);
  virtual ~TcpScanner();

  virtual bool scan() override;
  virtual void run() override;
protected:

};

#endif