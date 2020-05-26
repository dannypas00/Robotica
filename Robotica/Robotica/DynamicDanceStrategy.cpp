#include "DynamicDanceStrategy.h"
#include "VisionController.h"
#include <iostream>

DynamicDanceStrategy::DynamicDanceStrategy() {
}

int DynamicDanceStrategy::ExecuteStrategy()
{
	RobotController controller = RobotController();

	// Music file
	std::string musicFile = "muziekjes.mp3";

	// Start dance
	controller.Dance();

	//Done
	return 0;
}