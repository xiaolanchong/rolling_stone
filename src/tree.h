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

typedef enum { BlancSquare, StoneSquare, WallSquare} SQUARE;

// Deadlock entry
typedef int DLENTRY[3];

// Dead lock support
typedef struct {
	int    x_ofs;	   /* both of these are in -1 1's */
	int    y_ofs;	   /* and measured as from the stone in the midle */
	int    direction_not_used;  /* from which direction was the stone moved in */
	int    symetrical_not_used; /* is the patter symetrical? if yes, don't test
			    * mirror */
	int    deadlocks_not_used;
	int    unknowns_not_used;
	int    irrelevants_not_used;
	int    visited_not_used;
	const MAZE  *maze_not_used;
} DLSUP;

// Dead lock tree
typedef struct {
	const DLSUP   *Sup;
	const DLENTRY *Array;
	size_t	 CurrentLength;
} TREE;

// Loads the trees from the files
void LoadTrees(const char *sup1filename, const char* sup2filename);

/* use the tree to determine if pushing a stone to "pos" in "direction" in
 * maze creates a deadlock.
 * Returns YES - deadlock found or NO - free to go.
 */
BOOLTYPE DeadTree(const MAZE *maze, PHYSID pos, DIRECTION direction);
