#include "TcpScanner.h"

TcpScanner::TcpScanner(ScannerListener &listener)
  : Scanner(listener) {

}

TcpScanner::~TcpScanner() {

}

bool TcpScanner::init() {

  return true;
}

bool TcpScanner::scan() {

  return true;
}

void TcpScanner::run() {

}

list<Device*> TcpScanner::getDevices() {
  list<Device*> test;
  return test;
}

void TcpScanner::removeUsbDevice(Device *device) {

}