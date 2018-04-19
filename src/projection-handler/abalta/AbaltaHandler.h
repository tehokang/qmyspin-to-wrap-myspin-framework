#ifndef __ABALTA_HANDLER_H__
#define __ABALTA_HANDLER_H__

#include "../ProjectionHandler.h"

class AbaltaHandler : public ProjectionHandler
{
public:
  AbaltaHandler();
  virtual ~AbaltaHandler();

  virtual bool init() override;
  virtual bool start(void *connected_device) override;
  virtual void stop() override;

};

#endif