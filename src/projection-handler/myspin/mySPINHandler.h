#ifndef __MYSPIN_HANDLER_H__
#define __MYSPIN_HANDLER_H__

#include "../ProjectionHandler.h"

class MySPINHandler : public ProjectionHandler
{
public:
  MySPINHandler();
  virtual ~MySPINHandler();

  virtual bool init() override;
  virtual bool start() override;
  virtual void stop() override;
  virtual bool sendKey(int key, int press) override;
  virtual bool sendTouch(unsigned int x, unsigned int y, int finger, int action) override;

};

#endif