#ifndef __QMYSPIN_IMPL_H__
#define __QMYSPIN_IMPL_H__

#include <list>
using namespace std;

#include "../include/QmySPIN.h"
#include "PPCoordinator.h"

class QmySPINImpl : public QmySPIN, public ProjectionCoordinatorListener {
public:
  QmySPINImpl();
  virtual ~QmySPINImpl();

  virtual bool init() override;
  virtual bool start() override;
  virtual void stop() override;
  virtual bool scan() override;
  virtual bool select(Device *device) override;
  virtual bool unselect(Device *device) override;

  virtual void setFrameBuffer(
      PIXEL_FORMAT format, unsigned char *frame_buffer, unsigned int width, unsigned height) override;

  virtual bool sendKey(int key, int press) override;
  virtual bool sendTouch(int x, int y, int finger, int action) override;
  virtual bool sendVehicle(string message) override;

  virtual void onScan(list<Device*> devices) override;
  virtual void onSelect(Device *device) override;
  virtual void onUnselect(Device *device) override;
  virtual void onError(int error) override;
  virtual void onReady() override;
  virtual void onStop() override;
  virtual void onFrameUpdate() override;

protected:
  ProjectionCoordinator *m_pp_coordinator;
};

#endif