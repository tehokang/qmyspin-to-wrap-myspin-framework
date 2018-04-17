#include "UsbDevice.h"
#include "Macro.h"

UsbDevice::UsbDevice(
    string product_name, string manufacturer_name,
    string serial_number, unsigned int product_id, unsigned int vendor_id,
    unsigned int usb_class)
      : Device(product_name, manufacturer_name, serial_number)
      , m_product_id(product_id)
      , m_vendor_id(vendor_id)
      , m_usb_class(usb_class) {

}

UsbDevice::~UsbDevice() {
  LOG_DEBUG("\n");
}
