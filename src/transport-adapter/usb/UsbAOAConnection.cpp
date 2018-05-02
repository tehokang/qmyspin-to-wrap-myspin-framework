#include "UsbAOAConnection.h"
#include "UsbDevice.h"
#include "Macro.h"
#include <unistd.h>

UsbAOAConnection::UsbAOAConnection(ConnectionListener &listener)
  : Connection(listener)
  , m_interface(-1)
  , m_read_endpoint(-1)
  , m_write_endpoint(-1) {

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
  int ret = libusb_bulk_transfer(usb->getDeviceHandle(), m_write_endpoint,
          (uint8_t*) buffer, size, &sizeout, 1000);

  if ( ret != LIBUSB_SUCCESS && ret != LIBUSB_ERROR_TIMEOUT ) {
      // LOG_WARNING("Error when writing to usb: %s\n", libusb_error_name(ret));
      return false;
  } else if (ret == LIBUSB_ERROR_TIMEOUT) {
      // LOG_ERROR("Timeout on usb write\n");
      return false;
  }
  return true;
}

unsigned int UsbAOAConnection::receive(Device &device, unsigned char *buffer, unsigned int size) {
  UsbDevice *usb = static_cast<UsbDevice*>(&device);
  if ( !usb || !usb->getDeviceHandle() ) return 0;

  int sizeout = 0;
  int ret = libusb_bulk_transfer(usb->getDeviceHandle(), m_read_endpoint,
      buffer, size, &sizeout, 1000);

  if ( ret != LIBUSB_SUCCESS && ret != LIBUSB_ERROR_TIMEOUT )
  {
      // LOG_ERROR("Error when reading from usb: %s\n", libusb_error_name(ret));
  }

  __logging_buffer__(buffer, sizeout);

  return sizeout;
}

bool UsbAOAConnection::__connect__(UsbDevice *device) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_NULL(device);

  libusb_device *d = device->getDevice();
  libusb_device_handle *d_h = device->getDeviceHandle();

  if ( __is_google_accessory__(d) == true ) {
    RETURN_FALSE_IF_FALSE(__parse_interfaces__(d) == LIBUSB_SUCCESS);
    RETURN_FALSE_IF_FALSE(__turn_on_communication__(d, d_h));
    m_listener.onConnect(device);
  } else {
    if ( __is_support_aoap_mode__(d, d_h) == true ) {
      __request_turn_on_aoap_mode__(d, d_h);
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
    __turn_off_communication__(device->getDevice(), device->getDeviceHandle());
    libusb_close(device->getDeviceHandle());
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

int UsbAOAConnection::__parse_interfaces__(libusb_device* dev) {
    int ret = LIBUSB_ERROR_OTHER;
    libusb_config_descriptor* config_descriptor;
    libusb_get_active_config_descriptor(dev, &config_descriptor);

    LOG_DEBUG("number of interfaces : %d \n", config_descriptor->bNumInterfaces);

    for (int j = 0; j < config_descriptor->bNumInterfaces; ++j)
    {
        const libusb_interface* interface = &config_descriptor->interface[j];
        LOG_DEBUG("\tnumber of [%d] interface settings : %d \n",
                j, interface->num_altsetting);

        for (int k = 0; k < interface->num_altsetting; ++k)
        {
            const libusb_interface_descriptor* interface_descriptor =
                    &interface->altsetting[k];
            LOG_DEBUG("\t\tnumber of endpoint : %d \n",
                    interface_descriptor->bNumEndpoints);

            for (int l = 0; l < interface_descriptor->bNumEndpoints; ++l)
            {
                const libusb_endpoint_descriptor* endpoint_descriptor =
                        &interface_descriptor->endpoint[l];

                if (interface_descriptor->bInterfaceClass == AOAPConst::AOA_CLASS &&
                        interface_descriptor->bInterfaceSubClass == AOAPConst::AOA_SUBCLASS &&
                        interface_descriptor->bInterfaceProtocol == AOAPConst::AOA_PROTOCOL)
                {
                    ret = LIBUSB_SUCCESS;
                    m_interface = j;
                    if ( (LIBUSB_ENDPOINT_IN & endpoint_descriptor->bEndpointAddress) != 0 )
                    {
                        m_read_endpoint = endpoint_descriptor->bEndpointAddress;
                        LOG_DEBUG("\t\t\tread-endpoint for AOAP : %d \n",
                                endpoint_descriptor->bEndpointAddress);
                    }
                    else
                    {
                        m_write_endpoint = endpoint_descriptor->bEndpointAddress;
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

void UsbAOAConnection::__turn_off_communication__(libusb_device *d, libusb_device_handle *d_h) {
  LOG_DEBUG("\n");
  RETURN_IF_TRUE(m_interface == -1);
  libusb_release_interface(d_h, m_interface);
}

bool UsbAOAConnection::__turn_on_communication__(libusb_device *d, libusb_device_handle *d_h) {
  LOG_DEBUG("\n");
  RETURN_FALSE_IF_TRUE(m_interface == -1);
  RETURN_FALSE_IF_FALSE(libusb_set_configuration(d_h, 1) == LIBUSB_SUCCESS);
  RETURN_FALSE_IF_FALSE(libusb_claim_interface(d_h, m_interface) == LIBUSB_SUCCESS);
  return true;
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

void UsbAOAConnection::__request_turn_on_aoap_mode__(
  libusb_device* d, libusb_device_handle *d_h) {

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

  sendString(d_h, m_accessory_manufacturer_name.c_str(), AOAPConst::ACCESSORY_STRING_MANUFACTURER);
  sendString(d_h, m_accessory_model_name.c_str(), AOAPConst::ACCESSORY_STRING_MODEL);
  sendString(d_h, m_accessory_description.c_str(), AOAPConst::ACCESSORY_STRING_DESCRIPTION);
  sendString(d_h, m_accessory_version.c_str(), AOAPConst::ACCESSORY_STRING_VERSION);
  sendString(d_h, m_accessory_uri.c_str(), AOAPConst::ACCESSORY_STRING_URI);
  sendString(d_h, m_accessory_serial_number.c_str(), AOAPConst::ACCESSORY_STRING_SERIAL);

  libusb_control_transfer(d_h, AOAPConst::DEVICE_TO_HOST_TYPE,
      AOAPConst::ACCESSORY_START, 0, 0, nullptr, 0, 0);
}