#include "UsbAOAConnection.h"
#include "UsbDevice.h"
#include "Macro.h"
#include <unistd.h>

#define ACCESSORY_MANUFACTURER_NAME "BSOT"
#define ACCESSORY_MODEL_NAME "mySPIN"
#define ACCESSORY_DESCRIPTION "mySPIN"
#define ACCESSORY_VERSION "0.1"
#define ACCESSORY_URI "com.bosch.myspin.launcherapp.cn"
#define ACCESSORY_SERIAL_NUMBER "0000000012345678"

UsbAOAConnection::UsbAOAConnection(ConnectionListener &listener)
  : Connection(listener) {

}

UsbAOAConnection::~UsbAOAConnection() {

}

bool UsbAOAConnection::connect(Device &device) {
  LOG_DEBUG("\n");
  return pushMsg(new ConnectionMsg(ConnectionMsgType::CONNECT, &device));
}

void UsbAOAConnection::disconnect(Device &device) {
  LOG_DEBUG("\n");
  pushMsg(new ConnectionMsg(ConnectionMsgType::DISCONNECT, &device));
}

bool UsbAOAConnection::send(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_NULL(m_connected_device_handle);

  int sizeout = 0;
  int ret = libusb_bulk_transfer(m_connected_device_handle, m_write_endpoint,
          (uint8_t*) buffer, size, &sizeout, 1000);

  if ( ret != LIBUSB_SUCCESS && ret != LIBUSB_ERROR_TIMEOUT ) {
      LOG_WARNING("Error when writing to usb: %s\n", libusb_error_name(ret));
      return false;
  } else if (ret == LIBUSB_ERROR_TIMEOUT) {
      LOG_ERROR("Timeout on usb write\n");
      return false;
  }
  return true;
}

bool UsbAOAConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_NULL(m_connected_device_handle);

  int sizeout = 0;
  int ret = libusb_bulk_transfer(m_connected_device_handle, m_read_endpoint,
      buffer, size, &sizeout, 1000);

  if ( ret != LIBUSB_SUCCESS && ret != LIBUSB_ERROR_TIMEOUT )
  {
      LOG_ERROR("Error when reading from usb: %s\n", libusb_error_name(ret));
      return false;
  }
  return true;
}

void UsbAOAConnection::run() {
  ConnectionMsg *msg = nullptr;

  while ( m_running ) {
    if ( ( msg = static_cast<ConnectionMsg*>(popMsg()) ) != nullptr ) {
      switch ( msg->getType() ) {
        case ConnectionMsgType::CONNECT:
          __connect__(static_cast<UsbDevice*>(msg->getMsg()));
          break;
        case ConnectionMsgType::DISCONNECT:
          __disconnect__(static_cast<UsbDevice*>(msg->getMsg()));
          break;
        default:
          LOG_WARNING("Unknown message : %d \n", msg->getType());
          break;
      }
      SAFE_DELETE(msg);
    }
    usleep(100 * 1000);
  }
}

bool UsbAOAConnection::__connect__(UsbDevice *device) {
  libusb_device *d = nullptr;
  libusb_device_handle *d_h = nullptr;

  RETURN_FALSE_IF_FALSE(__open_device__(*device, &d, &d_h));

  if ( __is_google_accessory__(d) == true ) {
    m_listener.onConnect(device);
    LOG_DEBUG("%s is ready for communication as accessory \n",
        device->getProductName().c_str());
  } else {
    if ( __is_support_aoap_mode__(d, d_h) == true ) {
      __request_turn_on_aoap_mode__(d, d_h);
    } else {
      return false;
    }
  }

  m_connected_device = d;
  m_connected_device_handle = d_h;
  return true;
}

void UsbAOAConnection::__disconnect__(UsbDevice *device) {
  LOG_DEBUG("\n");
  if ( m_connected_device_handle ) {
    libusb_close(m_connected_device_handle);
    m_connected_device_handle = nullptr;
    m_connected_device = nullptr;
  }

  m_listener.onDisconnect(device);
}

bool UsbAOAConnection::__open_device__(
  UsbDevice &device, libusb_device **d, libusb_device_handle **d_h) {
  libusb_device **list;
  int cnt = libusb_get_device_list(NULL, &list);

  for (int i = 0; i < cnt; i++) {
      libusb_device *tmp = list[i];

      libusb_device_descriptor desc = {0};
      if ( LIBUSB_SUCCESS == libusb_get_device_descriptor(tmp, &desc) &&
          device.getProductId() == desc.idProduct &&
          device.getVendorId() == desc.idVendor ) {
        libusb_free_device_list(list, 1);
        *d = tmp;
        if ( LIBUSB_SUCCESS == libusb_open(*d, &(*d_h)) ) {
          return true;
        }
      }
  }
  return false;
}

bool UsbAOAConnection::__is_google_accessory__(libusb_device* d) {
  libusb_device_descriptor desc = {0};
  if ( LIBUSB_SUCCESS == libusb_get_device_descriptor(d, &desc) ) {
    if ( desc.idProduct != AOAPConst::AOAP_PRODUCT_1 && desc.idProduct != AOAPConst::AOAP_PRODUCT_2 &&
      desc.idProduct != AOAPConst::AOAP_PRODUCT_3 && desc.idProduct != AOAPConst::AOAP_PRODUCT_4 &&
      desc.idProduct != AOAPConst::AOAP_PRODUCT_5 && desc.idProduct != AOAPConst::AOAP_PRODUCT_6 ) {
      LOG_WARNING("This is not google accessory then we will ask whether it can suuport \n");
      return false;
    }
  }
  return true;
}

bool UsbAOAConnection::__is_support_aoap_mode__(libusb_device* d, libusb_device_handle *d_h) {
  uint8_t buffer[2];
  if ( 0 > libusb_control_transfer(d_h, AOAPConst::HOST_TO_DEVICE_TYPE,
          AOAPConst::ACCESSORY_GET_PROTOCOL, 0, 0, (uint8_t*)buffer, 2, 0) ) {
    LOG_WARNING("ACCESSORY_GET_PROTOCOL=[%u][%u] \n", buffer[0], buffer[1]);
    LOG_WARNING("This device can't support accessory mode \n\n");
    return false;
  }
  LOG_DEBUG("This device can support accessory mode \n\n");
  return true;
}

bool UsbAOAConnection::__request_turn_on_aoap_mode__(
    libusb_device* d, libusb_device_handle *d_h) {

  if ( LIBUSB_SUCCESS == libusb_open(d, &d_h) ) {
    LOG_DEBUG("\n");
    auto sendString = [](libusb_device_handle* handle, const char* str, int index)->int
    {
        return libusb_control_transfer(handle, AOAPConst::DEVICE_TO_HOST_TYPE,
                AOAPConst::ACCESSORY_SEND_STRING, 0, index, (uint8_t*)str, strlen(str) + 1, 0);
    };

    sendString(d_h, ACCESSORY_MANUFACTURER_NAME, AOAPConst::ACCESSORY_STRING_MANUFACTURER);
    sendString(d_h, ACCESSORY_MODEL_NAME, AOAPConst::ACCESSORY_STRING_MODEL);
    sendString(d_h, ACCESSORY_DESCRIPTION, AOAPConst::ACCESSORY_STRING_DESCRIPTION);
    sendString(d_h, ACCESSORY_VERSION, AOAPConst::ACCESSORY_STRING_VERSION);
    sendString(d_h, ACCESSORY_URI, AOAPConst::ACCESSORY_STRING_URI);
    sendString(d_h, ACCESSORY_SERIAL_NUMBER, AOAPConst::ACCESSORY_STRING_SERIAL);

    libusb_control_transfer(d_h, AOAPConst::DEVICE_TO_HOST_TYPE,
            AOAPConst::ACCESSORY_START, 0, 0, nullptr, 0, 0);
    return true;
  }
  return false;
}