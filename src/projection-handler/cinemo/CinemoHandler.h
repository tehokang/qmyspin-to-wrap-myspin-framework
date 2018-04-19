#ifndef __CINEMO_HANDLER_H__
#define __CINEMO_HANDLER_H__

#include "../ProjectionHandler.h"

class CinemoHandler : public ProjectionHandler
{
public:
  CinemoHandler();
  virtual ~CinemoHandler();

  virtual bool init() override;
  virtual bool start(void *connected_device) override;
  virtual void stop() override;

};

#endif