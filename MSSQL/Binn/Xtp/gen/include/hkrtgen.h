//*********************************************************************
// Copyright (c) Microsoft Corporation.
//*********************************************************************















#pragma once

#include "hkrtdef.h"


struct HkTableBindings
{
	
	unsigned int		TableId;
	struct HkTableMD*	TableMD;
};


struct HkProcBindings
{
	unsigned int			CountTableTypes;
	unsigned int			CountTables;
	
	unsigned int*			TableIds;
	struct HkTable**		Tables;
	struct HkSequenceObj**	SeqObjs;
	long					ProcId;
	struct HkProcInfo*		ProcInfo;
	unsigned int*			TableIdsStabilize;
};






HKRAPI __checkReturn HRESULT
SendOutputMetadata(
	__in struct HkProcContext* 		hkcontext,
	__in struct HkOutputMetadata*	hkoutput);

HKRAPI __checkReturn HRESULT
SendCurrentOutput(
	__in struct HkProcContext* 	hkcontext,
	int							rowcount,
	bool						isEndOfResultSet);

HKRAPI void
EndCurrentResultForError(__in struct HkProcContext* hkcontext);

HKRAPI __checkReturn HRESULT
HostConvert(
	__in struct HkErrorObject*  errorObj,
	unsigned char				fWarnTrunc,
	long						style,
	unsigned char				dateFormat,
	unsigned char				toType,
	unsigned char				toPrecision,
	unsigned char				toScale,
	unsigned short				toMaxLength,
	unsigned long				toCollation,
	__out union HkValue*		toValue,
	unsigned char				fromType,
	unsigned char				fromPrecision,
	unsigned char				fromScale,
	unsigned short				fromMaxLength,
	unsigned long				fromCollation,
	union HkValue				fromValue);

HKRAPI __checkReturn __int64
GetDateTime();

HKRAPI __checkReturn __int64
GetUTCDateTime();

HKRAPI __checkReturn HRESULT
GetDateTime2(
	__out __int64* result, 
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn __int64
GetUTCDateTime2();


HKRAPI __forceinline __checkReturn struct HkSixteenByteData
GetNewId();
HKRAPI __forceinline __checkReturn struct HkSixteenByteData
GetNewSequentialId();

HKRAPI __checkReturn int
DatePart(int datePart, __int64 date, int dateFirst);

HKRAPI __checkReturn HRESULT
DateAdd(
	int datePart,
	int number,
	int date,
	__out int* result);

HKRAPI __checkReturn int
DateDiff(
	int datePart,
	int firstDate,
	int secondDate);

HKRAPI __checkReturn int
EOMonth(int date);

HKRAPI __checkReturn HRESULT
SmallDateTimeFromParts(
	int year,
	int month,
	int day,
	int hour,
	int minute,
	__out int* result,
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn HRESULT
DateTimeFromParts(
	int year,
	int month,
	int day,
	int hour,
	int minute,
	int seconds,
	int milliseconds,
	__out __int64* result,
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn HRESULT
DateFromParts(
	int year,
	int month,
	int day,
	__out int* result,
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn HRESULT
TimeFromParts(
	int hour,
	int minute,
	int seconds,
	int fractions,
	int precision,
	__out __int64* result,
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn HRESULT
DateTime2FromParts(
	int year,
	int month,
	int day,
	int hour,
	int minute,
	int seconds,
	int fractions,
	int precision,
	__out __int64* result,
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn double
Rand();

HKRAPI __checkReturn double
SRand(int seed);

HKRAPI __checkReturn double
Cot(double x);

HKRAPI __checkReturn double
LogBaseN(double x, double base);

HKRAPI __checkReturn HRESULT
CreateError(
	__in struct HkErrorObject* errorObj,
	HRESULT hr,
	unsigned long paramCount,
	...);

HKRAPI void
CreateErrorForThrow(
	__in struct HkErrorObject* errorObj,
	int errorNum, 
	int state,
	unsigned long line,
	unsigned short msgLenInBytes,
	__in_ecount(msgLenInBytes) const unsigned char* msg);

HKRAPI void
SetLineNumberForError(
	__inout struct HkErrorObject* errorObj,
	unsigned long line);

HKRAPI __checkReturn HRESULT
CreateErrorForRethrow(
	__inout struct HkErrorObject* errorObj);

HKRAPI __checkReturn HRESULT
SaveErrorForCatchBlock(
	__inout struct HkErrorObject* errorObj);

HKRAPI __checkReturn HRESULT
DismissErrorForCatchBlock(
	__inout struct HkErrorObject* errorObj);

HKRAPI __checkReturn long
GetErrorNumber(
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn unsigned char*
GetErrorMessage(
	__in struct HkErrorObject* errorObj,
	__out unsigned short* msgLen);

HKRAPI __checkReturn long
GetErrorSeverity(
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn long
GetErrorState(
	__in struct HkErrorObject* errorObj);

HKRAPI __checkReturn long
GetErrorLine(
	__in struct HkErrorObject* errorObj);

#ifndef GOLDEN_BITS

HKRAPI void
FireXEventsForCallback(
	int callback,
	void const* left,
	void const* right,
	__int64 res,
	unsigned long dbid,
	unsigned long objid,
	unsigned long indid,
	unsigned long hkIndexId,
	struct HkColsInfo const* colsInfo);

HKRAPI void
FireXEventForHkSearchKey(
	struct HkSearchKey const* key,
	bool isEndKey,
	bool isPointLookup,
	bool isEndTable,
	unsigned long objid,
	unsigned long indid);

HKRAPI void
FireXEventForQuerySearchKey(
	unsigned long colCount,
	bool isStrict,
	bool isEndKey,
	bool isPointLookup,
	unsigned long objid,
	unsigned long indid,
	...);

#endif

HKRAPI void
AssertFail(
	unsigned int assert_type,
	__in __nullterminated const char* exp,
	__in __nullterminated const char* filename,
	int line,
	__in_opt __nullterminated const char* szDesc,
	__in char* args);

HKRAPI __checkReturn HRESULT
YieldThread(__in struct HkProcContext* hkcontext, unsigned long lineNo);

HKRAPI void
ThrowErrorHr(HRESULT hr);

HKRAPI __checkReturn HRESULT
SortHkRows(
	__in struct HkProcContext* hkcontext,
	__in void * context,
	__in void* sortBuffer,
	int (__cdecl *compare)(void *, const void *, const void *),
	long countRows,
	__in size_t sizeOfSortBufElem);

HKRAPI __checkReturn HRESULT
InitPriorityQueue(
	HRESULT (__cdecl *compare)(void *, long, long, __int64*),
	__in void* context,
	__out_ecount(sizeOfPriorityQueue) long *priorityQueue,
	__int64 sizeOfPriorityQueue,
	__out long *nextEntryPoint);
	
HKRAPI __checkReturn HRESULT
InsertIntoPriorityQueue(
	HRESULT (__cdecl *compare)(void *, long, long, __int64*),
	__in void* context,
	__inout_ecount(sizeOfPriorityQueue) long *priorityQueue,
	__int64 sizeOfPriorityQueue,
	__inout long *nextEntryPoint);

HKRAPI void
InitTopSortContext(
	__inout struct HkCallbackContext* callbackContext,
	__inout struct HkCompareContext* cmpContext,
	__inout struct HkTopSortContext* topsortContext,
	const void* params,
	size_t sortBufElemSize,
	__in unsigned char* deepDataBuffer,
	__in struct HkProcContext* hkcontext);




HKRAPI __checkReturn HRESULT
InitSortContext(
	__inout struct HkCallbackContext* callbackContext,
	__inout struct HkCompareContext* cmpContext,
	__inout struct HkSortContext* sortContext,
	const void* params,
	size_t sortBufElemSize,
	__in unsigned char* deepDataBuffer,
	__in struct HkProcContext* hkcontext,
	HRESULT (__cdecl *pqCompare)(void *, long, long, __int64*),
	int (__cdecl *sortCompare)(void *, const void *, const void *));




HKRAPI __checkReturn HRESULT
GetNextSortedRow(
	__in struct HkProcContext* hkcontext,
	__inout struct HkSortContext* sortContext,
	__deref_out void** returnRow);




HKRAPI __checkReturn HRESULT
GetFirstSortedRow(
	__in struct HkProcContext* hkcontext,
	__inout struct HkSortContext* sortContext,
	__deref_out void** returnRow);








HKRAPI __checkReturn HRESULT
GetEmptySortRowSlot(
	__in struct HkProcContext* hkcontext,
	__inout struct HkSortContext* sortContext,
	__deref_out void** returnRow);



HKRAPI __checkReturn HRESULT
AllocateBuffer(
	__in struct HkProcContext* hkcontext,
	__deref_out void** returnBuffer);

HKRAPI void
DeallocateBuffer(
	__in struct HkProcContext* hkcontext,
	__inout void* page);




HKRAPI void
DeallocateBufferForSort(
	__in struct HkProcContext* hkcontext,
	__inout struct HkSortContext* sortContext);




HKRAPI void
DeallocateBufferForTopSort(
	__in struct HkProcContext* hkcontext,
	__inout struct HkTopSortContext* topSortContext);

#if !defined(HKRUNTIME_BUILD)
	HKRAPI __checkReturn double acos(double x);
	HKRAPI __checkReturn double asin(double x);
	HKRAPI __checkReturn double atan(double x);
	HKRAPI __checkReturn double atan2(double x, double y);
	HKRAPI __checkReturn double cos(double x);
	HKRAPI __checkReturn double exp(double x);
	HKRAPI __checkReturn double log(double x);
	HKRAPI __checkReturn double log10(double x);
	HKRAPI __checkReturn double pow(double x, double y);
	HKRAPI __checkReturn double sin(double x);
	HKRAPI __checkReturn double sqrt(double x);
	HKRAPI __checkReturn double tan(double x);
#endif

