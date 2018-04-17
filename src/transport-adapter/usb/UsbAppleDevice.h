#ifndef __USB_APPLE_DEVICE_H__
#define __USB_APPLE_DEVICE_H__

#include "UsbDevice.h"

class UsbAppleDevice : public UsbDevice {
public:
  UsbAppleDevice(string product_name, string manufacturer_name,
    unsigned int product_id, unsigned int vendor_id,
    string serial_number, unsigned int usb_class);
  virtual ~UsbAppleDevice();

protected:

};

#endif