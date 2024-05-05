
#include "RollingStoneTest.h"

#if 0

extern "C"{
#include "../src/board.h"
#include "../src/init.h"

	IDA  MainIdaInfo;
	MAZE Maze;
}
#endif

TEST_F(RollingStoneTest, OneMoveTest)
{
	const std::string mazeStr =
R"(#####
# . #
# $ #
# @ #
#####
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 1);
	EXPECT_EQ(path[0].boxFrom.x, 2);
	EXPECT_EQ(path[0].boxFrom.x, 2);
	EXPECT_EQ(path[0].boxTo.x, 2);
	EXPECT_EQ(path[0].boxTo.x, 1);
}

TEST_F(RollingStoneTest, Level1Test)
{
	const std::string mazeStr =
R"(    #####
    #   #
    #$  #
  ###  $##
  #  $ $ #
### # ## #   ######
#   # ## #####  ..#
# $  $          ..#
##### ### #@##  ..#
    #     #########
    #######
)";

	auto path = FindPath(mazeStr);
	ASSERT_EQ(path.size(), 44);
}