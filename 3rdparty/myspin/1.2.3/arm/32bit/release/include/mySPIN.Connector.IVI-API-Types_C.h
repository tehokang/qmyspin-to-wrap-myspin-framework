
/*********************************************************************************************************
 *  Generated file  -   D O   N O T   M O D I F Y   !
 *
 *  Generator: mySPIN-ProtocolGenerator  V2.1.0.0
 *  Source:    mySPIN.Connector.IVI-API  V1.2.0
 *
 *  Internal:  WNO   2017-12-28   GeneratorC   V2.3.3.0
 *********************************************************************************************************
 */

#if !defined(MYSPIN_CONNECTOR_IVI_API_TYPES_HEADER)
#define MYSPIN_CONNECTOR_IVI_API_TYPES_HEADER

#include "mySPIN.Connector.IVI-API-BasicTypes_C.h"

#ifdef  __cplusplus 
extern "C" { 
#endif 


//=====================================================================================
// TYPES
//=====================================================================================

//-------------------------------------------------------------------------------------
// ENUMERATION TYPES
//-------------------------------------------------------------------------------------

enum _EventType_ENUM_T
{
    eEVENTTYPE_ClientProtocolVersion = 1,
    eEVENTTYPE_ServerProtocolAcknowledge = 2,
    eEVENTTYPE_ClientInit = 11,
    eEVENTTYPE_ServerInitAcknowledge = 12,
    eEVENTTYPE_ServerInit = 14,
    eEVENTTYPE_ClientInitDone = 17,
    eEVENTTYPE_ServerInitDone = 18,
    eEVENTTYPE_SetPixelFormat = 21,
    eEVENTTYPE_PixelFormatAcknowledge = 22,
    eEVENTTYPE_OverrideCompression = 23,
    eEVENTTYPE_OverrideCompressionAcknowledge = 24,
    eEVENTTYPE_FramebufferUpdateRequest = 25,
    eEVENTTYPE_FramebufferUpdate = 26,
    eEVENTTYPE_SetFrameSize = 27,
    eEVENTTYPE_FrameSizeAcknowledge = 28,
    eEVENTTYPE_SoftkeyEvent = 31,
    eEVENTTYPE_TouchEvent = 33,
    eEVENTTYPE_ClientState = 35,
    eEVENTTYPE_ServerState = 36,
    eEVENTTYPE_PositionInformation = 37,
    eEVENTTYPE_SetBlockMode = 39,
    eEVENTTYPE_BlockStatus = 40,
    eEVENTTYPE_BlockHealth = 42,
    eEVENTTYPE_InitiatePhoneCall = 50,
    eEVENTTYPE_PhoneCallStatusResponse = 51,
    eEVENTTYPE_NavigateTo = 52,
    eEVENTTYPE_SetVehicleDataFilter = 54,
    eEVENTTYPE_VehicleData = 55,
    eEVENTTYPE_BlacklistUrgentVehicleData = 56,
    eEVENTTYPE_ServerAudio = 58,
    eEVENTTYPE_ClientAudio = 59,
    eEVENTTYPE_ClientVoiceSupportInfo = 61,
    eEVENTTYPE_ServerVoiceSessionRequest = 62,
    eEVENTTYPE_ClientVoiceSessionStatus = 63,
    eEVENTTYPE_RequestAudioType = 64,
    eEVENTTYPE_AudioTypeResponse = 65,
    eEVENTTYPE_ClientCustomData = 67,
    eEVENTTYPE_ServerCustomData = 68,
    eEVENTTYPE_ClientSettings = 69,
    eEVENTTYPE_ServerAppInfo = 70,
    eEVENTTYPE_ClientRequestAppIcon = 71,
    eEVENTTYPE_ServerAppIcon = 72,
    eEVENTTYPE_ClientStartApp = 73,
    eEVENTTYPE_ServerAppStarted = 74,
    eEVENTTYPE_Ping = 128,
    eEVENTTYPE_PingAcknowledge = 129
};
typedef UInt8 EventType;

enum _StringEncoding_ENUM_T
{
    eSTRINGENCODING_UTF8 = 1,
    eSTRINGENCODING_ASCII_LATIN1 = 2
};
typedef UInt8 StringEncoding;

enum _Flag_ENUM_T
{
    eFLAG_FALSE = 0,
    eFLAG_TRUE = 1
};
typedef UInt8 Flag;

enum _FrameCompression_ENUM_T
{
    eFRAMECOMPRESSION_None = 0,
    eFRAMECOMPRESSION_JPEG = 1,
    eFRAMECOMPRESSION_ZLIB = 2,
    eFRAMECOMPRESSION_Uncompressed = 4,
    eFRAMECOMPRESSION_All = 7
};
typedef UInt32 FrameCompression;

enum _PixelFormat_ENUM_T
{
    ePIXELFORMAT_RGB888 = 1,
    ePIXELFORMAT_RGB565 = 2,
    ePIXELFORMAT_ARGB8888 = 3,
    ePIXELFORMAT_RGBA8888 = 4
};
typedef UInt8 PixelFormat;

enum _PixelEndianess_ENUM_T
{
    ePIXELENDIANESS_BigEndian = 1,
    ePIXELENDIANESS_LittleEndian = 2
};
typedef UInt8 PixelEndianess;

enum _SoftkeyEventType_ENUM_T
{
    eSOFTKEYEVENTTYPE_Press = 1,
    eSOFTKEYEVENTTYPE_Release = 2
};
typedef UInt8 SoftkeyEventType;

enum _Softkey_ENUM_T
{
    eSOFTKEY_Home = 1,
    eSOFTKEY_Back = 2,
    eSOFTKEY_Menu = 3,
    eSOFTKEY_Search = 4
};
typedef UInt8 Softkey;

enum _TouchType_ENUM_T
{
    eTOUCHTYPE_Down = 1,
    eTOUCHTYPE_Up = 2,
    eTOUCHTYPE_Moved = 3,
    eTOUCHTYPE_Cancelled = 4
};
typedef UInt8 TouchType;

enum _ClientDataType_ENUM_T
{
    eCLIENTDATATYPE_Movement = 1,
    eCLIENTDATATYPE_DayNightMode = 2,
    eCLIENTDATATYPE_FrameRequestsSuspended = 3
};
typedef UInt8 ClientDataType;

enum _ServerDataType_ENUM_T
{
    eSERVERDATATYPE_PhoneCall = 1,
    eSERVERDATATYPE_Transition = 2,
    eSERVERDATATYPE_Inactive = 3,
    eSERVERDATATYPE_LauncherAppState = 4,
    eSERVERDATATYPE_PTTAvailable = 5
};
typedef UInt8 ServerDataType;

enum _BlockMode_ENUM_T
{
    eBLOCKMODE_AllowAll = 1,
    eBLOCKMODE_DenyAll = 2,
    eBLOCKMODE_UseWhitelist = 3
};
typedef UInt8 BlockMode;

enum _PhoneCallStatus_ENUM_T
{
    ePHONECALLSTATUS_Received = 1,
    ePHONECALLSTATUS_Started = 2,
    ePHONECALLSTATUS_Active = 3,
    ePHONECALLSTATUS_Ended = 4,
    ePHONECALLSTATUS_Waiting = 5,
    ePHONECALLSTATUS_Rejected = 6
};
typedef UInt8 PhoneCallStatus;

enum _ServerCapabilities_ENUM_T
{
    eSERVERCAPABILITIES_None = 0,
    eSERVERCAPABILITIES_EnableVoiceControlDeprecated = 1,
    eSERVERCAPABILITIES_EnableAudioHandling = 2,
    eSERVERCAPABILITIES_EnableAppStart = 4,
    eSERVERCAPABILITIES_All = 7
};
typedef UInt32 ServerCapabilities;

enum _ClientCapabilities_ENUM_T
{
    eCLIENTCAPABILITIES_None = 0,
    eCLIENTCAPABILITIES_InitiatePhoneCall = 1,
    eCLIENTCAPABILITIES_NavigateTo = 2,
    eCLIENTCAPABILITIES_ScreenCopy = 4,
    eCLIENTCAPABILITIES_PositionInformation = 8,
    eCLIENTCAPABILITIES_AudioHandling = 16,
    eCLIENTCAPABILITIES_PacketExtensions = 32,
    eCLIENTCAPABILITIES_PartialFrameUpdate = 64,
    eCLIENTCAPABILITIES_NoHomeButton = 128,
    eCLIENTCAPABILITIES_RequiresFocusControl = 256,
    eCLIENTCAPABILITIES_IsTwoWheeler = 512,
    eCLIENTCAPABILITIES_IsOtherVehicle = 1024,
    eCLIENTCAPABILITIES_All = 2047
};
typedef UInt32 ClientCapabilities;

enum _VoiceSupport_ENUM_T
{
    eVOICESUPPORT_NotSupported = 0,
    eVOICESUPPORT_VirtualPhoneCallOnly = 1,
    eVOICESUPPORT_FullSCOSupport = 2,
    eVOICESUPPORT_ProtocolTransport = 3,
    eVOICESUPPORT_SecondEndpoint = 4
};
typedef UInt8 VoiceSupport;

enum _VoiceSupportConstraint_ENUM_T
{
    eVOICESUPPORTCONSTRAINT_NoConstraint = 0,
    eVOICESUPPORTCONSTRAINT_MicAndSpeakersTogetherOnly = 1
};
typedef UInt8 VoiceSupportConstraint;

enum _VoiceSessionStatus_ENUM_T
{
    eVOICESESSIONSTATUS_Unavailable = 0,
    eVOICESESSIONSTATUS_Idle = 1,
    eVOICESESSIONSTATUS_StartRequested = 2,
    eVOICESESSIONSTATUS_Active = 3,
    eVOICESESSIONSTATUS_EndRequested = 4
};
typedef UInt8 VoiceSessionStatus;

enum _VoiceSessionStatusConstraint_ENUM_T
{
    eVOICESESSIONSTATUSCONSTRAINT_NoConstraint = 0,
    eVOICESESSIONSTATUSCONSTRAINT_NoHFPConnection = 1,
    eVOICESESSIONSTATUSCONSTRAINT_VoiceAlreadyActive = 2,
    eVOICESESSIONSTATUSCONSTRAINT_SCOTimeout = 3
};
typedef UInt8 VoiceSessionStatusConstraint;

enum _VoiceRequest_ENUM_T
{
    eVOICEREQUEST_StartMicAndSpeakers = 0,
    eVOICEREQUEST_StartMicOnly = 1,
    eVOICEREQUEST_Active = 2,
    eVOICEREQUEST_EndUserEvent = 3,
    eVOICEREQUEST_EndRealCallEvent = 4
};
typedef UInt8 VoiceRequest;

enum _AudioType_ENUM_T
{
    eAUDIOTYPE_Ignore = 1,
    eAUDIOTYPE_Silent = 2,
    eAUDIOTYPE_Main = 3,
    eAUDIOTYPE_Chime = 4,
    eAUDIOTYPE_Announcement = 5,
    eAUDIOTYPE_CriticalAnnouncement = 6
};
typedef UInt8 AudioType;

enum _AudioControl_ENUM_T
{
    eAUDIOCONTROL_Request = 1,
    eAUDIOCONTROL_Release = 5
};
typedef UInt8 AudioControl;

enum _AudioStatus_ENUM_T
{
    eAUDIOSTATUS_Reject = 2,
    eAUDIOSTATUS_Open = 3,
    eAUDIOSTATUS_Suspend = 4,
    eAUDIOSTATUS_Close = 6
};
typedef UInt8 AudioStatus;

enum _CustomDataEvent_ENUM_T
{
    eCUSTOMDATAEVENT_String = 1,
    eCUSTOMDATAEVENT_Int = 2,
    eCUSTOMDATAEVENT_Raw = 3,
    eCUSTOMDATAEVENT_Can = 4,
    eCUSTOMDATAEVENT_Key = 5
};
typedef UInt8 CustomDataEvent;

enum _ClientCustomDataStringType_ENUM_T
{
    eCLIENTCUSTOMDATASTRINGTYPE_BTMACAddress = 1,
    eCLIENTCUSTOMDATASTRINGTYPE_IVIFirmwareVersionA = 2,
    eCLIENTCUSTOMDATASTRINGTYPE_IVIFirmwareVersionB = 3,
    eCLIENTCUSTOMDATASTRINGTYPE_IVIFirmwareVersionC = 4,
    eCLIENTCUSTOMDATASTRINGTYPE_IVIFirmwareVersionD = 5,
    eCLIENTCUSTOMDATASTRINGTYPE_IVIFirmwareVersionE = 6,
    eCLIENTCUSTOMDATASTRINGTYPE_IVIFirmwareVersionF = 7,
    eCLIENTCUSTOMDATASTRINGTYPE_BundleIdiOS = 8
};
typedef UInt16 ClientCustomDataStringType;

enum _ServerCustomDataStringType_ENUM_T
{
    eSERVERCUSTOMDATASTRINGTYPE_BTName = 1,
    eSERVERCUSTOMDATASTRINGTYPE_BundleIdiOS = 2
};
typedef UInt16 ServerCustomDataStringType;

enum _ClientCustomDataIntType_ENUM_T
{
    eCLIENTCUSTOMDATAINTTYPE_ScreenTest = 65280,
    eCLIENTCUSTOMDATAINTTYPE_SPbHUTunerClient = 65024,
    eCLIENTCUSTOMDATAINTTYPE_GetCanAmbientlight = 65281
};
typedef UInt16 ClientCustomDataIntType;

enum _ServerCustomDataIntType_ENUM_T
{
    eSERVERCUSTOMDATAINTTYPE_BatteryLevel = 1,
    eSERVERCUSTOMDATAINTTYPE_CarrierSignalLevel = 2,
    eSERVERCUSTOMDATAINTTYPE_MobileConnectionLevel = 3,
    eSERVERCUSTOMDATAINTTYPE_DateTime = 4,
    eSERVERCUSTOMDATAINTTYPE_BatteryStatus = 5,
    eSERVERCUSTOMDATAINTTYPE_DateTimeLocal = 6,
    eSERVERCUSTOMDATAINTTYPE_SPbHUTunerServer = 65024,
    eSERVERCUSTOMDATAINTTYPE_SetCanAmbientlight = 65281
};
typedef UInt16 ServerCustomDataIntType;

enum _ClientCustomDataRawType_ENUM_T
{
    eCLIENTCUSTOMDATARAWTYPE_NoOperation = 0
};
typedef UInt16 ClientCustomDataRawType;

enum _ServerCustomDataRawType_ENUM_T
{
    eSERVERCUSTOMDATARAWTYPE_NoOperation = 0,
    eSERVERCUSTOMDATARAWTYPE_StoreInstance = 4096,
    eSERVERCUSTOMDATARAWTYPE_GetInstance = 8192,
    eSERVERCUSTOMDATARAWTYPE_StoreCore = 12288,
    eSERVERCUSTOMDATARAWTYPE_GetCore = 16384,
    eSERVERCUSTOMDATARAWTYPE_StorePersistent = 20480,
    eSERVERCUSTOMDATARAWTYPE_GetPersistent = 24576,
    eSERVERCUSTOMDATARAWTYPE_DeletePersistent = 28672,
    eSERVERCUSTOMDATARAWTYPE_StoreHost = 32768,
    eSERVERCUSTOMDATARAWTYPE_GetHost = 36864,
    eSERVERCUSTOMDATARAWTYPE_DeleteHost = 40960
};
typedef UInt16 ServerCustomDataRawType;

enum _ClientCustomDataCanType_ENUM_T
{
    eCLIENTCUSTOMDATACANTYPE_Generic = 1,
    eCLIENTCUSTOMDATACANTYPE_CanAmbientlight = 65281
};
typedef UInt16 ClientCustomDataCanType;

enum _ServerCustomDataCanType_ENUM_T
{
    eSERVERCUSTOMDATACANTYPE_Generic = 1,
    eSERVERCUSTOMDATACANTYPE_CanAmbientlight = 65281
};
typedef UInt16 ServerCustomDataCanType;

enum _ClientCustomDataKeyType_ENUM_T
{
    eCLIENTCUSTOMDATAKEYTYPE_Press = 1,
    eCLIENTCUSTOMDATAKEYTYPE_Release = 2,
    eCLIENTCUSTOMDATAKEYTYPE_LongPress = 3,
    eCLIENTCUSTOMDATAKEYTYPE_Click = 4,
    eCLIENTCUSTOMDATAKEYTYPE_DoubleClick = 5,
    eCLIENTCUSTOMDATAKEYTYPE_Abort = 6
};
typedef UInt16 ClientCustomDataKeyType;

enum _ClientCustomDataKeyCode_ENUM_T
{
    eCLIENTCUSTOMDATAKEYCODE_PushToTalk = 1,
    eCLIENTCUSTOMDATAKEYCODE_ScrollUp = 2,
    eCLIENTCUSTOMDATAKEYCODE_ScrollDown = 3,
    eCLIENTCUSTOMDATAKEYCODE_PageUp = 4,
    eCLIENTCUSTOMDATAKEYCODE_PageDown = 5,
    eCLIENTCUSTOMDATAKEYCODE_ValueUp = 6,
    eCLIENTCUSTOMDATAKEYCODE_ValueDown = 7,
    eCLIENTCUSTOMDATAKEYCODE_PhoneLiftReceiver = 8,
    eCLIENTCUSTOMDATAKEYCODE_PhoneRingOff = 9,
    eCLIENTCUSTOMDATAKEYCODE_VolumeUp = 10,
    eCLIENTCUSTOMDATAKEYCODE_VolumeDown = 11,
    eCLIENTCUSTOMDATAKEYCODE_Ok = 12,
    eCLIENTCUSTOMDATAKEYCODE_Cancel = 13,
    eCLIENTCUSTOMDATAKEYCODE_Back = 14,
    eCLIENTCUSTOMDATAKEYCODE_KnobTickCW = 20,
    eCLIENTCUSTOMDATAKEYCODE_KnobTickCCW = 21,
    eCLIENTCUSTOMDATAKEYCODE_DPadUp = 30,
    eCLIENTCUSTOMDATAKEYCODE_DPadDown = 31,
    eCLIENTCUSTOMDATAKEYCODE_DPadLeft = 32,
    eCLIENTCUSTOMDATAKEYCODE_DPadRight = 33
};
typedef UInt8 ClientCustomDataKeyCode;

enum _ServerCustomDataKeyType_ENUM_T
{
    eSERVERCUSTOMDATAKEYTYPE_Press = 1,
    eSERVERCUSTOMDATAKEYTYPE_Release = 2,
    eSERVERCUSTOMDATAKEYTYPE_LongPress = 3,
    eSERVERCUSTOMDATAKEYTYPE_Click = 4,
    eSERVERCUSTOMDATAKEYTYPE_DoubleClick = 5,
    eSERVERCUSTOMDATAKEYTYPE_Abort = 6
};
typedef UInt16 ServerCustomDataKeyType;

enum _ServerCustomDataKeyCode_ENUM_T
{
    eSERVERCUSTOMDATAKEYCODE_PushToTalk = 1,
    eSERVERCUSTOMDATAKEYCODE_VolumeUp = 10,
    eSERVERCUSTOMDATAKEYCODE_VolumeDown = 11
};
typedef UInt8 ServerCustomDataKeyCode;

enum _AudioRequestResultCode_ENUM_T
{
    eAUDIOREQUESTRESULTCODE_NoError = 0,
    eAUDIOREQUESTRESULTCODE_UnknownError = 255
};
typedef UInt8 AudioRequestResultCode;

enum _NavigateToType_ENUM_T
{
    eNAVIGATETOTYPE_PositionOnly = 1,
    eNAVIGATETOTYPE_PlacemarkOnly = 2,
    eNAVIGATETOTYPE_Both = 3
};
typedef UInt8 NavigateToType;

enum _LauncherState_ENUM_T
{
    eLAUNCHERSTATE_NotVisible = 0,
    eLAUNCHERSTATE_VisibleFirst = 1,
    eLAUNCHERSTATE_VisibleOther = 2
};
typedef UInt8 LauncherState;

enum _AppStartStatus_ENUM_T
{
    eAPPSTARTSTATUS_Unknown = 0,
    eAPPSTARTSTATUS_InProgress = 1,
    eAPPSTARTSTATUS_Success = 2,
    eAPPSTARTSTATUS_Failed = 128,
    eAPPSTARTSTATUS_NotInstalled = 129,
    eAPPSTARTSTATUS_NotAllowed = 130,
    eAPPSTARTSTATUS_NotPaired = 131
};
typedef UInt8 AppStartStatus;

enum _AppInstallationStatus_ENUM_T
{
    eAPPINSTALLATIONSTATUS_Unknown = 0,
    eAPPINSTALLATIONSTATUS_NotInstalled = 1,
    eAPPINSTALLATIONSTATUS_NotPaired = 2,
    eAPPINSTALLATIONSTATUS_Executable = 3
};
typedef UInt8 AppInstallationStatus;

#ifdef  __cplusplus 
} 
#endif 


#endif //MYSPIN_CONNECTOR_IVI_API_TYPES_HEADER

