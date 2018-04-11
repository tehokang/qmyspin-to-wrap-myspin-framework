#ifndef __ABALTA_HANDLER_H__
#define __ABALTA_HANDLER_H__

#include "../ProjectionHandler.h"

class AbaltaHandler : public ProjectionHandler
{
public:
  AbaltaHandler();
  virtual ~AbaltaHandler();

  virtual bool init() override;
  virtual bool start() override;
  virtual void stop() override;
  virtual bool sendKey(int key, int press) override;
  virtual bool sendTouch(unsigned int x, unsigned int y, int finger, int action) override;

};

#endif