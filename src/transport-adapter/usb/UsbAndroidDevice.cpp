#include "UsbAndroidDevice.h"

UsbAndroidDevice::UsbAndroidDevice(string product_name, string manufacturer_name,
    unsigned int product_id, unsigned int vendor_id,
    string serial_number, unsigned int usb_class)
    : UsbDevice(product_name, manufacturer_name, product_id, vendor_id, serial_number, usb_class) {

}

UsbAndroidDevice::~UsbAndroidDevice() {

}
