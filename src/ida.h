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

extern IDA *IdaInfo;

/* Sets up all data structures and repeatedly calls ida with increasing
   threshold to guarantee optimal solutions, returns 0 if solution found
   otherwise the smallest heuristic value seen at any leaf node if this is
   ENDPATH there is no solution - deadlock 
   out_solution is optional and must contain at least ENDPATH items, DummyMove ends the path
   */
int   StartIda(BOOLTYPE nomacro, MOVE* out_solution);

void  PrintSolution(MOVE* out_solution);
BOOLTYPE   IsGoalNodeNorm(int g);
int   Ida(int depth, int g);
void  SetManStoneSquares(MAZE *maze, MOVE bestmove);
BOOLTYPE   AbortSearch();
void  InitIDA(IDA *ida);
 
BOOLTYPE   DistantSquares(PHYSID s1, PHYSID s2, short crowding);
BOOLTYPE   DistantMove(const MAZE *maze, const MOVE *last_move, const MOVE *test_move);
void  SetLocalCut(int k, int m, int d);
BOOLTYPE   RegisterMove(MOVE *move, int depth);
short Crowding(const MAZE *maze, PHYSID sq);
