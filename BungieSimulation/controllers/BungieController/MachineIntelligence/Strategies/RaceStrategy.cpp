#include "RaceStrategy.h"

namespace bungie {
int RaceStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	if (distanceMoved < toMove) {
		//Move 0.45m forwards to reach the rock
		controller.DriveUnits('f', 10, 20);
	}
	return 0;
}
}