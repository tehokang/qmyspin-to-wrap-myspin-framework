
/*********************************************************************************************************
 *  Generated file  -   D O   N O T   M O D I F Y   !
 *
 *  Generator: mySPIN-ProtocolGenerator  V2.1.0.0
 *  Source:    mySPIN.Connector.IVI-API  V1.2.0
 *
 *  Internal:  WNO   2017-12-28   GeneratorC   V2.3.3.0
 *********************************************************************************************************
 */

#if !defined(MYSPIN_CONNECTOR_IVI_API_BASICTYPES_HEADER)
#define MYSPIN_CONNECTOR_IVI_API_BASICTYPES_HEADER

#ifdef  __cplusplus 
#include <cstdint>
extern "C" { 
#else 
#include <stdlib.h>
#endif 


//=====================================================================================
// TYPES
//=====================================================================================

//-------------------------------------------------------------------------------------
// BASIC TYPES
//-------------------------------------------------------------------------------------
#ifndef __MACTYPES__
#if defined(WIN32)
typedef unsigned __int8 UInt8;
#else
#if defined(__QNX__)
typedef _uint8 UInt8;
#else
#if defined(__GNUC__)
#if defined(MYSPIN_TARGET_FREERTOS)
typedef uint8_t UInt8;
#else
typedef u_int8_t UInt8;
#endif  // FreeRTOS
#else
typedef uint8_t UInt8;
#endif  // GNUC
#endif  // QNX
#endif  // WIN
#endif  // MACTYPES

#ifndef __MACTYPES__
#if defined(WIN32)
typedef unsigned __int16 UInt16;
#else
#if defined(__QNX__)
typedef _uint16 UInt16;
#else
#if defined(__GNUC__)
#if defined(MYSPIN_TARGET_FREERTOS)
typedef uint16_t UInt16;
#else
typedef u_int16_t UInt16;
#endif  // FreeRTOS
#else
typedef uint16_t UInt16;
#endif  // GNUC
#endif  // QNX
#endif  // WIN
#endif  // MACTYPES

#ifndef __MACTYPES__
#if defined(WIN32)
typedef unsigned __int32 UInt32;
#else
#if defined(__QNX__)
typedef _uint32 UInt32;
#else
#if defined(__GNUC__)
#if defined(MYSPIN_TARGET_FREERTOS)
typedef uint32_t UInt32;
#else
typedef u_int32_t UInt32;
#endif  // FreeRTOS
#else
typedef uint32_t UInt32;
#endif  // GNUC
#endif  // QNX
#endif  // WIN
#endif  // MACTYPES

#ifndef __MACTYPES__
#if defined(WIN32)
typedef unsigned __int64 UInt64;
#else
#if defined(__QNX__)
typedef _uint64 UInt64;
#else
#if defined(__GNUC__)
#if defined(MYSPIN_TARGET_FREERTOS)
typedef uint64_t UInt64;
#else
typedef u_int64_t UInt64;
#endif  // FreeRTOS
#else
typedef uint64_t UInt64;
#endif  // GNUC
#endif  // QNX
#endif  // WIN
#endif  // MACTYPES

#if defined(WIN32)
typedef __int8 Int8;
#else
#if defined(__QNX__)
typedef _int8 Int8;
#else
#if defined(__GNUC__)
typedef int8_t Int8;
#else
typedef int8_t Int8;
#endif  // GNUC
#endif  // QNX
#endif  // WIN

#if defined(WIN32)
typedef __int16 Int16;
#else
#if defined(__QNX__)
typedef _int16 Int16;
#else
#if defined(__GNUC__)
typedef int16_t Int16;
#else
typedef int16_t Int16;
#endif  // GNUC
#endif  // QNX
#endif  // WIN

#if defined(WIN32)
typedef __int32 Int32;
#else
#if defined(__QNX__)
typedef _int32 Int32;
#else
#if defined(__GNUC__)
typedef int32_t Int32;
#else
typedef int32_t Int32;
#endif  // GNUC
#endif  // QNX
#endif  // WIN

#if defined(WIN32)
typedef __int64 Int64;
#else
#if defined(__QNX__)
typedef _int64 Int64;
#else
#if defined(__GNUC__)
typedef int64_t Int64;
#else
typedef int64_t Int64;
#endif  // GNUC
#endif  // QNX
#endif  // WIN

UInt32 sizeOf_UInt8();
UInt8 readFromBuffer_UInt8(void** bufferPointer);
void* writeToBuffer_UInt8(void* bufferPointer, UInt8 value);

UInt32 sizeOf_UInt16();
UInt16 readFromBuffer_UInt16(void** bufferPointer);
void* writeToBuffer_UInt16(void* bufferPointer, UInt16 value);

UInt32 sizeOf_UInt32();
UInt32 readFromBuffer_UInt32(void** bufferPointer);
void* writeToBuffer_UInt32(void* bufferPointer, UInt32 value);

UInt32 sizeOf_UInt64();
UInt64 readFromBuffer_UInt64(void** bufferPointer);
void* writeToBuffer_UInt64(void* bufferPointer, UInt64 value);

UInt32 sizeOf_Int8();
Int8 readFromBuffer_Int8(void** bufferPointer);
void* writeToBuffer_Int8(void* bufferPointer, Int8 value);

UInt32 sizeOf_Int16();
Int16 readFromBuffer_Int16(void** bufferPointer);
void* writeToBuffer_Int16(void* bufferPointer, Int16 value);

UInt32 sizeOf_Int32();
Int32 readFromBuffer_Int32(void** bufferPointer);
void* writeToBuffer_Int32(void* bufferPointer, Int32 value);

UInt32 sizeOf_Int64();
Int64 readFromBuffer_Int64(void** bufferPointer);
void* writeToBuffer_Int64(void* bufferPointer, Int64 value);

#if defined(WIN32)
#if !defined(__cplusplus)
typedef unsigned char     bool;
#endif
#endif


#ifdef  __cplusplus 
} 
#endif 


#endif //MYSPIN_CONNECTOR_IVI_API_BASICTYPES_HEADER

