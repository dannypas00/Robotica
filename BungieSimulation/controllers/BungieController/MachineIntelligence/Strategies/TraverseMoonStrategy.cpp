#include "TraverseMoonStrategy.h"
#include <iostream>

namespace bungie {
int TraverseMoonStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	std::cout << "[ACTION] Running Traverse Moon!" << std::endl;
	// Move forwards and traverse the rocks
	// TODO: Robot can handle this. But sometimes the physics glitch due to webots itself, which causes us to get stuck
	controller.DriveUnits('f', 0.5, 8);

	// Done
	return 0;
}
}