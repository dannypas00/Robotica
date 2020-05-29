#pragma once
#include "MIStrategy.h"
#include "RobotController.h"

class DynamicDanceStrategy : public MIStrategy {
public:
	DynamicDanceStrategy();

	int ExecuteStrategy() override;
};