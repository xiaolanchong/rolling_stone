#pragma once

#include <gtest/gtest.h>
#include <vector>
#include <string>

struct Position
{
   int x, y;
};

struct Step
{
   Position boxFrom;
   Position boxTo;
   Position manFrom;
};

using Path = std::vector<Step>;

class RollingStoneTest : public testing::Test
{
protected:
   RollingStoneTest();

   Path FindPath(const std::string& mazeStr);
};
