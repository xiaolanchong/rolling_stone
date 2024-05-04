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

extern MAZE *DeadMaze;
extern MAZE *DInsertMaze;

// Returns number of moves
int  DeadMoveOrdering(int depth, int number_moves);
void DeadDeactivateStones(MAZE *maze, const BitString visible);
BOOLTYPE  DeadMoveSuspected(const MAZE *maze, const MOVE *last_move);
PHYSID FindClosestPosMan(const MAZE *maze, const BitString squares,
	const BitString already_visible);
PHYSID FindClosestPosStone(const MAZE *maze, const BitString squares, 
		      const BitString already_visible);
void DeadMiniConflict(int minimize);

/* Try to find out if we can move this stone still to a goal,
   include those that might be creating a deadlock,
   after finding that this is a deadlock, find the minimal set of
   stones belonging to a deadlock */
BOOLTYPE  DeadMove(MAZE *maze, const MOVE *last_move, int treedepth);

/* Sets up all data structures and repeatedly calls ida with increasing
   threshold to guarantee optimal solutions, returns 0 if solution found
   otherwise the increase of maze->h by Threshold, if this is
   ENDPATH there is no solution - deadlock */
int  DeadStartIda();

/* the procedure that does the work at one node. it returns
   X - the smallest h underneath this node */
int  DeadIda(int treedepth, int g);

/* this is a routine that makes a STONE move, not merely a man move like
 * DoMove. It will just put the man to the new location */
int  DeadMakeMove(MAZE *maze, const MOVE *move, UNMOVE *ret, int targetpen);

void  DeadUnMakeMove(MAZE *maze, const UNMOVE *unmove, int targetpen);

/* This is a fast and bad lower bound - just the closest goal - since we
remove stones when we hit goals */
int  DeadLowerBound(MAZE *maze, int targetpen);

/* Update lowerbound after move to square pos */
int  DeadUpdateLowerBound(MAZE *maze, PHYSID pos, int targetpen);
