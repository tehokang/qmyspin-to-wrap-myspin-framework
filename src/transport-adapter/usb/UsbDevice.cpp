#include "UsbDevice.h"

UsbDevice::UsbDevice(
    string product_name, string manufacturer_name,
    unsigned int product_id, unsigned int vendor_id,
    string serial_number, unsigned int usb_class)
      : Device(product_name, manufacturer_name)
      , m_product_id(product_id)
      , m_vendor_id(vendor_id)
      , m_serial_number(serial_number)
      , m_usb_class(usb_class) {

}

UsbDevice::~UsbDevice() {

}
