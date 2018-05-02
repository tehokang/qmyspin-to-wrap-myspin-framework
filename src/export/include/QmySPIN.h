#ifndef __QMYSPIN_H__
#define __QMYSPIN_H__

#include <list>
#include <string>
using namespace std;

#include "Device.h"

class QmySPINListener {
public:
  virtual void onScan(list<Device*> devices) = 0;
  virtual void onSelect(Device *device) = 0;
  virtual void onUnselect(Device *device) = 0;
  virtual void onError(int error) = 0;
  virtual void onFrameUpdateStarted(unsigned int numOfRectangles) = 0;
  virtual void onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) = 0;
  virtual void onFrameUpdateEnded() = 0;
  virtual void onReady() = 0;
};

class QmySPIN {
public:
  static QmySPIN* createInstance();
  static QmySPIN* getInstance();
  static void destroyInstance();

  typedef enum PIXEL_FORMAT {
    ePIXELFORMAT_RGB888,
    ePIXELFORMAT_RGB565,
    ePIXELFORMAT_ARGB8888,
    ePIXELFORMAT_RGBA8888
  } PIXEL_FORMAT;

  typedef enum PRESS_TYPE {
    PRESS,
    RELEASE,
  } PRESS_TYPE;

  virtual bool init() = 0;
  virtual bool start() = 0;
  virtual void stop() = 0;
  virtual bool scan() = 0;
  virtual bool select(Device *device) = 0;
  virtual bool unselect(Device *device) = 0;

  virtual void requestFrameBuffer() = 0;
  virtual list<Device*> getDevices() = 0;
  virtual void sendHomeKey(PRESS_TYPE press) = 0;
  virtual void sendBackKey(PRESS_TYPE press) = 0;
  virtual void sendMenuKey(PRESS_TYPE press) = 0;
  virtual void sendSearchKey(PRESS_TYPE press) = 0;
  virtual void sendCustomKey(PRESS_TYPE press, int key) = 0;
  virtual void sendTouch(int x, int y, int finger, int action) = 0;
  virtual void setFrameBuffer(
      PIXEL_FORMAT format, unsigned char *frame_buffer,
      unsigned int width, unsigned height, unsigned int dpi) = 0;

  virtual bool sendVehicle(string message) = 0;

  virtual void addEventListener(QmySPINListener *listener);
  virtual void removeEventListener(QmySPINListener *listener);

  virtual void setLogLevel(bool info, bool debug, bool warn, bool error);
protected:
  QmySPIN();
  virtual ~QmySPIN();

  static QmySPIN *m_instance;
  list<QmySPINListener*> m_listeners;
};

#endif