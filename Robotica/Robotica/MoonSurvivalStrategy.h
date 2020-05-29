#pragma once
#include "MIStrategy.h"
#include "RobotController.h"

class MoonSurvivalStrategy : public MIStrategy {
public:
	MoonSurvivalStrategy();

	int ExecuteStrategy() override;
};