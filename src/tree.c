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
#include <sys/stat.h>

/* 
###########
###########
##.......##
##.OMKLN.##
##.IDCEF.##
##.H768A.##
##.G5149.##
##.J3$2B.##
##...@...##
##.......##
###########
########### */

const DLSUP DlSup2[MAX_SQUARES] = {
	{ 0,  1, NODIR,  1, 0, 0, 0, 0, NULL},		/* 1 */
	{ 1,  0, NODIR,  0, 0, 0, 0, 0, NULL},		/* 2 */
	{-1,  0, NODIR,  1, 0, 0, 0, 0, NULL},		/* 3 */
	{ 1,  1, SOUTH,  0, 0, 0, 0, 0, NULL},		/* 4 */
	{-1,  1, EAST,   1, 0, 0, 0, 0, NULL},		/* 5 */
	{ 0,  2, NODIR,  1, 0, 0, 0, 0, NULL},		/* 6 */
	{-1,  2, EAST,   0, 0, 0, 0, 0, NULL},		/* 7 */
	{ 1,  2, SOUTH,  1, 0, 0, 0, 0, NULL},		/* 8 */
	{ 2,  1, NODIR,  0, 0, 0, 0, 0, NULL},		/* 9 */
	{ 2,  2, SOUTH,  0, 0, 0, 0, 0, NULL},		/* A -10 */
	{ 2,  0, WEST,   0, 0, 0, 0, 0, NULL},		/* B -11 */
	{ 0,  3, NODIR,  0, 0, 0, 0, 0, NULL},		/* C -12 */
	{-1,  3, EAST,   0, 0, 0, 0, 0, NULL},		/* D -13 */
	{ 1,  3, SOUTH,  0, 0, 0, 0, 0, NULL},		/* E -14 */
	{ 2,  3, SOUTH,  0, 0, 0, 0, 0, NULL},		/* F -15 */
	{-2,  1, NODIR,  0, 0, 0, 0, 0, NULL},		/* G -16 */
	{-2,  2, EAST,   0, 0, 0, 0, 0, NULL},		/* H -17 */
	{-2,  3, EAST,   0, 0, 0, 0, 0, NULL},		/* I -18 */
	{-2,  0, NORTH,  1, 0, 0, 0, 0, NULL},		/* J -19 */
	{ 0,  4, NODIR,  1, 0, 0, 0, 0, NULL},		/* K -20 */
	{ 1,  4, SOUTH,  0, 0, 0, 0, 0, NULL},		/* L -21 */
	{-1,  4, EAST,   1, 0, 0, 0, 0, NULL},		/* M -22 */
	{ 2,  4, SOUTH,  0, 0, 0, 0, 0, NULL},		/* N -23 */
	{-2,  4, EAST,   1, 0, 0, 0, 0, NULL}		/* O -24 */
};

/* This was the maze and support structure in the first attempt
###########
###########
##.......##
##.MHFGI.##
##.LCABD.##
##.K5149.##
##.J3$28.##
##.N7@6E.##
##.......##
###########
########### 
*/

const DLSUP DlSup1[MAX_SQUARES] = {
	{ 0,  1, NODIR, 1, 0, 0, 0, 0, NULL},		/* 1 */
	{ 1,  0, NODIR, 0, 0, 0, 0, 0, NULL},		/* 2 */
	{-1,  0, NODIR, 1, 0, 0, 0, 0, NULL},		/* 3 */
	{ 1,  1, SOUTH, 0, 0, 0, 0, 0, NULL},		/* 4 */
	{-1,  1, EAST,  1, 0, 0, 0, 0, NULL},		/* 5 */
	{ 1, -1, NODIR, 0, 0, 0, 0, 0, NULL},		/* 6 */
	{-1, -1, NODIR, 1, 0, 0, 0, 0, NULL},		/* 7 */
	{ 2,  0, NODIR, 0, 0, 0, 0, 0, NULL},		/* 8 */
	{ 2,  1, SOUTH, 0, 0, 0, 0, 0, NULL},		/* 9 */
	{ 0,  2, NODIR, 0, 0, 0, 0, 0, NULL},		/* A -10 */
	{ 1,  2, SOUTH, 0, 0, 0, 0, 0, NULL},		/* B -11 */
	{-1,  2, EAST,  0, 0, 0, 0, 0, NULL},		/* C -12 */
	{ 2,  2, SOUTH, 0, 0, 0, 0, 0, NULL},		/* D -13 */
	{ 2, -1, WEST,  0, 0, 0, 0, 0, NULL},		/* E -14 */
	{ 0,  3, NODIR, 0, 0, 0, 0, 0, NULL},		/* F -15 */
	{ 1,  3, SOUTH, 0, 0, 0, 0, 0, NULL},		/* G -16 */
	{-1,  3, EAST,  0, 0, 0, 0, 0, NULL},		/* H -17 */
	{ 2,  3, SOUTH, 0, 0, 0, 0, 0, NULL},		/* I -18 */
	{-2,  0, NODIR, 0, 0, 0, 0, 0, NULL},		/* J -19 */
	{-2,  1, EAST,  0, 0, 0, 0, 0, NULL},		/* K -20 */
	{-2,  2, EAST,  0, 0, 0, 0, 0, NULL},		/* L -21 */
	{-2,  3, EAST,  0, 0, 0, 0, 0, NULL},		/* M -22 */
	{-2, -1, NORTH, 1, 0, 0, 0, 0, NULL}		/* N -23 */
};

static TREE  AllTrees[10];
static short NumberTrees = 0;

int InitTree( const DLSUP *sup ) {
	int id = NumberTrees++;
	AllTrees[id].Sup   = sup;
	AllTrees[id].CurrentLength = 0;
	AllTrees[id].Array = NULL;
	return id;
}

void LoadTree(int id, const char *filename) {
	TREE *t = &AllTrees[id];

	FILE *fp;
	struct stat buf;

	if ((fp = fopen(filename,"rb")) != NULL) {
		stat(filename, &buf);
		t->CurrentLength = buf.st_size/sizeof(DLENTRY);
		t->Array = (DLENTRY*)My_realloc(NULL,
					sizeof(DLENTRY)*(int)t->CurrentLength);
		t->CurrentLength = fread((DLENTRY*)t->Array,sizeof(DLENTRY),
				   	t->CurrentLength,fp);
		fclose(fp);
	} else {
		My_exit(1,"Pattern DB not found!\n");
	}
}

void LoadTrees(const char* sup1filename, const char* sup2filename)
{
	int id1 = InitTree(DlSup1);
	LoadTree(id1, sup1filename);
	int id2 = InitTree(DlSup2);
	LoadTree(id2, sup2filename);
}

BOOLTYPE DeadTree(const MAZE *maze, PHYSID pos, DIRECTION direction) {
	int    xofs, yofs; /* This is the multiplier to get the real offset */
	int    index,i,tree_id;
	PHYSID p;
	SQUARE square;
	const TREE  *t;

	
	if (maze->Phys[pos].goal >= 0) return(NO);
	for (tree_id = 0; 
	     tree_id < NumberTrees && tree_id < Options.dl_db; 
	     tree_id++) {
 	   t = &AllTrees[tree_id];
	   xofs = yofs = 0;
	   switch (direction) {
	   case NORTH: xofs =  YSIZE; yofs =  1; break;
	   case EAST:  xofs =  -1; yofs =  YSIZE; break;
	   case WEST:  xofs =   1; yofs = -YSIZE; break;
	   case SOUTH: xofs = -YSIZE; yofs = -1; break;
	   default: SR(Assert(0,"DeadTree: wrong direction: %i\n", direction));
		 return(NO);
	   }
	   index = 0;
	   i = 0;
	   do {
		p = pos + xofs*t->Sup[i].x_ofs + yofs*t->Sup[i].y_ofs;
		/* test if goal is in the pattern, if yes, no deadlock  or
		 * test the mirror pattern to see if that finds a deadlock */

		/* check for pattern overflow first */
		if (p<0 || p>XSIZE*YSIZE) 
			square = WallSquare;
		else {
			if (maze->Phys[p].goal >= 0) {
				goto TEST_MIRROR;
			}
			if (IsBitSetBS(maze->out,p)) square = WallSquare;
			else if (maze->PHYSstone[p]>=0) square = StoneSquare;
			else square = BlancSquare;
		}
		index = t->Array[index][square];
		i++;
	   } while (index>0);

	   if (index == 0) {
		return(YES);
	   }
TEST_MIRROR:
	   switch (direction) {
	   case NORTH: xofs = -YSIZE; yofs =   1; break;
	   case EAST:  xofs =   1; yofs =  YSIZE; break;
	   case WEST:  xofs =  -1; yofs = -YSIZE; break;
	   case SOUTH: xofs =  YSIZE; yofs =  -1; break;
	   }
	   index = 0;
	   i = 0;
	   do {
		p = pos + xofs*t->Sup[i].x_ofs + yofs*t->Sup[i].y_ofs;
		/* test if goal is in the pattern, if yes, no deadlock */

		/* check for pattern overflow first */
		if (p<0 || p>XSIZE*YSIZE) 
			square = WallSquare;
		else {
			if (maze->Phys[p].goal >= 0) {
				goto NEXT_PATTERN;
			}
			if (IsBitSetBS(maze->out,p)) square = WallSquare;
			else if (maze->PHYSstone[p]>=0) square = StoneSquare;
			else square = BlancSquare;
		}
		index = t->Array[index][square];
		i++;
	   } while (index>0);
	   if (index == 0) {
		return(YES);
	   }
NEXT_PATTERN:;
	}
	return(NO);
}
