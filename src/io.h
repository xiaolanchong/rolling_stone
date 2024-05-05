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

extern int PosNr;

void ReadMaze(FILE *fp, MAZE *maze );
void ReadMazeFromBuffer(const char* buffer, size_t size, MAZE* maze);
void PrintMaze(const MAZE *maze);
const char *PrintMove(MOVE move);
const char *HumanMove(MOVE move);
void PrintBit2Maze(const MAZE *maze, const BitString marks);
void PrintBit3Maze(const MAZE *maze, const BitString marks, const BitString mark2, PHYSID manpos);
// 0,0 - topleft of the maze
void ToScreenCoord(PHYSID pos, int* x, int* y);
