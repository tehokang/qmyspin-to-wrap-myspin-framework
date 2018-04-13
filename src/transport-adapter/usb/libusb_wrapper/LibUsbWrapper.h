#ifndef __LIBUSB_WRAPPER_H__
#define __LIBUSB_WRAPPER_H__

#include "Thread.h"

class LibUsbWrapperListener {
public:
  void onAttached()
};

class LibUsbWrapper : public Thread {
public:
  LibUsbWrapper();
  virtual ~LibUsbWrapper();

  virtual bool init();
  virtual bool start();
  virtual void stop();


private:

};

#endif