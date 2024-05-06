
#include "RollingStoneTest.h"
#include <vector>
#include <memory>
#include <mutex>

extern "C"
{
#include "../src/board.h"
#include "../src/init.h"

	IDA  MainIdaInfo;
}

namespace
{
	std::once_flag initGlobalVarsAndIdaFlag;

	void initEnvironment()
	{
		InitRandom();
		init_opts();
		InitBS();

		InitIDA(&MainIdaInfo);
		IdaInfo = &MainIdaInfo;
		MainIdaInfo.PrintPriority = -1000;

#ifdef _MSC_VER
		LoadTrees("../../../../" DL1PATHFILE, "../../../../" DL2PATHFILE);
#else
		LoadTrees(DL1PATHFILE, DL2PATHFILE);
#endif
	}
}

RollingStoneTest::RollingStoneTest()
{
	std::call_once(initGlobalVarsAndIdaFlag, &initEnvironment);
}

Path RollingStoneTest::FindPath(const std::string& mazeStr)
{
	const auto Maze = std::make_unique<MAZE>();
	InitMaze(Maze.get());

	MainIdaInfo.IdaMaze = Maze.get();
	IdaInfo = &MainIdaInfo;
	ReadMazeFromBuffer(mazeStr.c_str(), mazeStr.size(), Maze.get());
	std::vector<MOVE> solution(ENDPATH);
	int result = StartIda(YES, &solution[0]);
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
