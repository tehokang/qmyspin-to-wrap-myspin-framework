#include "UsbAOAConnection.h"
#include "UsbDevice.h"
#include "Macro.h"
#include <unistd.h>

UsbAOAConnection::UsbAOAConnection(ConnectionListener &listener)
  : Connection(listener) {
}

UsbAOAConnection::~UsbAOAConnection() {
  LOG_DEBUG("\n");
}

bool UsbAOAConnection::connect(Device &device) {
  LOG_DEBUG("\n");
  return __connect__(static_cast<UsbDevice*>(&device));
}

void UsbAOAConnection::disconnect(Device &device) {
  LOG_DEBUG("\n");
  __disconnect__(static_cast<UsbDevice*>(&device));
}

bool UsbAOAConnection::send(Device &device, unsigned char *buffer, unsigned int size) {
  UsbDevice *usb = static_cast<UsbDevice*>(&device);
  RETURN_FALSE_IF_TRUE( !usb || !usb->getDeviceHandle() );

  __logging_buffer__(buffer, size);

  int sizeout = 0;
  int ret = libusb_bulk_transfer(usb->getDeviceHandle(), usb->getWriteEndpoint(),
      (uint8_t*) buffer, size, &sizeout, 5000);

  if ( ret != LIBUSB_SUCCESS ) {
      LOG_WARNING("Error when writing to usb: %s\n", libusb_error_name(ret));
      return false;
  }
  LOG_DEBUG("sent ? %s \n", size == (unsigned int)sizeout ? "good" : "bad");
  return true;
}

unsigned int UsbAOAConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {
  UsbDevice *usb = static_cast<UsbDevice*>(&device);
  if ( !usb || !usb->getDeviceHandle() ) return 0;

  int sizeout = 0;
  int ret = libusb_bulk_transfer(usb->getDeviceHandle(), usb->getReadEndpoint(),
      buffer, size, &sizeout, 5000);

  if ( ret != LIBUSB_SUCCESS && ret != LIBUSB_ERROR_TIMEOUT ) {
    LOG_ERROR("Error when reading from usb: %s\n", libusb_error_name(ret));
  }
  __logging_buffer__(buffer, sizeout);

  return sizeout;
}

bool UsbAOAConnection::__connect__(UsbDevice *device) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_NULL(device);

  if ( __is_google_accessory__(device) == true ) {
    RETURN_FALSE_IF_FALSE(__parse_interfaces__(device) == LIBUSB_SUCCESS);
    RETURN_FALSE_IF_FALSE(__turn_on_communication__(device));
    m_listener.onConnect(device);
  } else {
    if ( __is_support_aoap_mode__(device) == true ) {
      __request_turn_on_aoap_mode__(device);
    } else {
      m_listener.onError(-1);
      return false;
    }
  }
  return true;
}

void UsbAOAConnection::__disconnect__(UsbDevice *device) {
  LOG_DEBUG("\n");
  if ( device && device->getDeviceHandle() ) {
    __turn_off_communication__(device);
  }
  m_listener.onDisconnect(device);
}

void UsbAOAConnection::run() {
  ConnectionMsg *msg = nullptr;

  while ( m_running ) {
    if ( ( msg = static_cast<ConnectionMsg*>(popMsg()) ) != nullptr ) {
      LOG_DEBUG("\n");
      switch ( msg->getType() ) {
        default:
          LOG_WARNING("Unknown message : %d \n", msg->getType());
          break;
      }
      SAFE_DELETE(msg);
    }
    struct timeval timeout = { 0, 100 };
    libusb_handle_events_timeout(nullptr, &timeout);
  }
}

int UsbAOAConnection::__parse_interfaces__(UsbDevice *device) {
    int ret = LIBUSB_ERROR_OTHER;
    libusb_device *dev = device->getDevice();
    libusb_config_descriptor* config_descriptor;
    libusb_get_active_config_descriptor(dev, &config_descriptor);
    device->setConfigure(config_descriptor->bConfigurationValue);

    LOG_DEBUG("number of interfaces : %d \n", config_descriptor->bNumInterfaces);

    for (int j = 0; j < config_descriptor->bNumInterfaces; ++j) {
        const libusb_interface* interface = &config_descriptor->interface[j];
        LOG_DEBUG("\tnumber of [%d] interface settings : %d \n",
            j, interface->num_altsetting);

        for (int k = 0; k < interface->num_altsetting; ++k) {
            const libusb_interface_descriptor* interface_descriptor =
                    &interface->altsetting[k];
            LOG_DEBUG("\t\tnumber of endpoint : %d \n",
                    interface_descriptor->bNumEndpoints);

            for (int l = 0; l < interface_descriptor->bNumEndpoints; ++l) {
                const libusb_endpoint_descriptor* endpoint_descriptor =
                        &interface_descriptor->endpoint[l];

                if (interface_descriptor->bInterfaceClass == AOAPConst::AOA_CLASS &&
                        interface_descriptor->bInterfaceSubClass == AOAPConst::AOA_SUBCLASS &&
                        interface_descriptor->bInterfaceProtocol == AOAPConst::AOA_PROTOCOL) {
                    ret = LIBUSB_SUCCESS;
                    device->setInterface(j);
                    if ( (LIBUSB_ENDPOINT_IN & endpoint_descriptor->bEndpointAddress) != 0 ) {
                      device->setReadEndpoint(endpoint_descriptor->bEndpointAddress);
                      LOG_DEBUG("\t\t\tread-endpoint for AOAP : %d \n",
                          endpoint_descriptor->bEndpointAddress);
                    } else {
                      device->setWriteEndpoint(endpoint_descriptor->bEndpointAddress);
                      LOG_DEBUG("\t\t\twrite-endpoint for AOAP : %d \n",
                          endpoint_descriptor->bEndpointAddress);
                    }
                }
            }
        }
    }

    LOG_DEBUG("\n");
    libusb_free_config_descriptor(config_descriptor);
    return ret;
}

void UsbAOAConnection::__turn_off_communication__(UsbDevice *device) {
  LOG_DEBUG("m_interface : %d \n", device->getInterface());
  RETURN_IF_TRUE(device == nullptr || device->getInterface() == 0xff);
  libusb_release_interface(device->getDeviceHandle(), device->getInterface());
  libusb_close(device->getDeviceHandle());
  device->setInterface(0xff);
}

bool UsbAOAConnection::__turn_on_communication__(UsbDevice *device) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_TRUE(device == nullptr || device->getInterface() == 0xff);
  RETURN_FALSE_IF_FALSE(
      libusb_set_configuration(device->getDeviceHandle(), device->getConfigure()) == LIBUSB_SUCCESS);
  RETURN_FALSE_IF_FALSE(
      libusb_claim_interface(device->getDeviceHandle(), device->getInterface()) == LIBUSB_SUCCESS);
  return true;
}

bool UsbAOAConnection::__is_google_accessory__(UsbDevice *device) {
  libusb_device_descriptor desc = {0};
  if ( LIBUSB_SUCCESS == libusb_get_device_descriptor(device->getDevice(), &desc) ) {
    if ( desc.idProduct != AOAPConst::AOAP_PRODUCT_1 && desc.idProduct != AOAPConst::AOAP_PRODUCT_2 &&
      desc.idProduct != AOAPConst::AOAP_PRODUCT_3 && desc.idProduct != AOAPConst::AOAP_PRODUCT_4 &&
      desc.idProduct != AOAPConst::AOAP_PRODUCT_5 && desc.idProduct != AOAPConst::AOAP_PRODUCT_6 ) {
      LOG_WARNING("This is not google accessory then we will ask whether it can suuport \n");
      return false;
    }
  }
  return true;
}

bool UsbAOAConnection::__is_support_aoap_mode__(UsbDevice *device) {
  uint8_t buffer[2];
  if ( 0 > libusb_control_transfer(device->getDeviceHandle(), AOAPConst::HOST_TO_DEVICE_TYPE,
          AOAPConst::ACCESSORY_GET_PROTOCOL, 0, 0, (uint8_t*)buffer, 2, 0) ) {
    LOG_WARNING("ACCESSORY_GET_PROTOCOL=[%u][%u] \n", buffer[0], buffer[1]);
    LOG_WARNING("This device can't support accessory mode \n\n");
    return false;
  }
  LOG_DEBUG("This device can support accessory mode \n\n");
  return true;
}

void UsbAOAConnection::__request_turn_on_aoap_mode__(UsbDevice *device) {
  LOG_DEBUG("\n");
  auto sendString = [](libusb_device_handle* handle, const char* str, int index)->int
  {
      return libusb_control_transfer(handle, AOAPConst::DEVICE_TO_HOST_TYPE,
              AOAPConst::ACCESSORY_SEND_STRING, 0, index, (uint8_t*)str, strlen(str) + 1, 0);
  };
  LOG_INFO("Accessory Manufacturer Name : %s \n", m_accessory_manufacturer_name.c_str());
  LOG_INFO("Accessory Model Name : %s \n", m_accessory_model_name.c_str());
  LOG_INFO("Accessory Description: : %s \n", m_accessory_description.c_str());
  LOG_INFO("Accessory Version : %s \n", m_accessory_version.c_str());
  LOG_INFO("Accessory URI : %s \n", m_accessory_uri.c_str());
  LOG_INFO("Accessory Serial Number : %s \n", m_accessory_serial_number.c_str());

  sendString(device->getDeviceHandle(), m_accessory_manufacturer_name.c_str(), AOAPConst::ACCESSORY_STRING_MANUFACTURER);
  sendString(device->getDeviceHandle(), m_accessory_model_name.c_str(), AOAPConst::ACCESSORY_STRING_MODEL);
  sendString(device->getDeviceHandle(), m_accessory_description.c_str(), AOAPConst::ACCESSORY_STRING_DESCRIPTION);
  sendString(device->getDeviceHandle(), m_accessory_version.c_str(), AOAPConst::ACCESSORY_STRING_VERSION);
  sendString(device->getDeviceHandle(), m_accessory_uri.c_str(), AOAPConst::ACCESSORY_STRING_URI);
  sendString(device->getDeviceHandle(), m_accessory_serial_number.c_str(), AOAPConst::ACCESSORY_STRING_SERIAL);

  libusb_control_transfer(device->getDeviceHandle(), AOAPConst::DEVICE_TO_HOST_TYPE,
      AOAPConst::ACCESSORY_START, 0, 0, nullptr, 0, 0);
}