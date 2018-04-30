#ifndef __USB_SCANNER_H__
#define __USB_SCANNER_H__

#include "Scanner.h"
#include <libusb-1.0/libusb.h>

class Device;
class UsbScanner : public Scanner {
public:
  UsbScanner(ScannerListener &listener);
  virtual ~UsbScanner();

  virtual bool init() override;
  virtual bool scan() override;
  virtual void run() override;

  virtual bool start() override;

protected:

  bool __init_usb_hotplug_callback__();

  void __scan__();
  void __notify_scanned__();
  void __notify_attached__(Device *device);
  void __notify_dettached__(Device *device);

  Device* __createUsbDevice__(libusb_device *device);
  void __removeUsbDevice__(libusb_device *device);
  Device* __findUsbDevice__(libusb_device *device);
  void __removeAllUsbDevice__();

  libusb_hotplug_callback_handle m_hotplug_callback_handle;

private:
  static int __onUsbHotplugged__(struct libusb_context* ctx, struct libusb_device* device,
      libusb_hotplug_event event, void* user_data);

};



#endif