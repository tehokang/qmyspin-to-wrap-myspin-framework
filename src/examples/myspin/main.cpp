#include "QmySPIN.h"
#include "Macro.h"

int main(int argc, char ** argv) {
  Logger::setLogLevel(true, true, true, true);

  QmySPIN *myspin = QmySPIN::createInstance();

  if ( myspin->init() ) {
    LOG_DEBUG("Success to init QmySPIN \n");
  }

  QmySPIN::destroyInstance();
  return 0;
}