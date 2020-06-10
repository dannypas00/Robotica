#include "DynamicDanceStrategy.h"
#include <iostream>

namespace bungie {
DynamicDanceStrategy::DynamicDanceStrategy() {
}

int DynamicDanceStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();

	// Prepare music file here, afterwards start to move towards the dance floor

	// Navigate forwards to the dance floor
	controller.DriveUnits('f', 0.5, 8);
	
	// Show some moves
	// TODO: Implement dance
	
	// Done
	return 0;
}
}