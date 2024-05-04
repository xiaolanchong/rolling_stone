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

#include "board.h"
unsigned char BitNumber[256];
  signed char BitFirst[256];

void InitBS() {
   int  i;
   char j;

   for ( i=0 ; i<256 ; i++ ) {
      BitNumber[i] = 0;
      BitFirst[i] = -1;
      for ( j=0 ; j<8 ; j++ )
          if ( i & (1<<j) ) BitNumber[i]++;
      for ( j=0 ; j<8 ; j++ )
          if ( i & (1<<j) ) {
	      BitFirst[i] = j;
	      break;
      }
   }                         
}

BOOLTYPE  Is0BS(const BitString a) {
	int i; for (i=0; i<NUMBERINTS; i++) if (a[i]!=0) return(0);
	return(1);
}

BOOLTYPE Isnt0BS(const BitString a ) {
  int i;

  for( i = 0; i < NUMBERINTS; i++ )
    if( a[ i ] )
      return 1;
  return 0;
}

int NumberBitsInt(int a) {
	int i,r=0;
	unsigned char *c = (unsigned char *) &a;
	for (i=0; i<sizeof(int); i++) r+=BitNumber[c[i]];
	return(r);
}

int NumberBitsBS(const BitString a) {
	int i,r=0;
	unsigned char *c = (unsigned char *) a;
	for (i=0; i<sizeof(BitString); i++) r+=BitNumber[c[i]];
	return(r);
}

void  PrintBS(const BitString a) {
	int i;
	Mprintf( 0, "-%i-\n",NUMBERINTS);fflush(stdout);
	PRINTBASETYPE(a[NUMBERINTS-1]);
	for (i=NUMBERINTS-2; i>=0; i--) {
		Mprintf( 0, "."); PRINTBASETYPE(a[i]);
	}
	Mprintf( 0, "\n");
}

void PrintBitMaze(const BitString a) {
	int x,y;

	for (y = YSIZE-1; y>=0; y--) {
		for (x = 0; x<XSIZE; x++) {
			if (IsBitSetBS(a,XY2ID(x,y))) Mprintf( 0, "*");
			else Mprintf( 0, ".");
		}
		Mprintf( 0, "\n");
	}
	fflush(stdout);
}

PHYSID FindAnySet(const BitString a)
{
	int x,y;

	for (y = YSIZE-1; y>=0; y--) {
		for (x = 0; x<XSIZE; x++) {
			if (IsBitSetBS(a,XY2ID(x,y))) return(XY2ID(x,y));
		}
	}
	return(0);
}

static char _foobits[ 256 ] = {
0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

int FindFirstSet( const BitString bs )
{
  int i, t;

  for( i = 0; i < NUMBERINTS; i++ )
    if( bs[ i ] ) {
      t = bs[ i ];
      i = i * sizeof( BASETYPE ) * 8;
      while( !( t & 255 ) ) {
	i += 8;
	t = t >> 8;
      }
      i += _foobits[ t & 255 ];
      return i;
    }
  return -1;
}


BOOLTYPE  EqualBS(const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) if (a[i] != b[i]) return(0);
	return(1);
}

BOOLTYPE  AllBitsSetBS(const BitString x, const BitString bits) {
  int i;

  for( i = 0; i < NUMBERINTS; i++ )
    if( ~x[ i ] & bits[ i ] )
      return 0;
  return 1;
}

void UnsetBS(BitString x, const BitString bits) {
	int i; for (i=0; i<NUMBERINTS; i++) x[i] &= ~bits[i];
}

void BitAndNotBS(BitString r, const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = a[i] & ~b[i];
}

void BitAndNotButOrBS(BitString r, const BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = a[i] & (~b[i] | c[i]);
}

void BitAndAndBS(BitString r, const BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = a[i] & b[i] & c[i];
}

void BitAndAndNotBS(BitString r, const BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = a[i] & b[i] & ~c[i];
}

void BitAndBS(BitString r, const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = a[i] & b[i];
}

void BitNandBS(BitString r, const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = ~(a[i] & b[i]);
}

void BitOrBS(BitString r, const  BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = a[i] | b[i];
}

void BitOrAndEqBS(BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] |= b[i] & c[i];
}

void BitNorBS(BitString r, const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = ~(a[i] | b[i]);
}

void BitNotBS(BitString r, const BitString a) {
        int i; for (i=0; i<NUMBERINTS; i++) r[i] = ~a[i];
}

/******/

void BitAndEqBS(BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] &= b[i];
}

void BitNandEqBS(BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] = ~(a[i] & b[i]);
}

void BitOrEqBS(BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] |= b[i];
}

void BitNorEqBS(BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] = ~(a[i] | b[i]);
}

void BitAndNotEqBS(BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] &= ~b[i];
}

void BitAndNotButOrEqBS(BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) a[i] &= (~b[i] | c[i]);
}


void BitNotAndNotBS(BitString r, const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) r[i] = ~(a[i] | b[i]);
}

void BitNotAndNotAndNotBS(BitString r, const BitString a, const BitString b,
	const BitString c) {
	int i;

	for (i = 0; i < NUMBERINTS; i++) r[i] = ~( a[i] | b[i] | c[i] );
}

void BitAndNotAndNotBS(BitString r, const BitString a, const BitString b, const BitString c) {
	int i;

	for (i = 0; i < NUMBERINTS; i++) r[i] = a[i] & ~b[i] & ~c[i];
}

/******/


BOOLTYPE  LogAndBS (const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) if ((a[i] & b[i]) != 0) return(1);
	return(0);
}
BOOLTYPE  LogAndNotBS(const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) if ((a[i] & ~b[i]) != 0) return(1);
	return(0);
}
BOOLTYPE  LogAndAndNotBS(const BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) if (((a[i] & b[i]) & ~c[i]) != 0)
		return(1);
	return(0);
}
int  LogAndNotAndNotBS(const BitString a, const BitString b, const BitString c) {
	int i; for (i=0; i<NUMBERINTS; i++) if ((a[i] & ~b[i] & ~c[i]) != 0)
		return(1);
	return(0);
}
BOOLTYPE  LogOrBS  (const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) if ((a[i] | b[i]) != 0) return(1);
	return(0);
}
BOOLTYPE  LogOrNotBS (const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) if ((a[i] | ~b[i]) != 0) return(1);
	return(0);
}
BOOLTYPE  LogNorAndNotBS (const BitString r, const BitString a, const BitString b) {
	int i; for (i=0; i<NUMBERINTS; i++) if (((r[i]^a[i])&~b[i])!=0) return(1);
	return(0);
}

