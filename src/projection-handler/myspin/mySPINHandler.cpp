#include "mySPINHandler.h"
#include "Macro.h"

MySPINHandler::MySPINHandler()
  : ProjectionHandler() {
  m_accessory_manufacturer_name = "BSOT";
  m_accessory_model_name = "mySPIN";
  m_accessory_description = "mySPIN";
  m_accessory_version = "0.1";
  m_accessory_uri = "com.bosch.myspin.launcherapp.cn";
  m_accessory_serial_number = "0000000012345678";
}

MySPINHandler::~MySPINHandler() {
  mySpin_Shutdown();
}

bool MySPINHandler::init() {
  mySpin_Init();
  LOG_DEBUG("Version of mySPIN : %s \n", mySpin_GetVersion());
  LOG_DEBUG("System Identification of mySPIN : %s \n", mySpin_GetSystemIdentification());

  return true;
}

bool MySPINHandler::start(void *connected_device) {
  LOG_DEBUG("\n");

  ProjectionHandler::start(connected_device);

  m_myspin_handle = mySpin_CreateInstance(connected_device, "MySPINHandler of Humax");

  mySpin_SetTraceClass(m_myspin_handle,
      (eTraceClass) (eTRACECLASS_ERROR | eTRACECLASS_WARNING |
      eTRACECLASS_INFORMATION  | eTRACECLASS_VERBOSE));

  mySpin_SetTraceOutput(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_trace_output__);

  mySpin_SetCallbackContext(m_myspin_handle, (void*)this);
  mySpin_SetSenderLink(m_myspin_handle, MySPINHandler::CoreCallBack::__on_send__);
  mySpin_SetReceiverLink(m_myspin_handle, MySPINHandler::CoreCallBack::__on_receive__);
  mySpin_SetProtocolCallback(m_myspin_handle, MySPINHandler::CoreCallBack::__on_protocol__);
  mySpin_SetFrameUpdateStartCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_frame_update_start__);
  mySpin_SetFrameUpdateCallback(m_myspin_handle, MySPINHandler::CoreCallBack::__on_frame_update__);
  mySpin_SetFrameUpdateEndCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_frame_update_end__);
  mySpin_SetErrorCallback(m_myspin_handle, MySPINHandler::CoreCallBack::__on_error__);
  mySpin_SetAppTransitionStatusCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_app_transition_status__);
  mySpin_SetAppInactiveCallback(m_myspin_handle, MySPINHandler::CoreCallBack::__on_app_inactive__);
  mySpin_SetCustomDataStringCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_custom_data_string__);
  mySpin_SetCustomDataIntCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_custom_data_int__);
  mySpin_SetVehicleDataRequestCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_vehicle_data_request__);

  mySpin_SetFrameOutputType(m_myspin_handle, eFLAG_FALSE);
  mySpin_SetPixelFormat(m_myspin_handle, m_pixel_format, 4, ePIXELENDIANESS_BigEndian);
  mySpin_SetFrameSize(m_myspin_handle, m_width, m_height,
      (((m_width* 10000)/m_dpi)/254), (((m_height*10000)/m_dpi)/254));

  ClientCustomDataKeyCode keys[4];
  keys[0] = eCLIENTCUSTOMDATAKEYCODE_Ok;
  keys[1] = eCLIENTCUSTOMDATAKEYCODE_Back;
  keys[2] = eCLIENTCUSTOMDATAKEYCODE_KnobTickCW;
  keys[3] = eCLIENTCUSTOMDATAKEYCODE_KnobTickCCW;
  mySpin_SetCustomKeysSupported(m_myspin_handle, 4, keys);
  mySpin_SetClientCapabilities(m_myspin_handle, eCLIENTCAPABILITIES_RequiresFocusControl, eFLAG_TRUE);
  // set language before starting communication
  mySpin_SetISO639LanguageCode(m_myspin_handle, (UInt8*)"epo");

  // start the receiver thread
  mySpin_SetInitialisationTimeout(m_myspin_handle, 20);
  Int32 retErr;
  if ( mySpin_StartMainThreadEx(m_myspin_handle, &retErr) == eFLAG_FALSE ) {
    LOG_ERROR("ADAPTER: mySpin_StartMainThread() returned error code %d.\n", retErr);
    return false;
  }
  return true;
}

void MySPINHandler::stop() {

  if ( m_myspin_handle != nullptr ) {
    mySpin_SetProtocolCallback(m_myspin_handle, nullptr);
    mySpin_SetFrameUpdateStartCallback(m_myspin_handle, nullptr);
    mySpin_SetFrameUpdateCallback(m_myspin_handle, nullptr);
    mySpin_SetFrameUpdateEndCallback(m_myspin_handle, nullptr);
    mySpin_SetErrorCallback(m_myspin_handle, nullptr);
    mySpin_SetAppTransitionStatusCallback(m_myspin_handle, nullptr);
    mySpin_SetAppInactiveCallback(m_myspin_handle, nullptr);
    mySpin_SetCustomDataStringCallback(m_myspin_handle, nullptr);
    mySpin_SetCustomDataIntCallback(m_myspin_handle, nullptr);
    mySpin_SetSenderLink(m_myspin_handle, nullptr);
    mySpin_SetReceiverLink(m_myspin_handle, nullptr);
    mySpin_SetTraceOutput(m_myspin_handle, nullptr);
    mySpin_DeleteInstance(m_myspin_handle);
    m_myspin_handle = nullptr;
  }
}

void MySPINHandler::sendHomeKey(PRESS_TYPE press) {
  LOG_DEBUG("\n");
  RETURN_IF_NULL(m_myspin_handle);
  mySpin_SoftkeyEvent(m_myspin_handle,
      eSOFTKEY_Home, press == PRESS_TYPE::PRESS ?
      eSOFTKEYEVENTTYPE_Press : eSOFTKEYEVENTTYPE_Release);
}

void MySPINHandler::sendBackKey(PRESS_TYPE press) {
  LOG_DEBUG("\n");
  RETURN_IF_NULL(m_myspin_handle);
  mySpin_SoftkeyEvent(m_myspin_handle,
      eSOFTKEY_Back, press == PRESS_TYPE::PRESS ?
      eSOFTKEYEVENTTYPE_Press : eSOFTKEYEVENTTYPE_Release);

}

void MySPINHandler::sendMenuKey(PRESS_TYPE press) {
  LOG_DEBUG("\n");
  RETURN_IF_NULL(m_myspin_handle);
  mySpin_SoftkeyEvent(m_myspin_handle,
      eSOFTKEY_Menu, press == PRESS_TYPE::PRESS ?
      eSOFTKEYEVENTTYPE_Press : eSOFTKEYEVENTTYPE_Release);
}

void MySPINHandler::sendSearchKey(PRESS_TYPE press) {
  LOG_DEBUG("\n");
  RETURN_IF_NULL(m_myspin_handle);
  mySpin_SoftkeyEvent(m_myspin_handle,
      eSOFTKEY_Search, press == PRESS_TYPE::PRESS ?
      eSOFTKEYEVENTTYPE_Press : eSOFTKEYEVENTTYPE_Release);
}

void MySPINHandler::sendCustomKey(PRESS_TYPE press, int key) {
  /**
   * @note NOTHING TO DO
   */
}

void MySPINHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  LOG_DEBUG("\n");
}

void MySPINHandler::__request_to_notify_ready__() {
  RETURN_IF_NULL(m_listener);
  m_listener->onReady();
}

bool MySPINHandler::__request_to_send__(UInt8 *buffer, size_t size, void* connection) {
  RETURN_FALSE_IF_FALSE(m_listener);
  return m_listener->onReqSend(buffer, size, connection);
}

unsigned int MySPINHandler::__request_to_receive__(UInt8 *buffer, size_t size, void* connection) {
  RETURN_FALSE_IF_FALSE(m_listener);
  return m_listener->onReqReceive(buffer, size, connection);
}

void MySPINHandler::__request_to_notify_frameupdate_started__(UInt8 numOfRectangles) {
  m_listener->onFrameUpdateStarted(numOfRectangles);
}

void MySPINHandler::__request_to_notify_frameupdating__(UInt8 currentNumber, UInt16 x0, UInt16 y0,
    UInt16 width, UInt16 height, UInt8* buffer, UInt32 bufferSize) {
  RETURN_IF_FALSE(m_listener);
  m_listener->onFrameUpdating(currentNumber, x0, y0, width, height, buffer, bufferSize);
}

void MySPINHandler::__request_to_notify_frameupdate_ended__() {
  RETURN_IF_FALSE(m_listener);
  m_listener->onFrameUpdateEnded();
#if 1
  mySpin_FramebufferUpdateRequest(__get_myspin_handle__(),
      (UInt16)(0 & 0xFFFF), (UInt16)(0 & 0xFFFF),
      (UInt16)(getWidth() & 0xFFFF), (UInt16)(getHeight() & 0xFFFF), eFLAG_TRUE);
#endif
}

void MySPINHandler::CoreCallBack::__on_trace_output__(
    void* context, eTraceClass traceClass, char* traceString) {
  LOG_DEBUG("mySPIN-CORE : %s %s\n", mySpin_getTraceClassPrefix(traceClass), traceString );
}

void* MySPINHandler::CoreCallBack::__on_send__(
    void* context, UInt8* buffer, size_t bufferSize, void* connection) {
  auto *handler = static_cast<MySPINHandler*>(context);
  RETURN_NULL_IF_NULL(handler);
  handler->__request_to_send__(buffer, bufferSize, connection);

  return nullptr;
}

unsigned int MySPINHandler::CoreCallBack::__on_receive__(
  void* context, UInt8* buffer, size_t bufferSize, void* connection) {
  auto *handler = static_cast<MySPINHandler*>(context);
  if ( handler ) {
    return handler->__request_to_receive__(buffer, bufferSize, connection);
  }
  return 0;
}

void MySPINHandler::CoreCallBack::__on_protocol__(void* context, eProtocolState newState) {
  LOG_DEBUG("\n");
  auto *handler = static_cast<MySPINHandler*>(context);
  RETURN_IF_NULL(handler);

	switch(newState) {
    case ePROTOCOL_STATE_RUN:
      handler->__request_to_notify_ready__();
      mySpin_FramebufferUpdateRequest(handler->__get_myspin_handle__(),
          (UInt16)(0 & 0xFFFF), (UInt16)(0 & 0xFFFF),
          (UInt16)(handler->getWidth() & 0xFFFF), (UInt16)(handler->getHeight() & 0xFFFF),
          eFLAG_TRUE);
      break;
    case ePROTOCOL_STATE_STOP:
      break;
    case ePROTOCOL_STATE_HANDSHAKE:
      break;
	  case ePROTOCOL_STATE_INIT_CLIENT:
      break;
	  case ePROTOCOL_STATE_INIT_SERVER:
      break;
	  case ePROTOCOL_STATE_INIT_DONE:
      break;
    default:
      break;
  }
}

void MySPINHandler::CoreCallBack::__on_frame_update_start__(void* context, UInt8 numOfRectangles) {
  LOG_DEBUG("\n");
  auto *handler = static_cast<MySPINHandler*>(context);
  RETURN_IF_NULL(handler);
  handler->__request_to_notify_frameupdate_started__(numOfRectangles);
}

void MySPINHandler::CoreCallBack::__on_frame_update__(
    void* context, UInt8 currentNumber, UInt16 x0, UInt16 y0,
    UInt16 width, UInt16 height, UInt8* buffer, UInt32 bufferSize) {
  LOG_DEBUG("\n");
  auto *handler = static_cast<MySPINHandler*>(context);
  RETURN_IF_NULL(handler);
  /**
   * @note Moment when it can dump
   */

  handler->__request_to_notify_frameupdating__(
    currentNumber, x0, y0, width, height, buffer, bufferSize);
}

void MySPINHandler::CoreCallBack::__on_frame_update_end__(void* context) {
	LOG_DEBUG("\n");
  auto *handler = static_cast<MySPINHandler*>(context);
  RETURN_IF_NULL(handler);
  handler->__request_to_notify_frameupdate_ended__();
}

void MySPINHandler::CoreCallBack::__on_error__(void* context, eErrorCode error) {
	LOG_ERROR("error callback with code %d\n", error);
}

void MySPINHandler::CoreCallBack::__on_app_transition_status__(void* context, Flag transitionStarts) {
	LOG_DEBUG("OnAppTransitionStatus with value %s\n", transitionStarts == eFLAG_TRUE ? "TRUE" : "FALSE");
}

void MySPINHandler::CoreCallBack::__on_app_inactive__(void* context, Flag appInactive) {
	LOG_DEBUG("OnAppInactive with value %s\n", appInactive == eFLAG_TRUE ? "TRUE" : "FALSE");
}

void MySPINHandler::CoreCallBack::__on_custom_data_string__(
    void* context, ServerCustomDataStringType type, StringEncoding encoding, char* data) {
	LOG_DEBUG("OnCustomMessage with type %d and string '%s'\n", type, data);
}

void MySPINHandler::CoreCallBack::__on_custom_data_int__(
    void* context, ServerCustomDataIntType type, UInt16 length, UInt8* data) {
	LOG_DEBUG("OnCustomDataInt with type %d and length %d\n", type, length);
}

void MySPINHandler::CoreCallBack::__on_vehicle_data_request__(
    void* context, Flag request, UInt8 length, UInt32* keyList) {
  LOG_DEBUG("request : %d, length : %d\n");
  for ( unsigned int i = 0; i < length; i++ ) {
    LOG_DEBUG("key[%d] : %x \n", i, keyList[i]);
  }
}