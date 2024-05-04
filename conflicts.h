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

void InitConflicts(CONFLICTS *c);
void DelConflicts(CONFLICTS *c);
void AddPenalties(CONFLICTS *c);
void InsertPenalty(CONFLICTS *c, int i, int p);
void InitPenalty(PENALTY *p, int penalty);

// Returns a pointer to the item in c->pen
PENALTY *FindPenalty(CONFLICTS *c, int penalty);

// Increases p->cflts to CONFLICT_INC
void AddConflicts(PENALTY *p);
void InsertConflict(PENALTY *p, const BitString c, const BitString no_reach);
void AddConflict(CONFLICTS *c, const BitString conflict, const BitString no_reach,int penalty);

BOOLTYPE  GetPriorPostPen(MAZE *maze, int penalty, int *prior, int *post);
int  GetPenalty(MAZE *maze, int targetpen);


void PrintConflicts(MAZE *maze, const CONFLICTS *c);

void AddTestedPen(CONFLICTS *c, const BitString relevant, const BitString stones, 
				PHYSID manpos, PHYSID stonepos, int goodtested);
void AddTestedDead(CONFLICTS *c, const BitString relevant, const BitString stones,
				PHYSID manpos, PHYSID stonepos);
/* return position+1 of pattern tested */
/* 0 if was not searched before */
int WasTestedPen(const CONFLICTS *c, const BitString stones, const BitString reach,
				PHYSID stonepos);
/* return position+1 of pattern tested in c->deadtested */
/* 0 if was not searched before */
int WasTestedDead(const CONFLICTS *c, const BitString stones, const BitString reach,
				PHYSID stonepos);

void PrintConflict(const CONFLICTS *c, int peni, int coni );
void PrintTested(const MAZE *maze, int num);
void PrintMatches(const MAZE *maze);

void RemoveConflict( CONFLICTS *c, int peni, int coni);
BOOLTYPE  RemoveDuplicates( CONFLICTS *c, int penalty,
		      const BitString pattern, const BitString no_reach );
void RemoveWorst( CONFLICTS *c );

