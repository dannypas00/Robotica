#ifndef MOON_MAZE_STRATEGY
#define MOON_MAZE_STRATEGY
#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class MoonMazeStrategy : public MIStrategy {
public:
	MoonMazeStrategy();

	int ExecuteStrategy() override;
};
}

#endif