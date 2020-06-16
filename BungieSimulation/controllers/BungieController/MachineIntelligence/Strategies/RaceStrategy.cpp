#include "RaceStrategy.h"

namespace bungie {
int RaceStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();

	std::cout << "[ACTION] Running MoonRace!" << std::endl;
	
	// Move forwards to win race
	// TODO: implement when we know what we need to do (no model provided from school yet)
	controller.DriveUnits('f', 10, 20);

	// Done
	return 0;
}
}