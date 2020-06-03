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
	controller.Drive('r', 0.5);
	//Done
	return 0;
}
}