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
  return pushMsg(new ScannerMsg(UsbScannerMsgType::SCAN, nullptr));
}

void UsbScanner::run() {
  ScannerMsg *msg = nullptr;

  while ( m_running ) {
    if ( ( msg = static_cast<ScannerMsg*>(popMsg()) ) != nullptr ) {
      switch ( msg->getType() ) {
        case UsbScannerMsgType::SCAN:
          __removeAllUsbDevice__();

          __do_scan_and_notify__();
          break;
        default:
          LOG_WARNING("Unknown message : %d \n", msg->getType());
          break;
      }
      SAFE_DELETE(msg);
    }
    usleep(100 * 1000);
    libusb_handle_events(nullptr);
  }
}

bool UsbScanner::__init_usb_hotplug_callback__() {
  libusb_hotplug_event any_event = static_cast<libusb_hotplug_event>
      (LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED | LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT);

  if ( !libusb_has_capability(LIBUSB_CAP_HAS_HOTPLUG) )
  {
      LOG_DEBUG("Error creating hotplug callback\n");
      return false;
  }

  if ( libusb_hotplug_register_callback(nullptr, any_event,
            static_cast<libusb_hotplug_flag>(1),
            LIBUSB_HOTPLUG_MATCH_ANY,
            LIBUSB_HOTPLUG_MATCH_ANY,
            LIBUSB_HOTPLUG_MATCH_ANY,
            UsbScanner::__onUsbHotplugged__, this,
            &m_hotplug_callback_handle) != LIBUSB_SUCCESS ) {
    LOG_DEBUG("Error creating hotplug callback\n");
    return false;
  }
  return true;
}

void UsbScanner::__do_scan_and_notify__() {
  libusb_device **list = NULL;
  int count = libusb_get_device_list(nullptr, &list);

  for ( int idx = 0; idx < count; ++idx ) {
    libusb_device *device = list[idx];
    libusb_device_descriptor desc = {0};
    libusb_device_handle *device_handle = nullptr;

    if ( 0 == libusb_get_device_descriptor(device, &desc) ) {
      unsigned char product_name[100] = { 0, };
      unsigned char manufacturer_name[100] = {0, };
      unsigned char serial_number[100] = {0, };

      libusb_open(device, &device_handle);
      libusb_get_string_descriptor_ascii(device_handle, desc.iManufacturer,
          manufacturer_name, sizeof(manufacturer_name));
      libusb_get_string_descriptor_ascii(device_handle, desc.iProduct,
          product_name, sizeof(product_name));
      libusb_get_string_descriptor_ascii(device_handle, desc.iSerialNumber,
          serial_number, sizeof(serial_number));

      __createUsbDevice__(
          (char*)product_name, (char*)manufacturer_name, (char*)serial_number,
          desc.idProduct, desc.idVendor, desc.bDeviceClass);
    }
  }
  m_listener.onScan(m_devices);
}

void UsbScanner::__removeAllUsbDevice__() {
  list<Device*>::iterator it = m_devices.begin();
  while ( it != m_devices.end() ) {
    Device *device = static_cast<UsbDevice*>(*it);
    delete device;
    it = m_devices.erase(it);
  }
}

void UsbScanner::__removeUsbDevice__(
    string product_name, string manufacturer_name, string serial_number,
    unsigned int vendor_id, unsigned int product_id, unsigned int usb_class)
{
    for ( list<Device*>::iterator it=m_devices.begin();
            it!=m_devices.end(); ++it )
    {
        UsbDevice *device = static_cast<UsbDevice*>(*it);
        if ( device->getProductName().compare(product_name) == 0 &&
            device->getManufacturerName().compare(manufacturer_name) == 0 &&
            device->getSerialNumber().compare(serial_number) == 0 )
        {
            m_devices.remove(*it);

            delete device;
            device = nullptr;
            return;
        }
    }
}

Device* UsbScanner::__findUsbDevice__(
    string product_name, string manufacturer_name, string serial_number,
    unsigned int vendor_id, unsigned int product_id, unsigned int usb_class)
{
    for ( list<Device*>::iterator it=m_devices.begin();
        it!=m_devices.end(); ++it )
    {
        UsbDevice *device = static_cast<UsbDevice*>(*it);
        if ( device->getProductName().compare(product_name) == 0 &&
            device->getManufacturerName().compare(manufacturer_name) == 0 &&
            device->getSerialNumber().compare(serial_number) == 0 )
        {
            return device;
        }
    }
    LOG_DEBUG("Not found exist USB \n");
    return nullptr;
}

Device* UsbScanner::__createUsbDevice__(
    string product_name, string manufacturer_name, string serial_number,
    unsigned int vendor_id, unsigned int product_id, unsigned int usb_class)
{
    for ( list<Device*>::iterator it=m_devices.begin();
        it!=m_devices.end(); ++it )
    {
        UsbDevice *device = static_cast<UsbDevice*>(*it);
        if ( device->getProductName().compare(product_name) == 0 &&
            device->getManufacturerName().compare(manufacturer_name) == 0 &&
            device->getSerialNumber().compare(serial_number) == 0 )
        {
            return device;
        }
    }

    UsbDevice *device = new UsbDevice(product_name, manufacturer_name, serial_number,
        product_id, vendor_id, usb_class );
    m_devices.push_back(device);

    LOG_DEBUG("============== Connected ====================\n");
    LOG_DEBUG("product-name: %s \n", device->getProductName().c_str());
    LOG_DEBUG("manufacturer-name: %s \n", device->getManufacturerName().c_str());
    LOG_DEBUG("vendor-id: %x \n", device->getVendorId());
    LOG_DEBUG("product-id: %x \n", device->getProductId());
    LOG_DEBUG("serial-number: %s \n", device->getSerialNumber().c_str());
    LOG_DEBUG("usb-class : %x\n",device->getUsbClass());
    LOG_DEBUG("=============================================\n\n");
    return device;
}


int UsbScanner::__onUsbHotplugged__(struct libusb_context* ctx, struct libusb_device* device,
    libusb_hotplug_event event, void* user_data)
{
  UsbScanner *scanner = static_cast<UsbScanner*>(user_data);

  libusb_device_descriptor desc;
  libusb_get_device_descriptor(device, &desc);

  switch ( event )
  {
      case LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED:
      case LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT:
        {
          scanner->__removeAllUsbDevice__();
          scanner->__do_scan_and_notify__();
        }
        break;
      default:
          break;
  }
  return 0;
}
