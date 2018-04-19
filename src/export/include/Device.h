#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <string>
#include <sys/time.h>
using namespace std;

class Device {
public:
  Device(string product_name, string manufacturer_name, string serial_number)
    : m_product_name(product_name)
    , m_manufacturer_name(manufacturer_name)
    , m_serial_number(serial_number) {

    m_hash_key = __generateKey__();
  }

  virtual ~Device() {
    m_product_name = "";
    m_manufacturer_name = "";
    m_serial_number = "";
  }

  int getKey() { return m_hash_key; };
  string getProductName() { return m_product_name; }
  string getManufacturerName() { return m_manufacturer_name; }
  string getSerialNumber() { return m_serial_number; }

private:
  unsigned int __generateKey__() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int us = tp.tv_sec * 1000 + tp.tv_usec;
    return hash<long int>()(us);
  }

  unsigned int m_hash_key;
  string m_product_name;
  string m_manufacturer_name;
  string m_serial_number;
};


#endif