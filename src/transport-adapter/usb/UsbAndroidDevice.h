#ifndef __USB_ANDROID_DEVICE_H__
#define __USB_ANDROID_DEVICE_H__

#include "UsbDevice.h"

class UsbAndroidDevice : public UsbDevice {
public:
  UsbAndroidDevice(string product_name, string manufacturer_name,
    unsigned int product_id, unsigned int vendor_id,
    string serial_number, unsigned int usb_class);
  virtual ~UsbAndroidDevice();

protected:

};

#endif