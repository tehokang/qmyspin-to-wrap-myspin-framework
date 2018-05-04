#ifndef __USB_AOA_CONNECTION_H__
#define __USB_AOA_CONNECTION_H__

#include "Connection.h"
#include "UsbDevice.h"
#include <libusb-1.0/libusb.h>

class AOAPConst {
public:
  static const unsigned int GOOG_VENDOR = 0x18d1;
  static const unsigned int AOAP_PRODUCT_1 = 0x2d00;
  static const unsigned int AOAP_PRODUCT_2 = 0x2d01;
  static const unsigned int AOAP_PRODUCT_3 = 0x2d02;
  static const unsigned int AOAP_PRODUCT_4 = 0x2d03;
  static const unsigned int AOAP_PRODUCT_5 = 0x2d04;
  static const unsigned int AOAP_PRODUCT_6 = 0x2d05;

  static const unsigned int HOST_TO_DEVICE_TYPE = 0xc0;
  static const unsigned int DEVICE_TO_HOST_TYPE = 0x40;

  static const unsigned int ACCESSORY_STRING_MANUFACTURER = 0;
  static const unsigned int ACCESSORY_STRING_MODEL = 1;
  static const unsigned int ACCESSORY_STRING_DESCRIPTION = 2;
  static const unsigned int ACCESSORY_STRING_VERSION = 3;
  static const unsigned int ACCESSORY_STRING_URI = 4;
  static const unsigned int ACCESSORY_STRING_SERIAL = 5;

  static const unsigned int ACCESSORY_GET_PROTOCOL = 51;
  static const unsigned int ACCESSORY_SEND_STRING = 52;
  static const unsigned int ACCESSORY_START = 53;

  static const unsigned int AOA_CLASS = 255;
  static const unsigned int AOA_SUBCLASS = 255;
  static const unsigned int AOA_PROTOCOL = 0;
};



class UsbAOAConnection : public Connection {
public:
  UsbAOAConnection(ConnectionListener &listener);
  virtual ~UsbAOAConnection();

  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual unsigned int receive(Device &device, unsigned char *buffer, unsigned int size) override;

protected:
  virtual void run() override;

  virtual bool __connect__(UsbDevice *device);
  virtual void __disconnect__(UsbDevice *device);
  virtual bool __is_google_accessory__(libusb_device *d);
  virtual bool __is_support_aoap_mode__(libusb_device* d, libusb_device_handle *d_h);
  virtual void __request_turn_on_aoap_mode__(libusb_device* d, libusb_device_handle *d_h);
  virtual bool __turn_on_communication__(libusb_device *d, libusb_device_handle *d_h);
  virtual void __turn_off_communication__(libusb_device *d, libusb_device_handle *d_h);
  virtual int __parse_interfaces__(libusb_device* dev);

  uint8_t m_configure;
  uint8_t m_interface;
  uint8_t m_read_endpoint;
  uint8_t m_write_endpoint;

};

#endif