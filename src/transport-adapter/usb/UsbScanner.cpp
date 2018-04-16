#include "UsbScanner.h"

UsbScanner::UsbScanner(ScannerListener &listener)
  : Scanner(listener) {

}

UsbScanner::~UsbScanner() {

}

bool UsbScanner::scan() {
  return true;
}

void UsbScanner::run() {
  while ( m_running ) {

  }
}