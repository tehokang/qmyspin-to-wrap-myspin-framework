#ifndef __USB_BLUETOOTH_DEVICE_H__
#define __USB_BLUETOOTH_DEVICE_H__

#include "../Device.h"

class UsbBluetoothDevice : public Device {
public:
  UsbBluetoothDevice(string product_name, string manufacturer_name);
  virtual ~UsbBluetoothDevice();

protected:

};

#endif