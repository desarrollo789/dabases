//*********************************************************************
// Copyright (c) Microsoft Corporation.
//*********************************************************************
















#pragma once




#include "hkengdef.h"

struct HkTable;
struct HkTransaction;
struct HkDatabase;
struct HkSequenceObj;



typedef unsigned long HkHash;














typedef void
(*KeyIncrementFn)(
	__in const struct HkFlatKey* source,
	__out struct HkSearchKey* target);









typedef __checkReturn __int64
(*CompareSKeyToFKeyFn)(
	__in const struct HkSearchKey* left,
	__in const struct HkFlatKey* right);









typedef __checkReturn __int64
(*CompareFKeyToFKeyFn)(
	__in const struct HkFlatKey* left,
	__in const struct HkFlatKey* right);














typedef __checkReturn __int64
(*CompareSKeyToRowFn)(
	__in const struct HkSearchKey* key,
	__in const struct HkRow* row);














typedef __checkReturn __int64
(*CompareRowToRowFn)(
	__in const struct HkRow* left,
	__in const struct HkRow* right);








typedef __checkReturn HkHash
(*ComputeSKeyHashFn)(
	__in const struct HkSearchKey* key);








typedef __checkReturn HkHash
(*ComputeFKeyHashFn)(
	__in const struct HkFlatKey* key);













typedef __checkReturn HkHash
(*ComputeRowHashFn)(
	__in const struct HkRow* row);
















typedef __checkReturn HRESULT
(*ExtractFlatKeyFn)(
	__in const struct HkRow* row,
	__out struct HkFlatKey* key,
	__in unsigned short bufferSize,
	__out unsigned short* keySize);



typedef enum
{
	
	
	HkHashIndexType = 0,		

	
	
	HkRangeIndexType = 1,

} HkIndexType;



enum HkIndexFlags
{
	HkIdxFlags_None = 0x0000,

	
	
	HkIdxFlags_IsUnique = 0x0001,

	
	
	
	
	HkIdxFlags_FixedSizeKeys = 0x0002,
};



struct HkHashIndexMD
{
	
	
	
	unsigned long MdIndexId;	

	
	
	unsigned short IndexFlags;

	
	
	unsigned int NumberOfBuckets;

	
	
	
	
	
	
	CompareSKeyToRowFn		CompareSKeyToRow;
	CompareRowToRowFn		CompareRowToRow;
	ComputeSKeyHashFn		ComputeSKeyHash;
	ComputeRowHashFn		ComputeRowHash;
};



struct HkRangeIndexMD
{	
	
	
	
	unsigned long MdIndexId;	

	
	
	unsigned short IndexFlags;

	
	
	
	unsigned short FlatKeySize;

	
	
	
	
	
	unsigned short SearchKeySize;

	
	
	struct HkFlatKey const* InfinityKey;

	
	
	unsigned short InfinityKeySize;

	
	
	
	
	
	
	CompareSKeyToFKeyFn		CompareSKeyToFKey;
	CompareFKeyToFKeyFn		CompareFKeyToFKey;
	CompareSKeyToRowFn		CompareSKeyToRow;
	ComputeFKeyHashFn		ComputeFKeyHash;
	ExtractFlatKeyFn		ExtractFlatKey;
	KeyIncrementFn			KeyIncrement;
};









typedef __checkReturn unsigned short
(*GetSerializeSizeFn)(
	__in const struct HkRow* row);









typedef __checkReturn HRESULT
(*SerializeFn)(
	__in const struct HkRow* row,
	__in_bcount(bufferSize) unsigned char* buffer,
	__in unsigned short bufferSize,
	__out unsigned short* copySize);








typedef __checkReturn HRESULT
(*DeserializeFn)(
	__in struct HkTransaction* tx,
	__in struct HkTable* table,
	__in_bcount(dataSize) const unsigned char* data,
	__in unsigned short dataSize,
	__out struct HkRow** row);














typedef __checkReturn unsigned short
(*GetSerializeRecKeySizeFn)(
	__in const struct HkRow* row);















typedef __checkReturn HRESULT
(*SerializeRecKeyFn)(
	__in const struct HkRow* row,
	__out_bcount(bufferSize) unsigned char* buffer,
	__in unsigned short bufferSize,
	__out unsigned short* copySize);













typedef __checkReturn HRESULT
(*DeserializeRecKeyFn)(
	__in_bcount(dataSize) const unsigned char* data,
	__in unsigned short dataSize,
	__out_bcount(bufferSize) struct HkSearchKey* key,
	__in unsigned short bufferSize);



struct HkCallbackContext
{
	
	
	struct HkErrorObject* ErrorObject;

	
	
	unsigned char* DeepDataBuffer;
};








enum HkTableFlags
{
	
	
	HkTableFlags_None = 0x0000,

	
	
	HkTableFlags_IsNonDurable = 0x0001,

	
	
	HkTableFlags_Default = HkTableFlags_None
};



struct HkTableMD
{
	
	
	size_t MinRowSize;
	
	
	
	size_t MaxRowSize;

	
	
	unsigned int CountHashIndices;

	
	
	struct HkHashIndexMD* HashIndexMD;

	
	
	unsigned int CountRangeIndices;

	
	
	struct HkRangeIndexMD* RangeIndexMD;

	
	
	
	
	
	
	
	
	
	unsigned int RecoveryIndex;

	
	
	void const* OpaqueData;

	
	
	
	
	
	
	unsigned int HostTableId;

	
	
	enum HkTableFlags TableFlags;

	
	
	
	
	
	
	
	GetSerializeSizeFn			GetSerializeSize;
	SerializeFn					Serialize;
	DeserializeFn				Deserialize;
	GetSerializeRecKeySizeFn	GetSerializeRecKeySize;
	SerializeRecKeyFn			SerializeRecKey;
	DeserializeRecKeyFn			DeserializeRecKey;
};

HKEAPI void HKAPICC
HkTableReleaseUnusedRow(
	__in struct HkRow* row,
	__in struct HkTable* table,
	__in struct HkTransaction* tx);

HKEAPI __checkReturn HRESULT HKAPICC
HkTableInsert(
	__in struct HkTable* table,
	__in struct HkTransaction* tx,
	__in struct HkRow* row);

HKEAPI __checkReturn HRESULT HKAPICC
HkTableUpdate(
	__in struct HkTable* table,
	__in struct HkTransaction* tx,
	__in struct HkRow* rowToUpdate,
	__in struct HkRow* newRow,
	__in unsigned long indexChangeMap);

HKEAPI __checkReturn HRESULT
HkTableDelete(
	__in struct HkTable* table,
	__in struct HkTransaction* tx,
	__in struct HkRow* row);

HKEAPI __checkReturn HRESULT HKAPICC
HkTransactionAllocMemory(
	__in struct HkTransaction* tx,
	__in unsigned long size,
	__deref_out_bcount(size) unsigned char** txMemory);

HKEAPI __checkReturn HRESULT HKAPICC
HkTransactionCreateSavePoint(
	__in struct HkTransaction* tx,
	__out HkTxSavePointId* id);

HKEAPI __checkReturn void HKAPICC
HkTransactionRefreshSavePoint(
	__in struct HkTransaction* tx,
	__in HkTxSavePointId id);

HKEAPI __checkReturn HRESULT HKAPICC
HkTransactionRollbackToSavePoint(
	__in struct HkTransaction* tx,
	__in HkTxSavePointId id);

HKEAPI __checkReturn HRESULT HKAPICC
HkTransactionWaitForDependencies(
	__in struct HkTransaction* tx,
	__in struct HkWait* wait);

HKEAPI __checkReturn HRESULT HKAPICC
HkRefreshStatementId(
	__in struct HkTransaction* tx);

HKEAPI __checkReturn HRESULT HKAPICC
HkRowAlloc(
	__in struct HkTransaction* transaction,
	__in struct HkTable* table,
	__in unsigned long rowSize,
	__out struct HkRow** row);

HKEAPI __checkReturn HRESULT HKAPICC
HkCursorHashAlloc(
	__in struct HkTable* table,
	__in unsigned int indexId,
	__in FilterFn filterFunction,
	__in unsigned int bufferRequiredForFilter,
	__out_opt struct HkErrorObject* error, 
	__out struct HkCursorHash** cursorHash,
	__in_opt const char* tag);

HKEAPI void HKAPICC
HkCursorHashFree(
	__in struct HkCursorHash* cursor);

HKEAPI __checkReturn HRESULT HKAPICC
HkCursorHashGetFirst(
	__in struct HkCursorHash* cursor,
	__in struct HkTransaction* tx,
	__in const struct HkSearchKey* key,
	__in_opt const struct HkParam* params,
	__in TxIsoLevel isoLevel,
	__out const struct HkRow** row);

HKEAPI __checkReturn __success(return == S_OK) HRESULT HKAPICC
HkCursorHashGetNext(
	__in struct HkCursorHash*  cursor,
	__out_opt struct HkErrorObject* error,
	__out const struct HkRow** row);

HKEAPI __checkReturn HRESULT HKAPICC
HkCursorRangeAlloc(
	__in struct HkTable* table,
	__in unsigned int indexId,
	__in FilterFn filterFunction,
	__in unsigned int bufferRequiredForFilter,
	__out_opt struct HkErrorObject* error, 
	__out struct HkCursorRange** cursorRange,
	__in_opt const char* tag);

HKEAPI void HKAPICC
HkCursorRangeFree(
	__in struct HkCursorRange* cursor);

HKEAPI __checkReturn HRESULT HKAPICC
HkCursorRangeGetFirst(
	__in struct HkCursorRange* cursor,
	__in struct HkTransaction* tx,
	__in const struct HkSearchKey* startKey,
	__in const struct HkSearchKey* endKey,
	__in_opt const struct HkParam* params,
	__in TxIsoLevel isoLevel,
	__out const struct HkRow** row);

HKEAPI __checkReturn __success(return == S_OK) HRESULT HKAPICC
HkCursorRangeGetNext(
	__in struct HkCursorRange* cursor,
	__out_opt struct HkErrorObject* error,
	__out const struct HkRow** row);

HKEAPI __checkReturn HRESULT HKAPICC
HkSequenceObjGetNext64(
	__in struct HkTransaction* tx,
	__in struct HkSequenceObj* seqObj,
	__out __int64* value64);

HKEAPI __checkReturn HRESULT HKAPICC
HkSequenceObjGetNext128(
	__in struct HkTransaction* tx,
	__in struct HkSequenceObj* seqObj,
	__out struct HkInt128* value128);
