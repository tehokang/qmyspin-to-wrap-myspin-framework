#include "UsbScanner.h"
#include "UsbDevice.h"
#include "Macro.h"
#include <unistd.h>

UsbScanner::UsbScanner(ScannerListener &listener)
  : Scanner(listener) {
  LOG_DEBUG("\n");
}

UsbScanner::~UsbScanner() {

}

bool UsbScanner::init() {
  if ( LIBUSB_SUCCESS != libusb_init(nullptr) ) {
    libusb_exit(nullptr);
    return false;
  }

  return __init_usb_hotplug_callback__();
}

bool UsbScanner::scan() {
  LOG_DEBUG("\n");
  return pushMsg(new ScannerMsg(ScannerMsgType::SCAN, nullptr));
}

void UsbScanner::run() {
  ScannerMsg *msg = nullptr;

  while ( m_running ) {
    if ( ( msg = static_cast<ScannerMsg*>(popMsg()) ) != nullptr ) {
      LOG_DEBUG("\n");
      switch ( msg->getType() ) {
        case ScannerMsgType::SCAN:
          __removeAllUsbDevice__();
          __scan__();
          __notify_scanned__();
          break;
        default:
          LOG_WARNING("Unknown message : %d \n", msg->getType());
          break;
      }
      SAFE_DELETE(msg);
    }
    usleep(100 * 1000);
    struct timeval timeout = { 0, 200 };
    libusb_handle_events_timeout(nullptr, &timeout);
  }
}

bool UsbScanner::__init_usb_hotplug_callback__() {
  libusb_hotplug_event any_event = static_cast<libusb_hotplug_event>
      (LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED | LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT);

  if ( !libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG) ) {
      LOG_ERROR("Error creating hotplug callback\n");
      return false;
  }

  if ( libusb_hotplug_register_callback(nullptr, any_event,
            static_cast<libusb_hotplug_flag>(1),
            LIBUSB_HOTPLUG_MATCH_ANY,
            LIBUSB_HOTPLUG_MATCH_ANY,
            LIBUSB_HOTPLUG_MATCH_ANY,
            UsbScanner::__onUsbHotplugged__, this,
            &m_hotplug_callback_handle) != LIBUSB_SUCCESS ) {
    LOG_ERROR("Error creating hotplug callback\n");
    return false;
  }
  return true;
}

void UsbScanner::__scan__() {
  libusb_device **list = NULL;
  int count = libusb_get_device_list(nullptr, &list);

  for ( int idx = 0; idx < count; ++idx ) {
    libusb_device *device = list[idx];
    __createUsbDevice__(device);
  }
}

void UsbScanner::__notify_scanned__() {
  m_listener.onScan(m_devices);
}

void UsbScanner::__notify_attached__(Device *device) {
  m_listener.onAttached(device);
}

void UsbScanner::__notify__dettached__(Device *device) {
  m_listener.onDettached(device);
}

void UsbScanner::__removeAllUsbDevice__() {
  list<Device*>::iterator it = m_devices.begin();
  while ( it != m_devices.end() ) {
    Device *device = static_cast<UsbDevice*>(*it);
    delete device;
    it = m_devices.erase(it);
  }
}

void UsbScanner::__removeUsbDevice__(libusb_device *device) {
  libusb_device_descriptor desc = {0};

  if ( LIBUSB_SUCCESS == libusb_get_device_descriptor(device, &desc) ) {
    for ( list<Device*>::iterator it = m_devices.begin();
            it != m_devices.end(); ++it ) {
      UsbDevice *device = static_cast<UsbDevice*>(*it);
      if ( device->getProductId() == desc.idProduct &&
          device->getVendorId() == desc.idVendor ) {
        m_devices.remove(*it);

        delete device;
        device = nullptr;
        return;
      }
    }
  }
}

Device* UsbScanner::__findUsbDevice__(libusb_device *device) {
  libusb_device_descriptor desc = {0};

  if ( LIBUSB_SUCCESS == libusb_get_device_descriptor(device, &desc) ) {
    for ( list<Device*>::iterator it = m_devices.begin();
        it != m_devices.end(); ++it ) {
      UsbDevice *device = static_cast<UsbDevice*>(*it);
      if ( device->getProductId() == desc.idProduct &&
          device->getVendorId() == desc.idVendor ) {
        return device;
      }
    }
  }
  LOG_DEBUG("Not found exist USB \n");
  return nullptr;
}

Device* UsbScanner::__createUsbDevice__(libusb_device *device) {
  libusb_device_descriptor desc = {0};
  libusb_device_handle *device_handle = nullptr;

  unsigned char product_name[100] = { 0, };
  unsigned char manufacturer_name[100] = {0, };
  unsigned char serial_number[100] = {0, };
  unsigned int product_id = 0x0000;
  unsigned int vendor_id = 0x0000;
  unsigned int usb_class = 0x00;

  if ( LIBUSB_SUCCESS == libusb_get_device_descriptor(device, &desc) &&
      LIBUSB_SUCCESS == libusb_open(device, &device_handle) ) {

    libusb_get_string_descriptor_ascii(device_handle, desc.iManufacturer,
        manufacturer_name, sizeof(manufacturer_name));
    libusb_get_string_descriptor_ascii(device_handle, desc.iProduct,
        product_name, sizeof(product_name));
    libusb_get_string_descriptor_ascii(device_handle, desc.iSerialNumber,
        serial_number, sizeof(serial_number));
    product_id = desc.idProduct;
    vendor_id = desc.idVendor;
    usb_class = desc.bDeviceClass;
  }

  if ( string((char*)product_name).empty() == true &&
      string((char*)manufacturer_name).empty() == true ) return nullptr;
  /**
   * @note case of device already exist
   */
  for ( list<Device*>::iterator it = m_devices.begin();
      it != m_devices.end(); ++it ) {
    UsbDevice *device = static_cast<UsbDevice*>(*it);
    if ( device->getProductName().compare((char*)product_name) == 0 &&
        device->getManufacturerName().compare((char*)manufacturer_name) == 0 &&
        device->getSerialNumber().compare((char*)serial_number) == 0 ) {
      return device;
    }
  }

  /**
   * @note case of new device
   */
  UsbDevice *new_device = new UsbDevice(
      (const char*)(product_name),
      (const char*)(manufacturer_name),
      (const char*)(serial_number),
      product_id, vendor_id, usb_class);

  LOG_DEBUG("============== Connected ====================\n");
  LOG_DEBUG("product-name: %s \n", new_device->getProductName().c_str());
  LOG_DEBUG("manufacturer-name: %s \n", new_device->getManufacturerName().c_str());
  LOG_DEBUG("vendor-id: 0x%04x \n", new_device->getVendorId());
  LOG_DEBUG("product-id: 0x%04x \n", new_device->getProductId());
  LOG_DEBUG("serial-number: %s \n", new_device->getSerialNumber().c_str());
  LOG_DEBUG("usb-class : %d\n", new_device->getUsbClass());
  LOG_DEBUG("=============================================\n\n");
  m_devices.push_back(new_device);

  return new_device;
}

int UsbScanner::__onUsbHotplugged__(struct libusb_context* ctx, struct libusb_device* device,
    libusb_hotplug_event event, void* user_data)
{
  UsbScanner *scanner = static_cast<UsbScanner*>(user_data);

  switch ( event )
  {
    case LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED:
      {
        UsbDevice* plugin_device = static_cast<UsbDevice*>(scanner->__createUsbDevice__(device));
        if ( plugin_device) scanner->__notify_attached__(plugin_device);
      }
      break;
    case LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT:
      {
        UsbDevice* plugout_device = static_cast<UsbDevice*>(scanner->__findUsbDevice__(device));
        if ( plugout_device) {
          scanner->__notify__dettached__(plugout_device);
          scanner->__removeUsbDevice__(device);
        }
      }
    break;
    default:
      break;
  }

  return 0;
}
