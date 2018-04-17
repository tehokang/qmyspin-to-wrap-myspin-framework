#ifndef __USB_DEVICE_H__
#define __USB_DEVICE_H__

#include "Device.h"
#include <string>

using namespace std;

class UsbDevice : public Device {
public:
  UsbDevice(string product_name, string manufacturer_name, string serial_number,
      unsigned int product_id, unsigned int vendor_id, unsigned int usb_class);
  virtual ~UsbDevice();

  unsigned int getProductId() { return m_product_id; }
  unsigned int getVendorId() { return m_vendor_id; }
  unsigned int getUsbClass() { return m_usb_class; }

protected:
  unsigned int m_product_id;
  unsigned int m_vendor_id;
  unsigned int m_usb_class;
};


#endif