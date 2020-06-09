#include "DynamicDanceStrategy.h"
#include <iostream>

namespace bungie {
DynamicDanceStrategy::DynamicDanceStrategy() {
}

int DynamicDanceStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();

	// Do somehting with music here

	// Start dance
	controller.DriveUnits('f', 0.5, 8);
	// controller.Drive('r', 0.5);
	//Done
	return 0;
}
}