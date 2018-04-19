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

bool MySPINHandler::start() {
  m_myspin_handle = mySpin_CreateInstance(this, "Instance for Sample Adapter Layer");

	mySpin_SetTraceOutput(m_myspin_handle, __on_trace_output__);
  /**
   * eTRACECLASS_ERROR
	 * eTRACECLASS_WARNING
	 * eTRACECLASS_INFORMATION
	 * eTRACECLASS_VERBOSE
	 * eTRACECLASS_INF_FRAME
	 * eTRACECLASS_VER_FRAME
   */
  mySpin_SetTraceClass(m_myspin_handle, eTRACECLASS_VER_FRAME);

	mySpin_SetSenderLink(m_myspin_handle, __on_send__);
	mySpin_SetReceiverLink(m_myspin_handle, __on_receive__);
	mySpin_SetProtocolCallback(m_myspin_handle, __on_protocol__);
	mySpin_SetFrameUpdateStartCallback(m_myspin_handle, __on_frame_update_start__);
	mySpin_SetFrameUpdateCallback(m_myspin_handle, __on_frame_update__);
	mySpin_SetFrameUpdateEndCallback(m_myspin_handle, __on_frame_update_end__);
	mySpin_SetErrorCallback(m_myspin_handle, __on_error__);
	mySpin_SetAppTransitionStatusCallback(m_myspin_handle, __on_app_transition_status__);
	mySpin_SetAppInactiveCallback(m_myspin_handle, __on_app_inactive__);
	mySpin_SetCustomDataStringCallback(m_myspin_handle, __on_custom_data_string__);
	mySpin_SetCustomDataIntCallback(m_myspin_handle, __on_custom_data_int__);
  mySpin_SetVehicleDataRequestCallback(m_myspin_handle, __on_vehicle_data_request__);

  mySpin_SetFrameOutputType(m_myspin_handle, eFLAG_FALSE);
	// mySpin_SetPixelFormat(mySpinHandle, config.pixelFormat, config.bytesPerPixel, config.pixelEndianess);
	// mySpin_SetFrameSize(mySpinHandle, config.frameWidth, config.frameHeight, config.physicalFrameWidth, config.physicalFrameHeight);
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
	mySpin_SetInitialisationTimeout(m_myspin_handle, 10);
  Int32 retErr;
	if (mySpin_StartMainThreadEx(m_myspin_handle, &retErr) == eFLAG_FALSE) {
		fprintf(stdout, "ADAPTER: mySpin_StartMainThread() returned error code %d.\n", retErr);
    return false;
	}

  return true;
}

void MySPINHandler::stop() {

	if ( m_myspin_handle != nullptr ) {
		mySpin_SetProtocolCallback(m_myspin_handle, NULL);
		mySpin_SetFrameUpdateStartCallback(m_myspin_handle, NULL);
		mySpin_SetFrameUpdateCallback(m_myspin_handle, NULL);
		mySpin_SetFrameUpdateEndCallback(m_myspin_handle, NULL);
		mySpin_SetErrorCallback(m_myspin_handle, NULL);
		mySpin_SetAppTransitionStatusCallback(m_myspin_handle, NULL);
		mySpin_SetAppInactiveCallback(m_myspin_handle, NULL);
		mySpin_SetCustomDataStringCallback(m_myspin_handle, NULL);
		mySpin_SetCustomDataIntCallback(m_myspin_handle, NULL);
		mySpin_SetSenderLink(m_myspin_handle, NULL);
		mySpin_SetReceiverLink(m_myspin_handle, NULL);
		mySpin_SetTraceOutput(m_myspin_handle, NULL);
		mySpin_DeleteInstance(m_myspin_handle);
    m_myspin_handle = nullptr;
  }
}

bool MySPINHandler::sendKey(int key, int press) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  return m_listener->onReqSend(buffer, buffer_size);
}

bool MySPINHandler::sendTouch(unsigned int x, unsigned int y, int finger, int action) {
  unsigned char buffer[1024] = {0, };
  unsigned int buffer_size = 0;

  /**
   * @todo Making a buffer to send
   */
  if ( m_listener == nullptr ) return false;
  return m_listener->onReqSend(buffer, buffer_size);
}

void MySPINHandler::__on_trace_output__(
    void* context, eTraceClass traceClass, char* traceString) {
  LOG_DEBUG("mySPIN-CORE : %s %s\n", mySpin_getTraceClassPrefix(traceClass), traceString );
}

void* MySPINHandler::__on_send__(
    void* context, UInt8* buffer, size_t bufferSize, void* connection) {

  return nullptr;
}

size_t MySPINHandler::__on_receive__(
  void* context, UInt8* buffer, size_t bufferSize, void* connection) {

  return 0;
}

void MySPINHandler::__on_protocol__(void* context, eProtocolState newState) {
	switch(newState) {
    case ePROTOCOL_STATE_RUN:
      break;
    case ePROTOCOL_STATE_STOP:
      break;
    default:
      break;
  }
}

void MySPINHandler::__on_frame_update_start__(void* context, UInt8 numOfRectangles) {
	LOG_DEBUG("ADAPTER: frame update start for %d rectangle%s.\n", numOfRectangles, numOfRectangles == 1 ? "" : "s");
}

void MySPINHandler::__on_frame_update__(
    void* context, UInt8 currentNumber, UInt16 x0, UInt16 y0,
    UInt16 width, UInt16 height, UInt8* buffer, UInt32 bufferSize) {

}

void MySPINHandler::__on_frame_update_end__(void* context) {
	LOG_DEBUG("ADAPTER: frame update end\n");
}

void MySPINHandler::__on_error__(void* context, eErrorCode error) {
	LOG_ERROR("ADAPTER: error callback with code %d\n", error);
}

void MySPINHandler::__on_app_transition_status__(void* context, Flag transitionStarts) {
	LOG_DEBUG("ADAPTER: OnAppTransitionStatus with value %s\n", transitionStarts == eFLAG_TRUE ? "TRUE" : "FALSE");
}

void MySPINHandler::__on_app_inactive__(void* context, Flag appInactive) {
	LOG_DEBUG("ADAPTER: OnAppInactive with value %s\n", appInactive == eFLAG_TRUE ? "TRUE" : "FALSE");
}

void MySPINHandler::__on_custom_data_string__(
    void* context, ServerCustomDataStringType type, StringEncoding encoding, char* data) {
	LOG_DEBUG("ADAPTER: OnCustomMessage with type %d and string '%s'\n", type, data);
}

void MySPINHandler::__on_custom_data_int__(
    void* context, ServerCustomDataIntType type, UInt16 length, UInt8* data) {
	LOG_DEBUG("ADAPTER: OnCustomDataInt with type %d and length %d\n", type, length);
}

void MySPINHandler::__on_vehicle_data_request__(
    void* context, Flag request, UInt8 length, UInt32* keyList) {
}