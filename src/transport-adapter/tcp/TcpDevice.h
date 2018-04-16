#ifndef __TCP_DEVICE_H__
#define __TCP_DEVICE_H__

#include "../Device.h"

class TcpDevice : public Device {
public:
  TcpDevice(string product_name, string manufacturer_name);
  virtual ~TcpDevice();

protected:

};

#endif