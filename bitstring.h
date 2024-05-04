/* 
** Copyright (C) 1999 by Andreas Junghanns.
**
** Permission to use, copy, modify, and distribute this software and its
** documentation for any purpose and without fee is hereby granted, provided
** that the above copyright notice appear in all copies and that both that
** copyright notice and this permission notice appear in supporting
** documentation.  This software is provided "as is" without express or
** implied warranty.
*/ 

// bit count of the number
extern unsigned char BitNumber[256];
// 1st bit 1 position, -1 if none
extern   signed char BitFirst[256];
/*
#define BASETYPE   int
#define PRINTBASETYPE(a) Mprintf( 0, "%08x",a);

#define BASETYPE   long long
#define PRINTBASETYPE(a) Mprintf( 0, "%016x",a);
*/

void InitBS();
BOOLTYPE  Is0BS(const BitString a);
BOOLTYPE  Isnt0BS(const BitString a);
PHYSID FindAnySet(const BitString a);
int FindFirstSet(const BitString bs );
int  NumberBitsInt(const int a);
int  NumberBitsBS(const BitString a);
void PrintBS(const BitString a);
void PrintBitMaze(const BitString a);
BOOLTYPE  EqualBS(const BitString a, const BitString b);
BOOLTYPE  AllBitsSetBS(const BitString x, const BitString bits);
void UnsetBS(BitString x, const BitString bits);

void BitAndNotBS(BitString r, const BitString a, const BitString b);
void BitAndNotButOrBS(BitString r, const BitString a, const BitString b, const BitString c);
void BitAndBS (BitString r, const BitString a, const BitString b);
void BitAndAndBS (BitString r, const BitString a, const BitString b, const BitString c);
void BitAndAndNotBS (BitString r, const BitString a, const BitString b, const BitString c);
void BitNandBS(BitString r, const BitString a, const BitString b);
void BitOrBS  (BitString r, const BitString a, const BitString b);
void BitOrAndEqBS(BitString a, const BitString b, const BitString c);
void BitNorBS (BitString r, const BitString a, const BitString b);
void BitNotBS (BitString r, const BitString a);
void BitNotAndNotBS(BitString r, const BitString a, const BitString b);

void BitAndEqBS (BitString a, const BitString b);
void BitNandEqBS(BitString a, const BitString b);
void BitOrEqBS  (BitString a, const BitString b);
void BitNorEqBS (BitString a, const BitString b);
void BitAndNotButOrEqBS(BitString a, const BitString b, const BitString c);
void BitAndNotEqBS(BitString a, const BitString b);
void BitAndNotAndNotBS(BitString r, const BitString a, const BitString b, const BitString c);
void BitNotAndNotAndNotBS(BitString r, const BitString a, const BitString b, const BitString c);


BOOLTYPE  LogAndBS   (const BitString a, const BitString b);
BOOLTYPE  LogAndNotBS(const BitString a, const BitString b);
BOOLTYPE  LogAndNotAndNotBS(const BitString a, const BitString b, const BitString c);
BOOLTYPE  LogAndAndNotBS(const BitString a, const BitString b, const BitString c);
BOOLTYPE  LogOrBS    (const BitString a, const BitString b);
BOOLTYPE  LogOrNotBS (const BitString a, const BitString b);
BOOLTYPE  LogNorAndNotBS (const BitString r, const BitString a, const BitString b);

#define Set0BS(a) memset(a,0,sizeof(BitString))
#define Set1BS(a) memset(a,0xff,sizeof(BitString))
#define CopyBS(to,from) memcpy(to,from,sizeof(BitString))
#define UnsetBitBS(a,p) \
	   ((a)[(p)/(sizeof(BASETYPE)*8)] \
	&=~ (((BASETYPE)1)<<((p)%(sizeof(BASETYPE)*8))))
#define SetBitBS(a,p) \
	   ((a)[(p)/(sizeof(BASETYPE)*8)] \
	|= (((BASETYPE)1)<<((p)%(sizeof(BASETYPE)*8))))
#define IsBitSetBS(a,p) \
	   ( ((a)[(p)/(sizeof(BASETYPE)*8)] \
	    &  ((BASETYPE)1)<<((p)%(sizeof(BASETYPE)*8))))
