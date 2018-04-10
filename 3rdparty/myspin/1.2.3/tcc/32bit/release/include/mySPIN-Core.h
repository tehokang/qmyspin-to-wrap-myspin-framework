/*
 * mySPIN-Core.h
 *
 *  Created on: Mar 18, 2013
 *      Author: nwa2hi
 *
 *  last version: Core 1.2.3 for protocol 1.2.0
 *  last date:    January 10, 2017
 *
 *  (C) Bosch SoftTec GmbH
 */

#ifndef MYSPIN_CORE_H_
#define MYSPIN_CORE_H_

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(MYSPIN_TARGET_WINDOWS)
#if defined(MYSPIN_CREATE_CORE_DLL)
#define MYSPIN_CORE_EXPORT	__declspec(dllexport)
#else
#define MYSPIN_CORE_EXPORT	__declspec(dllimport)
#endif
#else
#define MYSPIN_CORE_EXPORT
#endif

#include "mySPIN-Core-Types.h"

// ================================================================================================
// functions
// ================================================================================================

// Initialization
MYSPIN_CORE_EXPORT void mySpin_Init();
MYSPIN_CORE_EXPORT char* mySpin_GetVersion();
MYSPIN_CORE_EXPORT char* mySpin_GetSystemIdentification();

// CreateInstance
MYSPIN_CORE_EXPORT void* mySpin_CreateInstance(void* connectionInfo, const char* hostDescription);

// Data Transfer
MYSPIN_CORE_EXPORT void mySpin_SetSenderLink(void* instanceHandle, void *(*sendFunction) (void* context, UInt8* buffer, size_t bufferSize, void* connectionInfo));
MYSPIN_CORE_EXPORT void mySpin_SetReceiverLink(void* instanceHandle, size_t (*receiveFunction) (void* context, UInt8* buffer, size_t bufferSize, void* conInfo));

// Settings
MYSPIN_CORE_EXPORT void mySpin_SetTraceClass(void* instanceHandle, eTraceClass traceClass);
MYSPIN_CORE_EXPORT void mySpin_SetCallbackContext(void* instanceHandle, void* context);
MYSPIN_CORE_EXPORT void mySpin_SetClientCapabilities(void* instanceHandle, ClientCapabilities item, Flag isAvailable);
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetISO639LanguageCode(void* instanceHandle, UInt8 languageCode[3]);
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetPixelFormatEx(void* instanceHandle, eGraphicType graphicType, PixelFormat format, UInt32 bytesPerPixel, PixelEndianess endian);
MYSPIN_CORE_EXPORT void mySpin_SetPixelFormat(void* instanceHandle, PixelFormat format, UInt32 bytesPerPixel, PixelEndianess endian);
MYSPIN_CORE_EXPORT void mySpin_SetFrameSize(void* instanceHandle, UInt32 frameWidth, UInt32 frameHeight, UInt32 physicalWidth, UInt32 physicalHeight);
MYSPIN_CORE_EXPORT void mySpin_SetSupportedCustomData(void* instanceHandle, UInt8 numberOfEntries, ClientCustomDataIntType* supportedItemsList);
MYSPIN_CORE_EXPORT void mySpin_VoiceSupportInfo(void* instanceHandle, VoiceSupport supportValue, VoiceSupportConstraint supportConstraint);
MYSPIN_CORE_EXPORT void mySpin_SetInitialisationTimeout(void* instanceHandle, UInt8 value);
MYSPIN_CORE_EXPORT void mySpin_EnablePingWatchdog(void* instanceHandle, Flag isEnable, UInt8 timeoutValue);
MYSPIN_CORE_EXPORT eReturnCode mySpin_SendPingAckOnWatchdog(void* instanceHandle, Flag enable);
MYSPIN_CORE_EXPORT void mySpin_SetWaitForJoinTimeout(void* instanceHandle, UInt8 timeoutValue);
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetCustomKeysSupported(void* instanceHandle, UInt8 numberOfKeys, ClientCustomDataKeyCode* keyList);

// Callbacks
MYSPIN_CORE_EXPORT void mySpin_SetTraceOutput(void* instanceHandle, void (*onTraceOutput) (void* context, eTraceClass traceClass, char* traceString));
MYSPIN_CORE_EXPORT void mySpin_SetErrorCallback(void* instanceHandle, void (*onError) (void* context, eErrorCode error));
MYSPIN_CORE_EXPORT void mySpin_SetFrameUpdateStartCallback(void* instanceHandle, void (*onFrameUpdateStart) (void* context, UInt8 numOfRectangles));
MYSPIN_CORE_EXPORT void mySpin_SetFrameUpdateCallback(void* instanceHandle, void (*onFrameUpdate) (void* context, UInt8 currentNumber, UInt16 x0, UInt16 y0, UInt16 width, UInt16 height, UInt8* buffer, UInt32 bufferSize));
MYSPIN_CORE_EXPORT void mySpin_SetFrameUpdateEndCallback(void* instanceHandle, void (*onFrameUpdateEnd) (void* context));
MYSPIN_CORE_EXPORT void mySpin_SetProtocolCallback(void* instanceHandle, void (*protocolCallback) (void* context, eProtocolState newState));
MYSPIN_CORE_EXPORT void mySpin_SetOnMainThreadStartCallback(void* instanceHandle, void (*onMainThreadStart)(void* context));
MYSPIN_CORE_EXPORT void mySpin_SetOnMainThreadEndCallback(void* instanceHandle, void (*onMainThreadEnd)(void* context));
MYSPIN_CORE_EXPORT void mySpin_SetPhonecallStatusCallback(void* instanceHandle, void (*onPhonecallStatusChange)(void* context, Flag callStarts));
MYSPIN_CORE_EXPORT void mySpin_SetAppTransitionStatusCallback(void* instanceHandle, void (*onAppTransitionStatusChange)(void* context, Flag transitionStarts));
MYSPIN_CORE_EXPORT void mySpin_SetAppInactiveCallback(void* instanceHandle, void (*onAppActiveStatusChange)(void* context, Flag appInactive));
MYSPIN_CORE_EXPORT void mySpin_SetLauncherStateCallback(void* instanceHandle, void (*onLauncherState)(void* context, LauncherState value));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetPTTAvailableCallback(void* instanceHandle, void (*onPTTAvailable)(void* context, Flag pttAvailable));
MYSPIN_CORE_EXPORT void mySpin_SetInitiatePhoneCallCallback(void* instanceHandle, void (*onInitiatePhoneCall) (void* context, char* numberString, char* displayString));
MYSPIN_CORE_EXPORT void mySpin_SetNavigateToCallback(void* instanceHandle, void (*onNavigateTo) (void* context, char* displayString, NavigateToType type, double longitude, double latitude, LocationStrings* locationDesciption));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetAudioRequestCallback(void* instanceHandle, void (*onAudioRequest)(void* context, AudioControl command, UInt32 requestID, AudioType type));
MYSPIN_CORE_EXPORT void mySpin_SetVoiceSessionRequestCallback(void* instanceHandle, void (*onVoiceSessionRequest)(void* context, VoiceRequest requestType));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetVehicleDataRequestCallback(void* instanceHandle, void (*onVehicleDataRequest)(void* context, Flag request, UInt8 length, UInt32* keyList));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetCustomDataStringCallback(void* instanceHandle, void (*onCustomDataString)(void* context, ServerCustomDataStringType type, StringEncoding encoding, char* data));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetCustomDataIntCallback(void* instanceHandle, void (*onCustomDataInt)(void* context, ServerCustomDataIntType type, UInt16 length, UInt8* data));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetCustomDataKeyCallback(void* instanceHandle, void (*onCustomDataKey)(void* context, ServerCustomDataKeyType type, ServerCustomDataKeyCode code));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetCustomDataCanCallback(void* instanceHandle, void (*onCustomDataCan)(void* context, ServerCustomDataCanType type, UInt32 identifier, UInt8 dataLengthCode, UInt8* data));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetCustomDataRawCallback(void* instanceHandle, void (*onCustomDataRaw)(void* context, ServerCustomDataRawType type, UInt16 dataIdentifier, UInt16 length, UInt8* data));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetAppListChangedCallback(void* instanceHandle, void (*onAppListChanged)(void* context));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetAppIconResponseCallback(void* instanceHandle, void (*onAppIconResponse)(void* context, AppIconResponse* appIcon));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetAppStartedResponseCallback(void* instanceHandle, void (*onAppStartedResponse)(void* context, const char* identifierURL, AppStartStatus appStartStatus));
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetEndReceiverRequestCallback(void* instancehandle, void (*onEndReceiverRequest)(void* context));

// Start Operation
MYSPIN_CORE_EXPORT Flag mySpin_StartMainThreadEx(void* instanceHandle, Int32* errorNumber);
MYSPIN_CORE_EXPORT void mySpin_GetAvailableSoftkeys(void* instanceHandle, UInt8* numberOfKeys, Softkey** keyList);
MYSPIN_CORE_EXPORT ServerCapabilities mySpin_GetServerCapabilities(void* instanceHandle);
MYSPIN_CORE_EXPORT UInt16 mySpin_GetServerAppName(void* instanceHandle, char* textBuffer, UInt16 textBufferLen);
MYSPIN_CORE_EXPORT UInt16 mySpin_GetServerOSName(void* instanceHandle, char* textBuffer, UInt16 textBufferLen);
MYSPIN_CORE_EXPORT UInt16 mySpin_GetLauncherUUID(void* instanceHandle, char* textBuffer, UInt16 textBufferLen);

// Operation
MYSPIN_CORE_EXPORT void mySpin_FramebufferUpdateRequest(void* instanceHandle, UInt16 x0, UInt16 y0, UInt16 width, UInt16 height, Flag incremental);
MYSPIN_CORE_EXPORT void mySpin_SoftkeyEvent(void* instanceHandle, Softkey key, SoftkeyEventType event);
MYSPIN_CORE_EXPORT void mySpin_TouchEvents(void* instanceHandle, TouchEvent* eventArray, UInt8 numberOfEvents);
MYSPIN_CORE_EXPORT void mySpin_TouchEventsTimed(void* instanceHandle, TouchEvent* eventArray, UInt8 numberOfEvents, UInt32 timestamp);
MYSPIN_CORE_EXPORT eReturnCode mySpin_VehicleData(void* instanceHandle, UInt32 key, StringEncoding encoding, const char* jsonString);
MYSPIN_CORE_EXPORT void mySpin_PhoneCallStatusResponse(void* instanceHandle, PhoneCallStatus statusValue);
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetAudioStatus(void* instanceHandle, UInt32 requestID, AudioStatus status, AudioRequestResultCode reason);
MYSPIN_CORE_EXPORT void mySpin_VoiceSessionStatus(void* instanceHandle, VoiceSessionStatus statusValue, VoiceSessionStatusConstraint statusConstraint);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CustomDataString(void* instanceHandle, ClientCustomDataStringType type, StringEncoding encoding, const char* messageString);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CustomDataInt(void* instanceHandle, ClientCustomDataIntType type, UInt16 length, UInt8* pValue);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CustomDataKey(void* instanceHandle, ClientCustomDataKeyType type, ClientCustomDataKeyCode code);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CustomDataKeyTimed(void* instanceHandle, ClientCustomDataKeyType type, ClientCustomDataKeyCode code, UInt32 timestamp);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CustomDataCan(void* instanceHandle, ClientCustomDataCanType type, UInt32 identifier, UInt8 dataLengthCode, UInt8* data);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CustomDataRaw(void* instanceHandle, UInt16 identifier, UInt16 length, UInt8* pData);
MYSPIN_CORE_EXPORT eReturnCode mySpin_CreateAppInfoList(void* instanceHandle, UInt32* numberOfItems, AppInfoList** infoList);
MYSPIN_CORE_EXPORT eReturnCode mySpin_DeleteAppInfoList(void* instanceHandle, AppInfoList* infoList);
MYSPIN_CORE_EXPORT eReturnCode mySpin_RequestAppIcon(void* instanceHandle, const char* identifierURL, UInt16 width, UInt16 height);
MYSPIN_CORE_EXPORT eReturnCode mySpin_StartApp(void* instanceHandle, const char* identifierURL, KeyValueList* launchModes, KeyValueList* options);
MYSPIN_CORE_EXPORT eReturnCode mySpin_FrameRequestStatus(void* instanceHandle, Flag isSuspended);

// DeleteInstance
MYSPIN_CORE_EXPORT void mySpin_DeleteInstance(void* instanceHandle);

// Shutdown
MYSPIN_CORE_EXPORT void mySpin_Shutdown();

// Other
MYSPIN_CORE_EXPORT void* mySpin_GetConnectionInfo(void* instanceHandle);
MYSPIN_CORE_EXPORT char* mySpin_getTraceClassPrefix(eTraceClass theClass);
MYSPIN_CORE_EXPORT void mySpin_OverrideCompressionFormat(void* instanceHandle, FrameCompression compression);
MYSPIN_CORE_EXPORT void mySpin_SetFrameOutputType(void* instanceHandle, Flag useRaw);
MYSPIN_CORE_EXPORT eReturnCode mySpin_SetSupportedCompressions(void* instanceHandle, UInt32 compressions);
MYSPIN_CORE_EXPORT void mySpin_SetFrameUpdateRawCallback(void* instanceHandle, void (*onFrameUpdateRaw) (void* context,
									UInt8 rectNumber, UInt16 x0, UInt16 y0, UInt16 width, UInt16 height,
									UInt8* buffer, UInt32 bufferSize,
									UInt8 scaleHorizontal, UInt8 scaleVertical,
									PixelFormat format, PixelEndianess endian, FrameCompression compression));
MYSPIN_CORE_EXPORT void mySpin_SetDumpProperties(void* instanceHandle, Flag enable, Flag isStdDevice, UInt8 device, char* fileName);

// Deprecated functions
// used only in one project
MYSPIN_CORE_EXPORT void mySpin_AnnounceShutdown(void* instanceHandle);

// Deprecated functions now removed


#ifdef __cplusplus
}
#endif

#endif /* MYSPIN_CORE_H_ */
