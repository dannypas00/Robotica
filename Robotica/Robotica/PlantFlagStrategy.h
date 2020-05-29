#pragma once
#include "MIStrategy.h"
#include "RobotController.h"

class PlantFlagStrategy : public MIStrategy {
public:
	PlantFlagStrategy();

	int ExecuteStrategy() override;
};


