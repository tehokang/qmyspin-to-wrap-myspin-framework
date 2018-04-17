#include "BluetoothDevice.h"

UsbBluetoothDevice::UsbBluetoothDevice(
    string product_name, string manufacturer_name, string serial_number)
    : Device(product_name, manufacturer_name, serial_number) {

}

UsbBluetoothDevice::~UsbBluetoothDevice() {

}
