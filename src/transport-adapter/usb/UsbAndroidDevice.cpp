#include "UsbAndroidDevice.h"

UsbAndroidDevice::UsbAndroidDevice(
    string product_name, string manufacturer_name, string serial_number,
    unsigned int product_id, unsigned int vendor_id, unsigned int usb_class)
    : UsbDevice(product_name, manufacturer_name, serial_number, product_id, vendor_id, usb_class) {

}

UsbAndroidDevice::~UsbAndroidDevice() {

}
