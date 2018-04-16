#include "Scanner.h"

Scanner::Scanner(ScannerListener &listener)
  : m_listener(listener) {

}

Scanner::~Scanner() {

}

bool Scanner::scan() {

  return true;
}