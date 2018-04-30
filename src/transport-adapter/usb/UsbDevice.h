#ifndef __USB_DEVICE_H__
#define __USB_DEVICE_H__

#include "Device.h"
#include <string>
#include <libusb-1.0/libusb.h>

using namespace std;

class UsbDevice : public Device {
public:
  UsbDevice(string product_name, string manufacturer_name, string serial_number,
      libusb_device *device, libusb_device_handle *device_handle,
      unsigned int product_id, unsigned int vendor_id, unsigned int usb_class);
  virtual ~UsbDevice();

  libusb_device *getDevice() { return m_device; }
  libusb_device_handle *getDeviceHandle() { return m_device_handle; }
  unsigned int getProductId() { return m_product_id; }
  unsigned int getVendorId() { return m_vendor_id; }
  unsigned int getUsbClass() { return m_usb_class; }
  void updateDeviceHandle(libusb_device_handle *d_h) { m_device_handle = d_h; }

protected:
  libusb_device *m_device;
  libusb_device_handle *m_device_handle;
  unsigned int m_product_id;
  unsigned int m_vendor_id;
  unsigned int m_usb_class;
};


#endif