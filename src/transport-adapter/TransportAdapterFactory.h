#ifndef __TRANSPORT_ADAPTER_FACTORY_H__
#define __TRANSPORT_ADAPTER_FACTORY_H__

class TransportAdapter;
class TransportAdapterListener;

class TransportAdapterFactory {
public:
  typedef enum {
    USB_AOA,
    USB_IAP,
    BLUETOOTH,
    TCP,
  } TransportAdapaterType;

  static TransportAdapter& createTransportAdapter(
      TransportAdapaterType type, TransportAdapterListener &listener);
  static void destroyTransportAdapter(TransportAdapaterType type);

protected:
  static TransportAdapter *m_usb_aoa_transport_adapter;
  static TransportAdapter *m_usb_iap_transport_adapter;
  static TransportAdapter *m_bluetooth_transport_adapater;
  static TransportAdapter *m_tcp_transport_adapter;
  static TransportAdapter *m_unknown_transport_adapter;

private:
  TransportAdapterFactory();
  ~TransportAdapterFactory();
};

#endif