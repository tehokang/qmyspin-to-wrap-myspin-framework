#include "BluetoothScanner.h"

BluetoothScanner::BluetoothScanner(ScannerListener &listener)
  : Scanner(listener) {

}

BluetoothScanner::~BluetoothScanner() {

}

bool BluetoothScanner::scan() {

  return true;
}

void BluetoothScanner::run() {

}