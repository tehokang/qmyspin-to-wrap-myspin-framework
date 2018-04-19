#include "QmySPIN.h"
#include <unistd.h>
#include <stdio.h>

Device *m_android_device = nullptr;
class QmySPINListenerImpl : public QmySPINListener {
public:
  virtual void onScan(list<Device*> devices) {
    printf("[%s:%d] \n", __FUNCTION__, __LINE__);
    int counter = 0;
    for ( list<Device*>::iterator it=devices.begin();
        it!=devices.end(); ++it ) {
      Device *device = (Device*)(*it);
      printf("[%d] key : %x, product : %s, manufacturer : %s \n",
          ++counter,
          device->getKey(),
          device->getProductName().c_str(),
          device->getManufacturerName().c_str() );

      if ( device->getProductName().compare("SAMSUNG_Android") == 0 ) {
        m_android_device = device;
        printf("!!!\n");
      }
    }
  }

  virtual void onSelect(Device *device) {
    printf("[%s:%d] \n", __FUNCTION__, __LINE__);
    m_android_device = device;
  }

  virtual void onUnselect(Device *device) {
    printf("[%s:%d] \n", __FUNCTION__, __LINE__);
    m_android_device = nullptr;
  }

  virtual void onError(int error) {
    printf("[%s:%d] \n", __FUNCTION__, __LINE__);
  }

  virtual void onFrameUpdateStarted(unsigned int numOfRectangles) {
    printf("[%s:%d] rectangles : %d \n", __FUNCTION__, __LINE__, numOfRectangles);

  }

  virtual void onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) {
    printf("[%s:%d] currentNumber : %d \n", __FUNCTION__, __LINE__, currentNumber);

  }

  virtual void onFrameUpdateEnded() {
    printf("[%s:%d] \n", __FUNCTION__, __LINE__);
  }
};

int main(int argc, char ** argv) {
  unsigned int width = 800;
  unsigned int height = 480;
  unsigned int dpi = 96;
  unsigned char frame_buffer[width*height*4];
  QmySPIN::PIXEL_FORMAT pixel_format = QmySPIN::PIXEL_FORMAT::ePIXELFORMAT_RGBA8888;

  QmySPIN *myspin = QmySPIN::createInstance();
  myspin->setLogLevel(true, true, true, true);
  myspin->setFrameBuffer(pixel_format, frame_buffer, width, height, dpi);
  myspin->addEventListener(new QmySPINListenerImpl());

  if ( myspin->init() == false ) {
    printf("Fail to init QmySPIN \n");
  }

  if ( myspin->start() == false ) {
    printf("Fail to start QmySPIN \n");
  }

#if 0
  myspin->scan();
  while ( true ) {
    usleep(200*1000);
  }
#else
  char menu = '\0';
  while ( true ) {
    printf("######################## \n");
    printf(" s : scan usb devices \n");
    printf(" c : connect \n");
    printf(" d : disconnect \n");
    printf(" x : exit \n");
    printf("######################## \n");
    printf("input : " );

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