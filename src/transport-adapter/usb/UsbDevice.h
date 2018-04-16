#ifndef __USB_DEVICE_H__
#define __USB_DEVICE_H__

#include "../Device.h"
#include <string>

using namespace std;

class UsbDevice : public Device {
public:
  UsbDevice(string product_name, string manufacturer_name,
      unsigned int product_id, unsigned int vendor_id,
      string serial_number, unsigned int usb_class);
  virtual ~UsbDevice();

protected:
  unsigned int m_product_id;
  unsigned int m_vendor_id;
  string m_serial_number;
  unsigned int m_usb_class;
};


#endif