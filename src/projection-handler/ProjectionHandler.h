#ifndef __PROJECTION_HANDLER_H__
#define __PROJECTION_HANDLER_H__

#include <string>
using namespace std;

class ProjectionListener {
public:
  virtual bool onReqSend(unsigned char *buffer, unsigned int size, void *connection) = 0;
  virtual unsigned int onReqReceive(unsigned char *buffer, unsigned int size, void *connection) = 0;
  virtual void onError(int error) = 0;
  virtual void onFrameUpdateStarted(unsigned int numOfRectangles) = 0;
  virtual void onFrameUpdating(unsigned int currentNumber, unsigned int x, unsigned int y,
    unsigned int width, unsigned int height, unsigned char* buffer, unsigned int bufferSize) = 0;
  virtual void onFrameUpdateEnded() = 0;
  virtual void onReady() = 0;

};

class ProjectionHandler {
public:
  typedef enum PIXEL_FORMAT {
    ePIXELFORMAT_RGB888,
    ePIXELFORMAT_RGB565,
    ePIXELFORMAT_ARGB8888,
    ePIXELFORMAT_RGBA8888
  } PIXEL_FORMAT;

  typedef enum PRESS_TYPE {
    PRESS,
    RELEASE,
    MOVE,
    CANCEL,
  } PRESS_TYPE;

  ProjectionHandler();
  virtual ~ProjectionHandler();

  virtual bool init();
  virtual bool start(void *connected_device);
  virtual void stop();

  void setEventListener(ProjectionListener *listener);
  virtual void setFrameBuffer(
      ProjectionHandler::PIXEL_FORMAT format, unsigned char pixel_bytes,
      unsigned char *frame_buffer,
      unsigned int width, unsigned height, unsigned int dpi);

  virtual void requestFrameBuffer();
  virtual void sendHomeKey(PRESS_TYPE press);
  virtual void sendBackKey(PRESS_TYPE press);
  virtual void sendMenuKey(PRESS_TYPE press);
  virtual void sendSearchKey(PRESS_TYPE press);
  virtual void sendCustomKey(PRESS_TYPE press, int key);
  virtual void sendTouch(unsigned int x, unsigned int y, int finger, PRESS_TYPE action);

  string getAccessoryManufacturerName() { return m_accessory_manufacturer_name; }
  string getAccessoryModelName() { return m_accessory_model_name; }
  string getAccessoryDescription() { return m_accessory_description; }
  string getAccessoryVersion() { return m_accessory_version; }
  string getAccessoryUri() { return m_accessory_uri; }
  string getAccessorySerialNumber() { return m_accessory_serial_number; }

  unsigned int getWidth() { return m_width; }
  unsigned int getHeight() { return m_height; }
  unsigned int getDpi() { return m_dpi; }
  unsigned char *getFrameBuffer() { return m_frame_buffer; }
  PIXEL_FORMAT getPixelFormat() { return m_pixel_format; }

protected:
  ProjectionListener* m_listener;

  PIXEL_FORMAT m_pixel_format;
  unsigned char m_pixel_bytes;
  unsigned char *m_frame_buffer;
  unsigned int m_width;
  unsigned int m_height;
  unsigned int m_dpi;

  string m_accessory_manufacturer_name;
  string m_accessory_model_name;
  string m_accessory_description;
  string m_accessory_version;
  string m_accessory_uri;
  string m_accessory_serial_number;

  void *m_connected_device;
};

#endif