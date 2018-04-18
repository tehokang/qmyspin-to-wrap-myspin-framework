#ifndef __MYSPIN_HANDLER_H__
#define __MYSPIN_HANDLER_H__

#define MYSPIN_TARGET_FREERTOS

#include "../ProjectionHandler.h"
#include <stdio.h>
#include <mySPIN-Core.h>

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

protected:
  void *m_myspin_handle;

  static void __on_trace_output__(void* context, eTraceClass traceClass, char* traceString);
  static void* __on_send__(void* context, UInt8* buffer, size_t bufferSize, void* connection);
  static size_t __on_receive__(void* context, UInt8* buffer, size_t bufferSize, void* connection);
  static void __on_protocol__(void* context, eProtocolState newState);

  static void __on_frame_update_start__(void* context, UInt8 numOfRectangles);
  static void __on_frame_update__(
      void* context, UInt8 currentNumber, UInt16 x0, UInt16 y0,
      UInt16 width, UInt16 height, UInt8* buffer, UInt32 bufferSize);
  static void __on_frame_update_end__(void* context);
  static void __on_error__(void* context, eErrorCode error);
  static void __on_app_transition_status__(void* context, Flag transitionStarts);
  static void __on_app_inactive__(void* context, Flag appInactive);
  static void __on_custom_data_string__(
      void* context, ServerCustomDataStringType type, StringEncoding encoding, char* data);
  static void __on_custom_data_int__(
      void* context, ServerCustomDataIntType type, UInt16 length, UInt8* data);
  static void __on_vehicle_data_request__(
      void* context, Flag request, UInt8 length, UInt32* keyList);


};

#endif