#include "QmySPIN.h"
#include "Macro.h"
#include <unistd.h>

class QmySPINListenerImpl : public QmySPINListener {
public:
  virtual void onScan(list<Device*> devices) {
    LOG_DEBUG("\n");
    for ( list<Device*>::iterator it=devices.begin();
        it!=devices.end(); ++it ) {
      Device *device = (Device*)(*it);
      LOG_DEBUG("key : %x, product : %s, manufacturer : %s \n",
          device->getKey(),
          device->getProductName().c_str(),
          device->getManufacturerName().c_str() );
    }
  }

  virtual void onSelect(Device *device) {
    LOG_DEBUG("\n");
  }

  virtual void onUnselect(Device *device) {
    LOG_DEBUG("\n");
  }

  virtual void onError(int error) {
    LOG_DEBUG("\n");
  }

  virtual void onFrameUpdate() {
    LOG_DEBUG("\n");
  }
};

int main(int argc, char ** argv) {
  Logger::setLogLevel(true, true, true, true);

  QmySPIN *myspin = QmySPIN::createInstance();

  myspin->addEventListener(new QmySPINListenerImpl());

  if ( myspin->init() == false ) {
    LOG_ERROR("Fail to init QmySPIN \n");
  }

  if ( myspin->start() == false ) {
    LOG_ERROR("Fail to start QmySPIN \n");
  }

  while ( true ) {
    usleep(200*1000);
  };

  // if ( myspin->scan() == false ) {
  //   LOG_ERROR("Fail to scan via QmySPIN \n");
  // }

  QmySPIN::destroyInstance();
  return 0;
}