#ifndef __PROJECTION_HANDLER_H__
#define __PROJECTION_HANDLER_H__

#include <string>
using namespace std;

class ProjectionListener {
public:
  virtual bool onReqSend(unsigned char *buffer, unsigned int size) = 0;
  virtual bool onReqReceive(unsigned char *buffer, unsigned int size) = 0;
  virtual void onError(int error) = 0;
  virtual void onFrameUpdated(unsigned char *buffer, unsigned int size) = 0;
};

class ProjectionHandler {
public:
  ProjectionHandler();
  virtual ~ProjectionHandler();

  virtual bool init();
  virtual bool start();
  virtual void stop();
  virtual bool sendKey(int key, int press);
  virtual bool sendTouch(unsigned int x, unsigned int y, int finger, int action);

  void setEventListener(ProjectionListener *listener);

  string getAccessoryManufacturerName() { return m_accessory_manufacturer_name; }
  string getAccessoryModelName() { return m_accessory_model_name; }
  string getAccessoryDescription() { return m_accessory_description; }
  string getAccessoryVersion() { return m_accessory_version; }
  string getAccessoryUri() { return m_accessory_uri; }
  string getAccessorySerialNumber() { return m_accessory_serial_number; }

protected:
  ProjectionListener* m_listener;

  string m_accessory_manufacturer_name;
  string m_accessory_model_name;
  string m_accessory_description;
  string m_accessory_version;
  string m_accessory_uri;
  string m_accessory_serial_number;
};

#endif