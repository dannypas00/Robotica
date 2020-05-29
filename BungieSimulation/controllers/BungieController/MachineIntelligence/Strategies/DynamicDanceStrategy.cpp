#include "DynamicDanceStrategy.h"
#include <iostream>

namespace bungie {
DynamicDanceStrategy::DynamicDanceStrategy() {
}

int DynamicDanceStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();

	// Music file
	std::string musicFile = "muziekjes.mp3";

	// Start dance
	//controller.Dance();

	//Done
	return 0;
}
}