#include "TransportAdapterFactory.h"
#include "TransportAdapter.h"
#include "usb/UsbAOATransportAdapter.h"
#include "usb/UsbIAPTransportAdapter.h"
#include "bluetooth/BluetoothTransportAdapter.h"
#include "tcp/TcpTransportAdapter.h"
#include "Macro.h"

TransportAdapter *TransportAdapterFactory::m_usb_aoa_transport_adapter = nullptr;
TransportAdapter *TransportAdapterFactory::m_usb_iap_transport_adapter = nullptr;
TransportAdapter *TransportAdapterFactory::m_bluetooth_transport_adapater = nullptr;
TransportAdapter *TransportAdapterFactory::m_tcp_transport_adapter = nullptr;
TransportAdapter *TransportAdapterFactory::m_unknown_transport_adapter = nullptr;

TransportAdapter& TransportAdapterFactory::createTransportAdapter(
    TransportAdapterFactory::TransportAdapaterType type, TransportAdapterListener &listener) {

  switch ( type ) {
    case TransportAdapterFactory::TransportAdapaterType::USB_AOA:
      if ( m_usb_aoa_transport_adapter == nullptr ) {
        m_usb_aoa_transport_adapter = new UsbAOATransportAdapter(listener);
      }
      return *m_usb_aoa_transport_adapter;
    case TransportAdapterFactory::TransportAdapaterType::USB_IAP:
      if ( m_usb_iap_transport_adapter == nullptr ) {
        m_usb_iap_transport_adapter = new UsbIAPTransportAdapter(listener);
      }
      return *m_usb_iap_transport_adapter;
    case TransportAdapterFactory::TransportAdapaterType::BLUETOOTH:
      if ( m_bluetooth_transport_adapater == nullptr ) {
        m_bluetooth_transport_adapater = new BluetoothTransportAdapter(listener);
      }
      return *m_bluetooth_transport_adapater;
    case TransportAdapterFactory::TransportAdapaterType::TCP:
      if ( m_tcp_transport_adapter == nullptr ) {
        m_tcp_transport_adapter = new TcpTransportAdapter(listener);
      }
      return *m_tcp_transport_adapter;
    default:
      if ( m_unknown_transport_adapter == nullptr ) {
        m_unknown_transport_adapter = new TransportAdapter(listener);
      }
      break;
  }
  return *m_unknown_transport_adapter;
}

void TransportAdapterFactory::destroyTransportAdapter(
    TransportAdapterFactory::TransportAdapaterType type) {

  switch ( type ) {
    case TransportAdapterFactory::TransportAdapaterType::USB_AOA:
      SAFE_DELETE(m_usb_aoa_transport_adapter);
      break;
    case TransportAdapterFactory::TransportAdapaterType::USB_IAP:
      SAFE_DELETE(m_usb_iap_transport_adapter);
      break;
    case TransportAdapterFactory::TransportAdapaterType::BLUETOOTH:
      SAFE_DELETE(m_bluetooth_transport_adapater);
      break;
    case TransportAdapterFactory::TransportAdapaterType::TCP:
      SAFE_DELETE(m_tcp_transport_adapter);
      break;
    default:
      SAFE_DELETE(m_unknown_transport_adapter);
      break;
  }
}


TransportAdapterFactory::TransportAdapterFactory() {
  /**
   * @note NOTHING TO DO
   */
}

TransportAdapterFactory::~TransportAdapterFactory() {
  /**
   * @note NOTHING TO DO
   */
}
