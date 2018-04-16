#ifndef __PROJECTION_COORDINATOR_H__
#define __PROJECTION_COORDINATOR_H__

#include "../../projection-handler/ProjectionHandler.h"
#include "../../transport-adapter/TransportAdapter.h"

class ProjectionCoordinatorListener {
public:
  virtual void onScan(list<Device*> devices) = 0;
  virtual void onSelect(Device *device) = 0;
  virtual void onUnselect(Device *device) = 0;
  virtual void onError(int error) = 0;
  virtual void onReady() = 0;
  virtual void onStop() = 0;
  virtual void onFrameUpdate() = 0;
};

class ProjectionCoordinator : public ProjectionListener, public TransportAdapterListener {
public:
  ProjectionCoordinator();
  virtual ~ProjectionCoordinator();

  virtual bool init();
  virtual bool start();
  virtual void stop();
  virtual bool scan();
  virtual bool select(Device *device);
  virtual bool unselect(Device *device);
  virtual bool sendKey(int key, int press);
  virtual bool sendTouch(int x, int y, int finger, int action);
  virtual bool sendVehicle(string message);
  virtual void setEventListener(ProjectionCoordinatorListener *listener);

  virtual bool onReqSend(unsigned char *buffer, unsigned int size) override;
  virtual bool onReqReceive(unsigned char *buffer, unsigned int size) override;
  virtual void onFrameUpdated(unsigned char *buffer, unsigned int size) override;

  virtual void onScan(list<Device*> device) override;
  virtual void onConnect(Device* device) override;
  virtual void onDisconnect(Device* device) override;

  virtual void onError(int error) override;

protected:
  ProjectionCoordinatorListener *m_listener;
};


#endif