#include "Scanner.h"
#include "Macro.h"

Scanner::Scanner(ScannerListener &listener)
  : QueueThread()
  , m_listener(listener) {
  LOG_DEBUG("\n");
}

Scanner::~Scanner() {
  LOG_DEBUG("\n");
}