#ifndef __USB_SCANNER_H__
#define __USB_SCANNER_H__

#include "Scanner.h"
#include <libusb-1.0/libusb.h>
class Device;
class UsbScanner : public Scanner {
public:
  typedef enum _USB_SCANNER_MSG_TYPE_ {
    SCAN
  } UsbScannerMsgType;

  UsbScanner(ScannerListener &listener);
  virtual ~UsbScanner();

  virtual bool init() override;
  virtual bool scan() override;
  virtual void run() override;

protected:

  bool __init_usb_hotplug_callback__();
  void __do_scan_and_notify__();

  Device* __createUsbDevice__(
      string product_name, string manufacturer_name, string serial_number,
      unsigned int vendor_id, unsigned int product_id, unsigned int usb_class);

  Device* __findUsbDevice__(
      string product_name, string manufacturer_name, string serial_number,
      unsigned int vendor_id, unsigned int product_id, unsigned int usb_class);

  void __removeUsbDevice__(
      string product_name, string manufacturer_name, string serial_number,
      unsigned int vendor_id, unsigned int product_id, unsigned int usb_class);

  void __removeAllUsbDevice__();

  libusb_hotplug_callback_handle m_hotplug_callback_handle;

private:
  static int __onUsbHotplugged__(struct libusb_context* ctx, struct libusb_device* device,
      libusb_hotplug_event event, void* user_data);

};



#endif