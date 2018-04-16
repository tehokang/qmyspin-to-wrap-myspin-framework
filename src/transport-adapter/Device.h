#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <string>
#include <sys/time.h>
using namespace std;

class Device {
public:
  Device(string product_name, string manufacturer_name)
    : m_product_name(product_name)
    , m_manufacturer_name(manufacturer_name) {

    m_hash_key = generateKey();
  }

  virtual ~Device() {

  }

  int getKey() { return m_hash_key; };
  string getProductName() { return m_product_name; }
  string getManufacturerName() { return m_manufacturer_name; }

private:
  unsigned int generateKey() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return hash<long int>()(ms);
  }

  unsigned int m_hash_key;
  string m_product_name;
  string m_manufacturer_name;
};


#endif