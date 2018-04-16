#include "TcpScanner.h"

TcpScanner::TcpScanner(ScannerListener &listener)
  : Scanner(listener) {

}

TcpScanner::~TcpScanner() {

}

bool TcpScanner::scan() {

  return true;
}

void TcpScanner::run() {

}