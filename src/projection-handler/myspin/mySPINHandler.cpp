#include "mySPINHandler.h"
#include "Macro.h"

MySPINHandler::MySPINHandler()
  : ProjectionHandler()
  , m_myspin_handle(nullptr) {
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
  mySpin_SetPhonecallStatusCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_phone_call_status_changed__);
  mySpin_SetCustomDataStringCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_custom_data_string__);
  mySpin_SetCustomDataIntCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_custom_data_int__);
  mySpin_SetLauncherStateCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_launcher_state_changed__);
  mySpin_SetSupportedCustomData(m_myspin_handle, 0, nullptr);
  mySpin_VoiceSupportInfo(m_myspin_handle,
      eVOICESUPPORT_NotSupported, eVOICESUPPORTCONSTRAINT_NoConstraint);
  mySpin_EnablePingWatchdog(m_myspin_handle, eFLAG_TRUE, 1);
  mySpin_SetWaitForJoinTimeout(m_myspin_handle, 5);

#if 0
  mySpin_SetVehicleDataRequestCallback(m_myspin_handle,
      MySPINHandler::CoreCallBack::__on_vehicle_data_request__);
#endif

  mySpin_SetFrameOutputType(m_myspin_handle, eFLAG_FALSE);
  mySpin_SetPixelFormat(m_myspin_handle, m_pixel_format, m_pixel_bytes, ePIXELENDIANESS_LittleEndian);
  mySpin_SetFrameSize(m_myspin_handle, m_width, m_height,
      (((m_width* 10000)/m_dpi)/254), (((m_height*10000)/m_dpi)/254));

  ClientCustomDataKeyCode keys[4];
  keys[0] = eCLIENTCUSTOMDATAKEYCODE_Ok;
  keys[1] = eCLIENTCUSTOMDATAKEYCODE_Back;
  keys[2] = eCLIENTCUSTOMDATAKEYCODE_KnobTickCW;
  keys[3] = eCLIENTCUSTOMDATAKEYCODE_KnobTickCCW;
  mySpin_SetCustomKeysSupported(m_myspin_handle, 4, keys);
  mySpin_SetClientCapabilities(m_myspin_handle, eCLIENTCAPABILITIES_RequiresFocusControl, eFLAG_TRUE);
  mySpin_SetClientCapabilities(m_myspin_handle, eCLIENTCAPABILITIES_PartialFrameUpdate, eFLAG_TRUE);
  mySpin_SetISO639LanguageCode(m_myspin_handle, (UInt8*)"eng");
  mySpin_SetInitialisationTimeout(m_myspin_handle, 0);

  Int32 retErr;
  if ( mySpin_StartMainThreadEx(m_myspin_handle, &retErr) == eFLAG_FALSE ) {
    LOG_ERROR("ADAPTER: mySpin_StartMainThread() returned error code %d.\n", retErr);
    return false;
  }
  return true;
}

void MySPINHandler::stop() {
  m_mtx_for_thread_safe.lock();
  LOG_DEBUG("Begin of stop, m_myspin_handle : %p \n", m_myspin_handle);
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
    mySpin_SetVehicleDataRequestCallback(m_myspin_handle, nullptr);
    mySpin_SetSenderLink(m_myspin_handle, nullptr);
    mySpin_SetReceiverLink(m_myspin_handle, nullptr);
    mySpin_SetTraceOutput(m_myspin_handle, nullptr);
    mySpin_SetLauncherStateCallback(m_myspin_handle, nullptr);
    mySpin_DeleteInstance(m_myspin_handle);
    m_myspin_handle = nullptr;
  } else {
    LOG_WARNING("mySPIN already shut down \n");
  }

  ProjectionHandler::stop();
  LOG_DEBUG("End of stop \n");
  m_mtx_for_thread_safe.unlock();
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

void MySPINHandler::sendTouch(unsigned int x, unsigned int y, int finger, PRESS_TYPE action) {
  // LOG_DEBUG("\n");
  RETURN_IF_NULL(m_myspin_handle);

  TouchEvent touch;
  touch.xPosition = x;
  touch.yPosition = y;
  touch.fingerId = finger;

  switch ( action ) {
    case PRESS_TYPE::MOVE:
      touch.event = eTOUCHTYPE_Moved;
      break;
    case PRESS_TYPE::PRESS:
      touch.event = eTOUCHTYPE_Down;
      break;
    case PRESS_TYPE::RELEASE:
      touch.event = eTOUCHTYPE_Up;
      break;
    case PRESS_TYPE::CANCEL:
      touch.event = eTOUCHTYPE_Cancelled;
      break;
  }
  mySpin_TouchEventsTimed(m_myspin_handle, &touch, 1, 0);
}

void MySPINHandler::requestFrameBuffer() {
  LOG_DEBUG("\n");
  RETURN_IF_NULL(m_myspin_handle);
  mySpin_FramebufferUpdateRequest(m_myspin_handle,
      (UInt16)(0 & 0xFFFF), (UInt16)(0 & 0xFFFF),
      (UInt16)(getWidth() & 0xFFFF), (UInt16)(getHeight() & 0xFFFF), eFLAG_TRUE);
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
  requestFrameBuffer();
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

size_t MySPINHandler::CoreCallBack::__on_receive__(
  void* context, UInt8* buffer, size_t bufferSize, void* connection) {
  auto *handler = static_cast<MySPINHandler*>(context);
  if ( handler ) {
    return handler->__request_to_receive__(buffer, bufferSize, connection);
  }
  return -1;
}

void MySPINHandler::CoreCallBack::__on_protocol__(void* context, eProtocolState newState) {
  LOG_DEBUG("\n");
  auto *handler = static_cast<MySPINHandler*>(context);
  RETURN_IF_NULL(handler);

	switch(newState) {
    case ePROTOCOL_STATE_RUN:
      LOG_DEBUG("ePROTOCOL_STATE_RUN \n");
      {
        UInt8 numberOfKeys = 0;
        Softkey *softkeys;
        mySpin_GetAvailableSoftkeys(handler->__get_myspin_handle__(), &numberOfKeys, &softkeys);
        for ( int i=0; i<numberOfKeys; i++ ) {
          LOG_DEBUG("Support Soft Key[%d] : %d \n", i, softkeys[i]);
        }
      }
      handler->__request_to_notify_ready__();
      handler->requestFrameBuffer();
      break;
    case ePROTOCOL_STATE_STOP:
      LOG_DEBUG("ePROTOCOL_STATE_STOP \n");
      break;
    case ePROTOCOL_STATE_HANDSHAKE:
      LOG_DEBUG("ePROTOCOL_STATE_HANDSHAKE \n");
      break;
	  case ePROTOCOL_STATE_INIT_CLIENT:
      LOG_DEBUG("ePROTOCOL_STATE_INIT_CLIENT \n");
      break;
	  case ePROTOCOL_STATE_INIT_SERVER:
      LOG_DEBUG("ePROTOCOL_STATE_INIT_SERVER \n");
      break;
	  case ePROTOCOL_STATE_INIT_DONE:
      LOG_DEBUG("ePROTOCOL_STATE_INIT_DONE \n");
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
  switch ( error ) {
    case eERRORCODE_CONNECTION_TIMEOUT:
      LOG_ERROR("eERRORCODE_CONNECTION_TIMEOUT\n");
      break;
    case eERRORCODE_CONNECTION_EOF_ZERO:
      LOG_ERROR("eERRORCODE_CONNECTION_EOF_ZERO\n");
      break;
    case eERRORCODE_PROTOCOL_STOP:
      LOG_ERROR("eERRORCODE_PROTOCOL_STOP\n");
      break;
    case eERRORCODE_Z_DATA_ERROR:
      LOG_ERROR("eERRORCODE_Z_DATA_ERROR\n");
      break;
    case eERRORCODE_MEM_ALLOC:
      LOG_ERROR("eERRORCODE_MEM_ALLOC\n");
      break;
    case eERRORCODE_FRAME_SIZE_MISMATCH:
      LOG_ERROR("eERRORCODE_FRAME_SIZE_MISMATCH\n");
      break;
    case eERRORCODE_INITIALIZATION_TIMEOUT:
      LOG_ERROR("eERRORCODE_INITIALIZATION_TIMEOUT\n");
      break;
    case eERRORCODE_RECEIVER_START_FAILED:
      LOG_ERROR("eERRORCODE_RECEIVER_START_FAILED\n");
      break;
    case eERRORCODE_MESSAGE_PROCESSING_FAILED:
      LOG_ERROR("eERRORCODE_MESSAGE_PROCESSING_FAILED\n");
      break;
    case eERRORCODE_JPEG_ERROR:
      LOG_ERROR("eERRORCODE_JPEG_ERROR\n");
      break;
    case eERRORCODE_INITIALIZATION_ABORT:
      LOG_ERROR("eERRORCODE_INITIALIZATION_ABORT\n");
      break;
    case eERRORCODE_NONE:
    default:
      break;
  }
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
  LOG_DEBUG("request : %d, length : %d\n", request, length);
  for ( unsigned int i = 0; i < length; i++ ) {
    LOG_DEBUG("key[%d] : %x \n", i, keyList[i]);
  }
}

void MySPINHandler::CoreCallBack::__on_launcher_state_changed__(
    void *context, LauncherState value) {
  LOG_DEBUG("\n");

  switch ( value ) {
    case eLAUNCHERSTATE_NotVisible:
      LOG_DEBUG("eLAUNCHERSTATE_NotVisible\n");
      break;
    case eLAUNCHERSTATE_VisibleFirst:
      LOG_DEBUG("eLAUNCHERSTATE_VisibleFirst\n");
      break;
    case eLAUNCHERSTATE_VisibleOther:
      LOG_DEBUG("eLAUNCHERSTATE_VisibleOther\n");
      break;
  }
}

void MySPINHandler::CoreCallBack::__on_phone_call_status_changed__(
    void *context, Flag callStarts) {
  LOG_DEBUG("callStarts : %d \n", callStarts);

}