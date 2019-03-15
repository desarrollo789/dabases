//*********************************************************************
// Copyright (c) Microsoft Corporation.
//*********************************************************************















#pragma once



struct HkOffsetInfo
{
	unsigned short const DataOffset;			
	unsigned short const NullOffset;			
	unsigned char const NullBitMask;			
};



struct HkSearchKeyColsInfo
{
	
	
	
	
	
	unsigned short FixedSize;

	
	
	struct HkOffsetInfo const* Offsets;

	
	
	
	
	unsigned short ColCountOffset;

	
	
	
	
	unsigned short EpsilonOffset;
};



struct HkFlatKeyColsInfo
{
	unsigned short FixedSize;					
	struct HkOffsetInfo const* Offsets;			
};



struct HkColsInfo
{
	
	
	unsigned short FixedSize;								
	struct HkOffsetInfo const* Offsets;						
	struct HkSearchKeyColsInfo const* SearchKeyColsInfo;	
	struct HkFlatKeyColsInfo const* FlatKeyColsInfo;		
};



struct HkOutputMetadata
{
	int							rsId;
	unsigned long				currentLineNumber;
	unsigned short				columnCount;
	const unsigned char*		columnNameLens;
	const wchar_t* const*		columnNames;
	const unsigned char*		columnTypes;
	const unsigned char*		columnNullables;
	const unsigned char*		columnPrecisions;
	const unsigned char*		columnScales;
	const unsigned short*		columnMaxLengths;
	const unsigned long*		columnCollations;	
	const unsigned char*		columnStatusBits;
	unsigned short				orderByCount;
	const unsigned short*		orderByColumns;
	const unsigned char* const*	tdsBufs;
	const unsigned short*		tdsBufLengths;
	unsigned short				clientCount;
	const unsigned short*		clients;
};

struct HkTable;
struct HkTransaction;
struct HkTableMD;
struct HkTable;
struct HkCallbackContext;
struct IHkStatementPerf;

#define HKVALUEBASE_MEMBERS \
	__int64				SignedIntData;	\
	unsigned __int64	UnsignedIntData;	\
	float				FloatData;			\
	double				DoubleData;


struct HkSixteenByteData
{	
	unsigned char data[16];
};

struct HkPal
{
	unsigned char* Pointer;
	unsigned short Length;
};

union HkValue
{
	
	HKVALUEBASE_MEMBERS

	
	struct HkSixteenByteData SixteenByteData;

	
	struct HkInt128 Int128Data;

	
	struct HkPal PalData;
};

struct HkProcContext
{
	struct HkDatabase* Database;
	struct HkTransaction* Transaction;
	struct HkTransaction* TableVarTransaction;
	struct HkErrorObject* ErrorObject;
	unsigned char* DeepDataBuffer;
	union HkValue* OutputBuffer;
	unsigned char* OutputNulls;
	unsigned long OutputBufferSize;
	struct HkTable** TableVars;
	struct IHkStatementPerf* StmtPerf;
	unsigned long IsSecondary;
};


typedef __checkReturn HRESULT
( __stdcall *ProcEntryPoint)(
	__in struct HkProcContext* context,
	__in union HkValue* valueArray,
	__in unsigned char* nullArray);

struct HkQueryStmtInfo
{
	int					Offset;
	int					OffsetEnd;
	unsigned long		LineNum;
};

struct HkProcInfo
{
	ProcEntryPoint			ProcFn;
	unsigned long			BufferSpaceNeeded;
	unsigned short			MaxOutputColumns;
	unsigned short			MaxOrderByColumns;
	unsigned long			TableVarsCount;
	unsigned long			TableParamsCount;
	unsigned long const*	TableVarsMDOffsets;
	unsigned long			TableTypeCount;
	unsigned int*			TableTypeIds;
	struct HkTableMD const**	TableTypeMDs;
	unsigned char 	SortBufferNeeded;
	unsigned char 	TopSortBufferNeeded;
	unsigned char			ProcIsolationLevel;
	unsigned char 	DelayedDurability;
	unsigned int			CountTablesStabilize;
	struct HkRootTableRow ** 	TableRowsStabilize;
	unsigned long			ProcQueryStmtCount;
	struct HkQueryStmtInfo*	ProcQueryStmtInfo;
};

struct HkCompareContext
{
	struct HkCallbackContext* Context;
	const void* Params;
};

struct HkSortContext
{
	struct HkCompareContext* CmpContext;
	void* SortBuffer;
	long* PqLocation;
	unsigned char DirectoryPageAllocated;
	unsigned long PagesAllocated;
	unsigned long MaxRows;
	unsigned long CurrentRowCount;
	size_t SortBufElemSize;
	long PageIndex;
	int (__cdecl *SortCompare)(void *, const void *, const void *);
	HRESULT (__cdecl *PqCompare)(void *, long, long, __int64*);
};

struct HkTopSortContext
{
	struct HkCompareContext* CmpContext;
	void* SortBuffer;
	long* PqLocation;
	unsigned long TopNValue;
	size_t SortBufElemSize;
};

#if !defined(HKRAPI)
	#if defined(HKRUNTIME_BUILD)
		#define HKRAPI extern "C" __declspec(dllexport)
	#else
		#if defined(__cplusplus)
			#define HKRAPI extern "C" __declspec(dllimport)
		#else
			#define HKRAPI __declspec(dllimport)
		#endif
	#endif
#endif





#if !defined(HKAPICC)
	#if defined(_X86_)
		#define HKAPICC __cdecl
	#else
		#define HKAPICC
	#endif
#endif

HKRAPI __checkReturn HRESULT HKAPICC
HkRtWaitForDependencies(__in struct HkProcContext *hkcontext, unsigned long currentLineNo, HRESULT hrCurrent);

HKRAPI __checkReturn HRESULT HKAPICC
HkRtWaitForDependenciesEx(__in struct HkProcContext *hkcontext, unsigned long currentLineNo, HRESULT hrCurrent);

