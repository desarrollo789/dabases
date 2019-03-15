//*********************************************************************
// Copyright (c) Microsoft Corporation.
//*********************************************************************















#pragma once

#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define HRESULT_FACILITY(hr) (((hr) >> 16) & 0x1fff)

#if defined(__cplusplus)
	
	
	#define HKGAPI extern "C" extern
#else
	#define HKGAPI
#endif

struct IHkStatementPerf;



HKGAPI void
hkassert_fail(
	unsigned int, 
	const char* exp, 
	const char* file, 
	int line, 
	const char* fmt, ...);




#define utassert_fail hkassert_fail




#ifndef DBG_ASSERT
	#ifdef DEBUG
		#define DBG_ASSERT(exp) ((exp) ? 0 : hkassert_fail(0 , #exp, __FILE__, __LINE__, 0))
	#else
		#define DBG_ASSERT(exp)
	#endif
#endif

#ifndef RTL_ASSERT
	#define RTL_ASSERT(exp) ((exp) ? 0 : hkassert_fail(1 , #exp, __FILE__, __LINE__, 0))
#endif

HKGAPI __forceinline __checkReturn __int64
Min(__int64 a, __int64 b)
{
	return (a < b) ? a : b;
}

HKGAPI __forceinline __checkReturn __int64
Max(__int64 a, __int64 b)
{
	return (a > b) ? a : b;
}

HKGAPI __forceinline __checkReturn long
ConvertCompareKeysResult(__int64 result64);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_int128(
	struct HkInt128 key1,
	struct HkInt128 key2);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_int128_fast(
	struct HkInt128 key1,
	struct HkInt128 key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_int128(
	struct HkInt128 key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_int64(
	__int64 key1,
	__int64 key2);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_int64_fast(
	__int64 key1,
	__int64 key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_int64(
	__int64 key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_int(
	int key1,
	int key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_int(
	int key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_short(
	short key1,
	short key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_short(
	short key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_uchar(
	unsigned char key1,
	unsigned char key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_uchar(
	unsigned char key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_double(
	double key1,
	double key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_double(
	double key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline void
IncrementKey_double(
	double source,
	__out double* target);

HKGAPI __forceinline void
DecrementKey_double(
	double source,
	__out double* target);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_float(
	float key1,
	float key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_float(
	float key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline void
IncrementKey_float(
	float source,
	__out float* target);

HKGAPI __forceinline void
DecrementKey_float(
	float source,
	__out float* target);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_Strings(
	unsigned char const* key1,
	unsigned short key1Len,
	unsigned char const* key2,
	unsigned short key2Len);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_Bin(
	__in_bcount(key1Len) unsigned char const* key1,
	unsigned short key1Len,
	__in_bcount(key2Len) unsigned char const* key2,
	unsigned short key2Len);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_WideStrings(
	__in_bcount(key1Len) unsigned char const* key1,
	unsigned short key1Len,
	__in_bcount(key2Len) unsigned char const* key2,
	unsigned short key2Len);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_Strings(
	unsigned char const* key,
	unsigned short keyLen,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_WideStrings(
	__in_bcount(keyLen) unsigned char const* key,
	unsigned short keyLen,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_Bin(
	__in_bcount(keyLen) unsigned char const* key,
	unsigned short keyLen,
	 __inout unsigned long* hashState);

HKGAPI __forceinline __checkReturn __int64
CompareKeys_guid(
	struct HkSixteenByteData key1,
	struct HkSixteenByteData key2);

HKGAPI __forceinline __checkReturn  unsigned long
ComputeHash_guid(
	struct HkSixteenByteData key,
	 __inout unsigned long* hashState);

HKGAPI __forceinline void
IncrementKey_guid(
	struct HkSixteenByteData source,
	__out struct HkSixteenByteData* target);

HKGAPI __forceinline void
DecrementKey_guid(
	struct HkSixteenByteData source,
	__out struct HkSixteenByteData* target);

HKGAPI __forceinline __checkReturn HRESULT
RowSerialize(
	__in_bcount(serializeSize) struct HkRow const* row,
	__in unsigned short serializeSize,
	__out_bcount_part(bufferSize, serializeSize) unsigned char* buffer,
	__in unsigned short bufferSize,
	__in unsigned short* copySize);

HKGAPI __forceinline __checkReturn HRESULT
RowDeserialize(
	__in struct HkTransaction* tx, 
	__in struct HkTable* table, 
	__in_bcount(datasize) unsigned char const* data, 
	__in unsigned short datasize, 
	__in unsigned short minRowSize,
	__in unsigned short maxRowSize,
	__out struct HkRow** row);

HKGAPI __forceinline void
SetFloatingPointControl();
HKGAPI __forceinline void
SetFloatingPointControlTruncate();
HKGAPI __forceinline void
SetFloatingPointControlExact();

HKGAPI __checkReturn int
ExceptionFilter(unsigned int code, __out HRESULT* hr);
HKGAPI __checkReturn int
ExceptionFilterExactFloat(unsigned int code, double val, __out float* dest, __out HRESULT* hr);
HKGAPI __checkReturn int
ExceptionFilterExactFloatToInt(unsigned int code, double val, __out __int64* dest, __out HRESULT* hr);

HKGAPI __forceinline __checkReturn unsigned char
Fits128Into64(struct HkInt128 const* value);
HKGAPI __forceinline __checkReturn unsigned char
Fits256Into64(struct HkInt256 const* value);
HKGAPI __forceinline __checkReturn unsigned char
Fits256Into128(struct HkInt256 const* value);
HKGAPI __forceinline void
Convert128To64(struct HkInt128 const* value, __out __int64* res);
HKGAPI __forceinline void
Convert256To64(struct HkInt256 const* value, __out __int64* res);
HKGAPI __forceinline void
Convert256To128(struct HkInt256 const* value, __out struct HkInt128* res);
HKGAPI __forceinline void
Convert64To128(__int64 value, __out struct HkInt128* res);

HKGAPI  __forceinline void
Convert128ToDouble(struct HkInt128 const* value, __out double* res);
HKGAPI  __forceinline void
Convert128ToFloat(struct HkInt128 const* value, __out float* res);
HKGAPI __forceinline void
Convert64ToDoubleWithScale64(__int64 value, unsigned __int64 scale, double scaleRecip, __out double* res);
HKGAPI __forceinline void
Convert128ToDoubleWithScale64(struct HkInt128 const* value, unsigned __int64 scale, double scaleRecip, __out double* res);
HKGAPI __forceinline void
Convert128ToDoubleWithScale128(struct HkInt128 const* value, struct HkInt128 const* scale, double scaleRecip, __out double* res);
HKGAPI  __forceinline void
Convert64ToFloatWithScale64(__int64 value, unsigned __int64 scale, double scaleRecip, __out float* res);
HKGAPI  __forceinline void
Convert128ToFloatWithScale64(struct HkInt128 const* value, unsigned __int64 scale, double scaleRecip, __out float* res);
HKGAPI  __forceinline void
Convert128ToFloatWithScale128(struct HkInt128 const* value, struct HkInt128 const* scale, double scaleRecip, __out float* res);

HKGAPI __forceinline void
ConvertDoubleTo64(double value, __out __int64* res);
HKGAPI __forceinline void
ConvertDoubleTo128(double value, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
ConvertDoubleTo64WithScale64(double value, __int64 scale, __out __int64* res);
HKGAPI __forceinline __checkReturn HRESULT
ConvertDoubleTo128WithScale64(double value, __int64 scale, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
ConvertDoubleTo128WithScale128(double value, struct HkInt128 const* scale, __out struct HkInt128* res);

HKGAPI __forceinline void
ShiftRight256To256(struct HkInt256 const* value, unsigned char shift, __out struct HkInt256* result);

HKGAPI __forceinline __checkReturn bool
Equal128And64(struct HkInt128 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
Equal64And128(__int64 a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
Equal128And128(struct HkInt128 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
Equal256And64(struct HkInt256 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
Equal64And256(__int64 a, struct HkInt256 const* b);
HKGAPI __forceinline __checkReturn bool
Equal256And128(struct HkInt256 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
Equal128And256(struct HkInt128 const* a, struct HkInt256 const* b);

HKGAPI __forceinline __checkReturn bool
NotEqual128And64(struct HkInt128 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
NotEqual64And128(__int64 a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
NotEqual128And128(struct HkInt128 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
NotEqual256And64(struct HkInt256 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
NotEqual64And256(__int64 a, struct HkInt256 const* b);
HKGAPI __forceinline __checkReturn bool
NotEqual256And128(struct HkInt256 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
NotEqual128And256(struct HkInt128 const* a, struct HkInt256 const* b);

HKGAPI __forceinline __checkReturn bool
LessThan128And64(struct HkInt128 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
LessThan64And128(__int64 a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
LessThan128And128(struct HkInt128 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
LessThan256And64(struct HkInt256 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
LessThan64And256(__int64 a, struct HkInt256 const* b);
HKGAPI __forceinline __checkReturn bool
LessThan256And128(struct HkInt256 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
LessThan128And256(struct HkInt128 const* a, struct HkInt256 const* b);

HKGAPI __forceinline __checkReturn bool
GreaterThan128And64(struct HkInt128 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
GreaterThan64And128(__int64 a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThan128And128(struct HkInt128 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThan256And64(struct HkInt256 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
GreaterThan64And256(__int64 a, struct HkInt256 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThan256And128(struct HkInt256 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThan128And256(struct HkInt128 const* a, struct HkInt256 const* b);

HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo128And64(struct HkInt128 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo64And128(__int64 a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo128And128(struct HkInt128 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo256And64(struct HkInt256 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo64And256(__int64 a, struct HkInt256 const* b);
HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo256And128(struct HkInt256 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
LessThanOrEqualTo128And256(struct HkInt128 const* a, struct HkInt256 const* b);

HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo128And64(struct HkInt128 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo64And128(__int64 a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo128And128(struct HkInt128 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo256And64(struct HkInt256 const* a, __int64 b);
HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo64And256(__int64 a, struct HkInt256 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo256And128(struct HkInt256 const* a, struct HkInt128 const* b);
HKGAPI __forceinline __checkReturn bool
GreaterThanOrEqualTo128And256(struct HkInt128 const* a, struct HkInt256 const* b);

HKGAPI __forceinline __checkReturn bool
IsNeg128(struct HkInt128 const* a);
HKGAPI __forceinline __checkReturn bool
IsZero128(struct HkInt128 const* a);
HKGAPI __forceinline __checkReturn bool
IsNeg256(struct HkInt256 const* a);

HKGAPI __forceinline __checkReturn HRESULT
Negate64(__int64 input, __out __int64* res);
HKGAPI __forceinline void
Negate128Unsafe(struct HkInt128 const* input, __out struct HkInt128* res);

HKGAPI __forceinline void
Add64And64(__int64 a, __int64 b, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
Add128And64(struct HkInt128 const* a, __int64 b, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
Add64And128(__int64 a, struct HkInt128 const* b, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
Add128And128(struct HkInt128 const* a, struct HkInt128 const* b, __out struct HkInt128* res);
HKGAPI __forceinline void 
Add256And64Unsafe(struct HkInt256 const* a, __int64 b, __out struct HkInt256* res);
HKGAPI __forceinline void 
Add256And128Unsafe(struct HkInt256 const* a, struct HkInt128 const* b, __out struct HkInt256* res);
HKGAPI __forceinline void 
Add256And192Unsafe(struct HkInt256 const* a, struct HkInt192 const* b, __out struct HkInt256* res);

HKGAPI __forceinline __checkReturn HRESULT
Subtract128And64(struct HkInt128 const* a, __int64 b, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
Subtract64And128(__int64 a, struct HkInt128 const* b, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
Subtract128And128(struct HkInt128 const* a, struct HkInt128 const* b, __out struct HkInt128* res);

HKGAPI __forceinline __checkReturn HRESULT
Multiply64By64Res64(__int64 a, __int64 b, __out __int64* res);
HKGAPI __forceinline void
Multiply64By64(__int64 a, __int64 b, struct HkInt128* res);
HKGAPI __forceinline void
Multiply128By64(struct HkInt128 const* a, __int64 b, __out struct HkInt256* res);
HKGAPI __forceinline void
Multiply64By128(__int64 a, struct HkInt128 const* b, __out struct HkInt256* res);
HKGAPI __forceinline void
Multiply128By128(struct HkInt128 const* a, struct HkInt128 const* b, __out struct HkInt256* res);
HKGAPI __forceinline __checkReturn HRESULT
Multiply128By192(struct HkInt128 const* a, struct HkInt192 const* b, __out struct HkInt256* res);
HKGAPI __forceinline void
Multiply64By192(__int64 a, struct HkInt192 const* b, __out struct HkInt256* res);


HKGAPI __forceinline __checkReturn HRESULT
Divide64By64(__int64 a, __int64 b, __out __int64* result);
HKGAPI __forceinline void
Divide128By64Unsafe(struct HkInt128 const* a, __int64 b, __out struct HkInt128* res);
HKGAPI __forceinline void
Divide128By128Unsafe(struct HkInt128 const* a, struct HkInt128 const* b, __out struct HkInt128* res);
HKGAPI __forceinline __checkReturn HRESULT
Divide256By64(struct HkInt256 const* a, __int64 b, __out struct HkInt128* res);
HKGAPI __checkReturn __checkReturn HRESULT
Divide256By128(struct HkInt256 const* a, struct HkInt128 const* b, __out struct HkInt128* res);

HKGAPI __forceinline __checkReturn HRESULT
Modulo64By64(__int64 a, __int64 b, __out __int64* res, __out __int64* rem);
HKGAPI __forceinline void
Modulo64By128Unsafe(__int64 a, struct HkInt128 const* b, __out __int64* rem);
HKGAPI __forceinline void
Modulo128By64Unsafe(struct HkInt128 const* a, __int64 b, __out __int64* rem);
HKGAPI __forceinline void
Modulo128By128Unsafe(struct HkInt128 const* a, struct HkInt128 const* b, __out struct HkInt128* rem);

HKGAPI __forceinline __checkReturn HRESULT
Divide64By64Rec(__int64 a, unsigned __int64 b, unsigned __int64 x, __out __int64* res, unsigned char exact);
HKGAPI __forceinline void
Divide64By64RecTruncDown(__int64 a, unsigned __int64 b, unsigned __int64 x, __out __int64* res);
HKGAPI __forceinline void
Divide128By64RecUnsafeTruncDown(struct HkInt128 const* a, unsigned __int64 b, struct HkInt128 const* x, __out __int64* res);
HKGAPI __forceinline void
Divide128By64RecTruncDown(struct HkInt128 const* a, unsigned __int64 b, struct HkInt128 const* x, __out struct HkInt128* res);
HKGAPI __forceinline void
Divide64By64RecTruncDownRem(__int64 a, unsigned __int64 b, unsigned __int64 x, __out __int64* res, __out __int64* rem);
HKGAPI __forceinline void
Divide128By64RecUnsafeTruncDownRem(struct HkInt128 const* a, unsigned __int64 b, struct HkInt128 const* x, __out __int64* res, __out __int64* rem);
HKGAPI __forceinline __checkReturn HRESULT
Divide128By64RecUnsafe(struct HkInt128 const* a, unsigned __int64 b, struct HkInt128 const* x, __out __int64* res, unsigned char exact);
HKGAPI __forceinline __checkReturn HRESULT
Divide128By64Rec(struct HkInt128 const* a, unsigned __int64 b, struct HkInt128 const* x, __out struct HkInt128* res, unsigned char exact);
HKGAPI __forceinline __checkReturn HRESULT
Divide128By128RecUnsafe(struct HkInt128 const* a, struct HkInt128 const* b, unsigned __int64 x, __out __int64* res, unsigned char exact);
HKGAPI __forceinline __checkReturn HRESULT
Divide256By64Rec(struct HkInt256 const* a, unsigned __int64 b, struct HkInt192 const* x, __out struct HkInt128* res, unsigned char exact);
HKGAPI __forceinline __checkReturn HRESULT
Divide256By128Rec(struct HkInt256 const* a, struct HkInt128 const* b, struct HkInt192 const* x, __out struct HkInt128* res, unsigned char exact);

HKGAPI __forceinline __checkReturn double
Atn2(double x, double y);
HKGAPI __forceinline __checkReturn double
Degrees(double x);
HKGAPI __forceinline __checkReturn double
Radians(double x);
HKGAPI __forceinline __checkReturn double
Square(double x);

HKGAPI __forceinline __checkReturn HRESULT
YieldCheck(__in struct HkProcContext* hkcontext, unsigned int yc, unsigned long lineNo);

HKGAPI __forceinline __checkReturn unsigned short
RTrimBinary(__in_ecount(length) const unsigned char* value, unsigned short length);
HKGAPI __forceinline __checkReturn unsigned short
RTrimChar(__in_ecount(length) const unsigned char* value, unsigned short length);
HKGAPI __forceinline __checkReturn unsigned short
RTrimWChar(__in_ecount(length) const unsigned char* value, unsigned short length);
HKGAPI __forceinline __checkReturn unsigned short
LTrimChar(__in_ecount(length) const unsigned char* value, unsigned short length);
HKGAPI __forceinline __checkReturn unsigned short
LTrimWChar(__in_ecount(length) const unsigned char* value, unsigned short length);

HKGAPI __checkReturn HRESULT
ConvCharToBit(
	__in_bcount(strLength) const unsigned char*	str,
	__in unsigned short							strLength,
	__out __int64*								intValue);

HKGAPI __checkReturn HRESULT
ConvWCharToBit(
	__in_bcount(strLength) const unsigned char*	str,
	__in unsigned short							strLength,
	__out __int64*								intValue);

HKGAPI __checkReturn HRESULT
ConvCharToInt(
	__in_bcount(strLength) const unsigned char*	str,
	__in unsigned short							strLength,
	__out __int64*								intValue);

HKGAPI __checkReturn HRESULT
ConvWCharToInt(
	__in_bcount(strLength) const unsigned char*	str,
	__in unsigned short							strLength,
	__out __int64*								intValue);

HKGAPI __checkReturn HRESULT
ConvCharToLargeNumeric(
	__in_bcount(strLength)const unsigned char*  str,
	__in unsigned short							strLength,
	__in unsigned short							prec,
	__in unsigned short							scale,			
	__out struct HkInt128*						intValue);

HKGAPI __checkReturn HRESULT
ConvWCharToLargeNumeric(
	__in_bcount(strLength)const unsigned char*  str,
	__in unsigned short							strLength,
	__in unsigned short							prec,
	__in unsigned short							scale,			
	__out struct HkInt128*						intValue);

HKGAPI __checkReturn HRESULT
ConvCharToNumeric(
	__in_bcount(strLength)const unsigned char*  str,
	__in unsigned short							strLength,
	__in unsigned short							prec,
	__in unsigned short							scale,			
	__out __int64*								intValue);

HKGAPI __checkReturn HRESULT
ConvWCharToNumeric(
	__in_bcount(strLength)const unsigned char*  str,
	__in unsigned short							strLength,
	__in unsigned short							prec,
	__in unsigned short							scale,			
	__out __int64*								intValue);

HKGAPI __forceinline void
hkmemcpy_s(
	__out_bcount_part(destSize, srcSize) void* dest,
	size_t destSize,
	__in_bcount(srcSize) const void* src,
	size_t srcSize);

HKGAPI __forceinline void
hkmemcpy_s_ex(
	__deref_inout_bcount_part(*destSize, srcSize) void** dest,
	__inout size_t* destSize,
	__in_bcount(srcSize) const void* src,
	size_t srcSize);

#if defined(__cplusplus)
template <size_t _Size, typename _DstType>
__forceinline void
hkmemcpy_s(_DstType (&dest)[_Size], __in_bcount(srcSize) const void* src, size_t srcSize)
{
	return hkmemcpy_s(dest, _Size * sizeof(_DstType), src, srcSize);
}
#endif

HKGAPI __forceinline void
hkwmemset(__out_bcount(_N) void* _S, wchar_t _C, size_t _N);

HKGAPI __forceinline void
hkwmemset_s_ex(
	__deref_inout_bcount_part(*bufferLength, _N * sizeof(wchar_t)) void** bufferPtr, 
	__inout size_t* bufferLength, 
	wchar_t _C, 
	size_t _N);

HKGAPI __forceinline void
hkmemset_s_ex(
	__deref_inout_bcount_part(bufferLength, _N) void** bufferPtr, 
	__inout size_t* bufferLength, 
	char _C, 
	size_t _N);

HKGAPI __forceinline void
ReportStmtStarted(__inout_opt struct IHkStatementPerf* stmtPerf);

HKGAPI __forceinline void
ReportStmtEnded(__inout_opt struct IHkStatementPerf* stmtPerf, unsigned long qindex);



HKGAPI __forceinline __checkReturn void*
GetSortBufElem(__in void* context, long dirPageIndex);



HKGAPI __forceinline __checkReturn void*
GetTopSortBufElem(__in void* context, long index);



HKGAPI __forceinline __checkReturn struct HkCompareContext*
FetchCompareContext(__in void* context);

