#include "BluetoothScanner.h"

BluetoothScanner::BluetoothScanner(ScannerListener &listener)
  : Scanner(listener) {

}

BluetoothScanner::~BluetoothScanner() {

}

bool BluetoothScanner::init() {

  return true;
}

bool BluetoothScanner::scan() {

  return true;
}

void BluetoothScanner::run() {

}

list<Device*> BluetoothScanner::getDevices() {
  list<Device*> test;
  return test;
}

void BluetoothScanner::removeUsbDevice(Device *device) {

}