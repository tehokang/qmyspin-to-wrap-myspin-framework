#include "UsbDevice.h"
#include "Macro.h"

UsbDevice::UsbDevice(
    string product_name, string manufacturer_name, string serial_number,
    libusb_device *device, libusb_device_handle *device_handle,
    unsigned int product_id, unsigned int vendor_id, unsigned int usb_class)
  : Device(product_name, manufacturer_name, serial_number)
  , m_device(device)
  , m_device_handle(device_handle)
  , m_product_id(product_id)
  , m_vendor_id(vendor_id)
  , m_usb_class(usb_class)
  , m_configure(0xff)
  , m_interface(0xff)
  , m_read_endpoint(0xff)
  , m_write_endpoint(0xff) {
  LOG_INFO("%p \n", this);
}

UsbDevice::~UsbDevice() {
  LOG_INFO("%p \n", this);
}
