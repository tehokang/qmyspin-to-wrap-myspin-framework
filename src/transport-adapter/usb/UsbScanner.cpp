#include "UsbScanner.h"
#include "UsbDevice.h"
#include "Macro.h"
#include <unistd.h>

UsbScanner::UsbScanner(ScannerListener &listener)
  : Scanner(listener) {
  LOG_DEBUG("\n");
}

UsbScanner::~UsbScanner() {
  __removeAllUsbDevice__();
}

bool UsbScanner::init() {
  if ( LIBUSB_SUCCESS != libusb_init(nullptr) ) {
    libusb_exit(nullptr);
    return false;
  }
  return true;
}

bool UsbScanner::start() {
  Scanner::start();
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
    usleep(10*1000);
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
  LOG_DEBUG("\n");
  libusb_device **list = nullptr;
  int count = libusb_get_device_list(nullptr, &list);

  for ( int idx = 0; idx < count; ++idx ) {
    libusb_device *device = list[idx];
    __createUsbDevice__(device);
  }
}

void UsbScanner::__notify_scanned__() {
  LOG_DEBUG("\n");
  m_listener.onScan(m_devices);
}

void UsbScanner::__notify_attached__(Device *device) {
  LOG_DEBUG("\n");
  m_listener.onAttached(device);
}

void UsbScanner::__notify_dettached__(Device *device) {
  LOG_DEBUG("\n");
  m_listener.onDettached(device);
}

void UsbScanner::__removeAllUsbDevice__() {
  LOG_DEBUG("\n");
  list<Device*>::iterator it = m_devices.begin();
  while ( it != m_devices.end() ) {
    Device *device = static_cast<UsbDevice*>(*it);
    delete device;
    device = nullptr;
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
    UsbDevice *usb = static_cast<UsbDevice*>(*it);
    if ( usb->getProductName().compare((char*)product_name) == 0 &&
        usb->getManufacturerName().compare((char*)manufacturer_name) == 0 &&
        usb->getSerialNumber().compare((char*)serial_number) == 0 &&
        usb->getDevice() == device ) {
      LOG_INFO("This already exist \n");
      usb->updateDeviceHandle(device_handle);
      return usb;
    }
  }

  /**
   * @note case of new device
   */
  UsbDevice *new_device = new UsbDevice(
      (const char*)(product_name),
      (const char*)(manufacturer_name),
      (const char*)(serial_number),
      device, device_handle,
      product_id, vendor_id, usb_class);

  LOG_INFO("============== Connected ====================\n");
  LOG_INFO("product-name: %s \n", new_device->getProductName().c_str());
  LOG_INFO("manufacturer-name: %s \n", new_device->getManufacturerName().c_str());
  LOG_INFO("vendor-id: 0x%04x \n", new_device->getVendorId());
  LOG_INFO("product-id: 0x%04x \n", new_device->getProductId());
  LOG_INFO("serial-number: %s \n", new_device->getSerialNumber().c_str());
  LOG_INFO("usb-class : %d\n", new_device->getUsbClass());
  LOG_INFO("device : %p \n", new_device->getDevice());
  LOG_INFO("device-handle : %p \n", new_device->getDeviceHandle());
  LOG_INFO("=============================================\n\n");
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
        LOG_DEBUG("LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED \n");
        UsbDevice* plugin_device = static_cast<UsbDevice*>(scanner->__createUsbDevice__(device));
        if ( plugin_device) scanner->__notify_attached__(plugin_device);
      }
      break;
    case LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT:
      {
        LOG_DEBUG("LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT \n");
        UsbDevice* plugout_device = static_cast<UsbDevice*>(scanner->__findUsbDevice__(device));
        if ( plugout_device) {
          scanner->__notify_dettached__(plugout_device);
          scanner->__removeUsbDevice__(device);
        }
      }
    break;
    default:
      break;
  }

  return 0;
}
