
#include "RollingStoneTest.h"

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
	EXPECT_EQ(path[0].boxFrom.y, 2);
	EXPECT_EQ(path[0].boxTo.x, 2);
	EXPECT_EQ(path[0].boxTo.y, 1);
}

