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


extern MAZE *PenMaze;
extern MAZE *AreaMaze;
extern MAZE *InsertMaze;

int  PenMoveOrdering(int depth, int number_moves);
int  PenMoveSuspected(const MAZE *maze, const MOVE *last_move);
int  PenMiniConflict(int penalty, int minimize);

BOOLTYPE  PenIsGoalNode(int g);
int  ScanSearch(MAZE *maze);
int  PenMove(MAZE *maze, HASHENTRY *entry, MOVE *last_move, int treedepth,
	int targetpen);
int  GoodTested(MAZE *maze);
void PenDeactivateStones(MAZE *maze, BitString visible, int targetpen);
int  PenStartIda();
int  PenIda(int treedepth, int g);
int  PenMakeMove(MAZE *maze, MOVE *move, UNMOVE *ret, int targetpen);
int  PenUnMakeMove(MAZE *maze, UNMOVE *unmove, int targetpen);
int  PenLowerBound(MAZE *maze, int targetpen);
int  PenUpdateLowerBound(MAZE *maze, PHYSID pos, int targetpen);
PHYSID FindFarthestPosStone(MAZE *maze, const BitString squares, 
		      		  const BitString already_visible);

void MarkReachPos(const MAZE *maze, BitString reach, PHYSID manpos, BOOLTYPE clear);
int  FindFringeStones( const MAZE *maze, BitString fs,
		      BitString no_reach, PHYSID move_to );
int  WhichStones(const MAZE *maze, BitString fs, BitString no_reach, BOOLTYPE clear);
BOOLTYPE  AddMoreStones( const MAZE *maze, BitString fs, BitString no_reach);
/* Return True (YES) if targetpen was achieved */
BOOLTYPE  AreaMove(MAZE *maze, MOVE *last_move, int treedepth, int targetpen);
