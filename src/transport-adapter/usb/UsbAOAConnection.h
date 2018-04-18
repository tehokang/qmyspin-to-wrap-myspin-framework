#ifndef __USB_AOA_CONNECTION_H__
#define __USB_AOA_CONNECTION_H__

#include "Connection.h"
#include "UsbDevice.h"
#include <libusb-1.0/libusb.h>

class UsbAOAConnection : public Connection {
public:
  UsbAOAConnection(ConnectionListener &listener);
  virtual ~UsbAOAConnection();

  virtual bool connect(Device &device) override;
  virtual void disconnect(Device &device) override;
  virtual bool send(Device &device, unsigned char *buffer, unsigned int size) override;
  virtual bool receive(Device &device, unsigned char *buffer, unsigned int size) override;

protected:
  virtual void run() override;

  virtual bool __connect__(UsbDevice *device);
  virtual void __disconnect__(UsbDevice *device);
  virtual bool __open_device__(UsbDevice &device, libusb_device **d, libusb_device_handle **d_h);
  virtual bool __is_google_accessory__(libusb_device *d);
  virtual bool __is_support_aoap_mode__(libusb_device* d, libusb_device_handle *d_h);
  virtual bool __request_turn_on_aoap_mode__(libusb_device* d, libusb_device_handle *d_h);

  libusb_device *m_connected_device;
  libusb_device_handle *m_connected_device_handle;
  uint8_t m_read_endpoint;
  uint8_t m_write_endpoint;
};

#endif