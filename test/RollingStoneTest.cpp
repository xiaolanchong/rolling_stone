
#include "RollingStoneTest.h"

extern "C"
{
#include "../src/board.h"
#include "../src/init.h"

	IDA  MainIdaInfo;
	MAZE Maze;
}

RollingStoneTest::RollingStoneTest()
{
	InitRandom();
	init_opts();
	InitBS();
	InitIDA(&MainIdaInfo);
	IdaInfo = &MainIdaInfo;

	IdaInfo->PrintPriority = -1000;
#ifdef _MSC_VER
	LoadTrees("../../../../" DL1PATHFILE, "../../../../" DL2PATHFILE);
#else
	LoadTrees(DL1PATHFILE, DL2PATHFILE);
#endif
}

Path RollingStoneTest::FindPath(const std::string& mazeStr)
{
	InitMaze(&Maze);

	MainIdaInfo.IdaMaze = &Maze;
	ReadMazeFromBuffer(mazeStr.c_str(), mazeStr.size(), &Maze);
	IdaInfo = &MainIdaInfo;
	MOVE solution[ENDPATH] = {};
	int result = StartIda(YES, solution);
	if (result < 0 || result >= ENDPATH)
		return {};

	Path path;
	path.reserve(100);
	for (size_t i = 0; i < ENDPATH; ++i)
	{
		if (ISDUMMYMOVE(solution[i]))
			break;
		Position boxFrom;
		ToScreenCoord(solution[i].from, &boxFrom.x, &boxFrom.y);
		Position boxTo;
		ToScreenCoord(solution[i].to, &boxTo.x, &boxTo.y);
		Position manFrom;
		ToScreenCoord(solution[i].man, &manFrom.x, &manFrom.y);
		path.push_back({ std::move(boxFrom), std::move(boxTo), std::move(manFrom) });
	}
	return path;
}
