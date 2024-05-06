
# Rolling Stone

Rolling Stone is an application developed by Andreas Junghanns. 
This is a solution to Sokoban game. See https://webdocs.cs.ualberta.ca/~games/Sokoban .
This is an attempt to revive the source files and organize into a meaningfull interface/implementation version.
/src directory is a renewed application.
/test directory is Google test suites to demonstrate the application and a way to reuse the code for your own solutions.

## Maze format

 \# - wall
 @ - man
 +, % - man on a goal
 $, A-Z - crate (stone)
 \*, a-z - crate (stone) on a goal
 . - goal
 =, <space> - empty place

Maximum goals: 34
Maximum crates: 34
Maximum maze width: 20
Maximum maze height: 16

## Terms and definitions

Described at http://sokobano.de/wiki/index.php?title=Solver

### Internal coordinate system

(0, 0) is the bottom left corner, but the maze(level) is aligned to the top left.

Y ^

F  #####
E###   ###
D#.. $$$ #
C#.  @   #
B###     #
A  #######
9
..
0123456789A..J  X->

### Notes about Windows version

The initial application was compiled under \*Nix system with GCC and was ported to Windows and VS2022.
However not all functionality can be easily transferred. The following parts are dummies: 
- getrusage call (to measure the time spent by the app). See https://pubs.opengroup.org/onlinepubs/009696699/functions/getrusage.html
- setitimer call (to interrupt search by timeout). See https://pubs.opengroup.org/onlinepubs/9699919799.2018edition/functions/getitimer.html

## Other References

- Wikipedia, article on Sokoban: https://en.wikipedia.org/wiki/Sokoban
- Sokoban solving specialized wiki: http://sokobano.de/wiki/index.php?title=Main_Page
- Online JS game: https://sokoban-solver-statistics.sourceforge.io/
- Other solvers statistics: https://sokoban-solver-statistics.sourceforge.io/statistics/LargeTestSuite/
