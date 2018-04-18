#include "QmySPIN.h"
#include "Macro.h"
#include <unistd.h>

Device *m_android_device = nullptr;
class QmySPINListenerImpl : public QmySPINListener {
public:
  virtual void onScan(list<Device*> devices) {
    LOG_DEBUG("\n");
    int counter = 0;
    for ( list<Device*>::iterator it=devices.begin();
        it!=devices.end(); ++it ) {
      Device *device = (Device*)(*it);
      LOG_DEBUG("[%d] key : %x, product : %s, manufacturer : %s \n",
          ++counter,
          device->getKey(),
          device->getProductName().c_str(),
          device->getManufacturerName().c_str() );

      if ( device->getProductName().compare("SAMSUNG_Android") == 0 ) {
        m_android_device = device;
        LOG_DEBUG("!!!\n");
      }
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

#if 0
  myspin->scan();
  while ( true ) {
    usleep(200*1000);
  }
#else
  char menu = '\0';
  while ( true ) {
    LOG_DEBUG("######################## \n");
    LOG_DEBUG(" s : scan usb devices \n");
    LOG_DEBUG(" c : connect \n");
    LOG_DEBUG(" d : disconnect \n");
    LOG_DEBUG(" x : exit \n");
    LOG_DEBUG("######################## \n");
    LOG_DEBUG("input : " );

    menu = getchar();//scanf("%c", &menu);
    switch ( menu ) {
      case 's' : myspin->scan(); break;
      case 'c' : myspin->select(m_android_device); break;
      case 'd' : myspin->unselect(m_android_device); break;
      case 'x' : goto EXIT;
      default: break;
    }
    usleep(200*1000);
  };
#endif

EXIT:
  QmySPIN::destroyInstance();
  return 0;
}