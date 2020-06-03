#include "GateStrategy.h"

namespace bungie {
int GateStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();

	if (rotated == 0) {
		//Move 0.45m forwards to reach the rock
		controller.MoveUnits(0.45, 'f', 1.5);
		controller.Drive('r', 10);
		rotated += 1;
	}
	else if (rotated >= 620) {
		//Move 0.45m forwards to reach the container
		controller.MoveUnits(0.45, 'f', 1.5);
	}
	else {
		//Rotate 90 deg to the right
		controller.Drive('r', 10);
		rotated += 1;
	}
	return 0;
}
}