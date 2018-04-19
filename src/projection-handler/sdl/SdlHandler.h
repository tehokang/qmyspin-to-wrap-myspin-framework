#ifndef __SDL_HANDLER_H__
#define __SDL_HANDLER_H__

#include "../ProjectionHandler.h"

class SdlHandler : public ProjectionHandler
{
public:
  SdlHandler();
  virtual ~SdlHandler();

  virtual bool init() override;
  virtual bool start(void *connected_device) override;
  virtual void stop() override;

};

#endif