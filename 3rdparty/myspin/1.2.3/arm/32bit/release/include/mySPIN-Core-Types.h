/*
 * mySPIN-Core.h
 *
 *  Created on: Feb 2, 2015
 *      Author: nwa2hi
 *
 *  last version: Core 1.1.3 for protocol 1.1.0
 *  last date:    Feb 2, 2015
 *
 *  (C) Bosch SoftTec GmbH
 */

#ifndef MYSPIN_CORE_TYPES_H_
#define MYSPIN_CORE_TYPES_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include "mySPIN.Connector.IVI-API-Types_C.h"

// ================================================================================================
// enumeration types
// ================================================================================================

enum _RETURN_CODE_T
{
	eRETURN_OKAY = 0,
	eRETURN_NULL_PARAM = -1,
	eRETURN_PACKET_MEMORY = -2,
	eRETURN_STATE_NOT_RUN = -3,
	eRETURN_NULL_HANDLE = -4,
	eRETURN_PARAM_VALUE = -5,
	eRETURN_NOT_FOUND = -6,
	eRETURN_MEM_ALLOC = -7,
	eRETURN_NOT_SUPPORTED = -8,
	eRETURN_ALREADY_IN_LIST = -9,
	eRETURN_NOT_ALLOWED = -10
};
typedef enum _RETURN_CODE_T eReturnCode;

enum _PROTOCOL_STATE_T
{
	ePROTOCOL_STATE_NONE = 0,
	ePROTOCOL_STATE_HANDSHAKE,
	ePROTOCOL_STATE_INIT_CLIENT,
	ePROTOCOL_STATE_INIT_SERVER,
	ePROTOCOL_STATE_INIT_DONE,
	ePROTOCOL_STATE_RUN,
	ePROTOCOL_STATE_STOP
};
typedef enum _PROTOCOL_STATE_T eProtocolState;

typedef enum
{
	eERRORCODE_NONE = 0,
	eERRORCODE_CONNECTION_TIMEOUT,			// connection timeout
	eERRORCODE_CONNECTION_EOF_ZERO,			// receive function returned EOF or 0 bytes
	eERRORCODE_PROTOCOL_STOP,				// protocol status change from RUN to STOP
	eERRORCODE_Z_DATA_ERROR,				// error while uncompression frame data
	eERRORCODE_MEM_ALLOC,					// memory allocation needed for operation failed
	eERRORCODE_FRAME_SIZE_MISMATCH,			// uncompressed frame size != expected size (width*height*bpp)
	eERRORCODE_INITIALIZATION_TIMEOUT,		// protocol setup time exceeded; will probably never reach _STATE_RUN
	eERRORCODE_RECEIVER_START_FAILED,		// pthread_create() for main thread returned error
	eERRORCODE_MESSAGE_PROCESSING_FAILED,	// message processing failed: NULL pointer, unknown event or memory allocation
	eERRORCODE_JPEG_ERROR,					// error while uncompression frame data
	eERRORCODE_INITIALIZATION_ABORT,		// main thread end while init timeout running
} eErrorCode;

typedef enum
{
	eTRACECLASS_NONE        = 0x00,
	eTRACECLASS_ERROR       = 0x01,
	eTRACECLASS_WARNING     = 0x02,
	eTRACECLASS_INFORMATION = 0x04,
	eTRACECLASS_VERBOSE     = 0x08,
	eTRACECLASS_INF_FRAME   = 0x10,
	eTRACECLASS_VER_FRAME   = 0x20
} eTraceClass;

typedef enum
{
	eLOCATION_Country		= 0x0001,
	eLOCATION_StateRegion	= 0x0002,
	eLOCATION_ZipCode		= 0x0004,
	eLOCATION_City			= 0x0008,
	eLOCATION_Street		= 0x0010,
	eLOCATION_CrossStreet	= 0x0020,
	eLOCATION_Housenumber	= 0x0040
} LocationStringsMask;

typedef enum
{
    eGRAPHICTYPE_Unknown = 0,
    eGRAPHICTYPE_Frame = 1,
    eGRAPHICTYPE_Icon = 2
} eGraphicType;

// ================================================================================================
// structure types
// ================================================================================================
typedef struct
{
	TouchType	event;
	UInt16		xPosition;
	UInt16		yPosition;
	UInt32		fingerId;
} TouchEvent;

typedef struct
{
	UInt16 validMask;
	char* Country;
	char* StateRegion;
	char* ZipCode;
	char* City;
	char* Street;
	char* CrossStreet;
	char* Housenumber;
} LocationStrings;


typedef struct
{
	char* IdentifierURL;
	char* Name;
	Flag  IsInstalled;
} ShortAppInfo;

typedef struct
{
	UInt8 NumberOfCategories;
	UInt32* Categories;
} CategoryList;

typedef struct
{
	char* key;
	char* value;
} KeyValue;

typedef struct
{
	UInt8 NumberOfEntries;
	KeyValue* Entries;
} KeyValueList;

typedef struct
{
	char* IdentifierURL;
	char* Name;
	UInt32 UniqueIconID;
	char* Manufacturer;
	char* Description;
	CategoryList* Categories;
	AppInstallationStatus InstStatus;
	Flag IsAbleToLaunchApps;
	UInt8 arrLanguage[3];
} AppInfo;

typedef struct
{
	UInt8 NumberOfEntries;
	AppInfo** Entries;
} AppInfoList;


typedef struct
{
	char* IdentifierURL;
	UInt32 UniqueIconID;
	UInt32 uncompressedDataLength;
	UInt8* uncompressedData;
} AppIconResponse;


#ifdef __cplusplus
}
#endif

#endif /* MYSPIN_CORE_TYPES_H_ */
