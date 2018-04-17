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
  virtual void onFrameUpdate() = 0;
};

class QmySPIN {
public:
  static QmySPIN* createInstance();
  static QmySPIN* getInstance();
  static void destroyInstance();

  typedef enum {
    ePIXELFORMAT_RGB888 = 1,
    ePIXELFORMAT_RGB565 = 2,
    ePIXELFORMAT_ARGB8888 = 3,
    ePIXELFORMAT_RGBA8888 = 4
  } PIXEL_FORMAT;

  virtual bool init() = 0;
  virtual bool start() = 0;
  virtual void stop() = 0;
  virtual bool scan() = 0;
  virtual bool select(Device *device) = 0;
  virtual bool unselect(Device *device) = 0;

  virtual bool sendKey(int key, int press) = 0;
  virtual bool sendTouch(int x, int y, int finger, int action) = 0;
  virtual bool sendVehicle(string message) = 0;

  virtual void addEventListener(QmySPINListener *listener);
  virtual void removeEventListener(QmySPINListener *listener);
  virtual void setFrameBuffer(
      PIXEL_FORMAT format, unsigned char *frame_buffer, unsigned int width, unsigned height);


protected:
  QmySPIN();
  virtual ~QmySPIN();

  static QmySPIN *m_instance;
  list<QmySPINListener*> m_listeners;
  PIXEL_FORMAT m_pixel_format;
  unsigned int m_width;
  unsigned int m_height;
  unsigned char *m_frame_buffer;
};

#endif