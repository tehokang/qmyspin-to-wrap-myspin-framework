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

  uint8_t getConfigure() { return m_configure; }
  uint8_t getInterface() { return m_interface; }
  uint8_t getReadEndpoint() { return m_read_endpoint; }
  uint8_t getWriteEndpoint() { return m_write_endpoint; }

  void setConfigure(uint8_t configure) { m_configure = configure; }
  void setInterface(uint8_t interface) { m_interface = interface; }
  void setReadEndpoint(uint8_t read_endpoint) { m_read_endpoint = read_endpoint; }
  void setWriteEndpoint(uint8_t write_endpoint) { m_write_endpoint = write_endpoint; }

protected:
  libusb_device *m_device;
  libusb_device_handle *m_device_handle;
  unsigned int m_product_id;
  unsigned int m_vendor_id;
  unsigned int m_usb_class;

  uint8_t m_configure;
  uint8_t m_interface;
  uint8_t m_read_endpoint;
  uint8_t m_write_endpoint;

};


#endif