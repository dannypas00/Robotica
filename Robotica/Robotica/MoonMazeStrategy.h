#pragma once
#include "MIStrategy.h"
#include "RobotController.h"

class MoonMazeStrategy : public MIStrategy {
public:
	MoonMazeStrategy();

	int ExecuteStrategy() override;
};
