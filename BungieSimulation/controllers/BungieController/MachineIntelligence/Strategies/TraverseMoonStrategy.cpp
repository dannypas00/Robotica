#include "TraverseMoonStrategy.h"
#include <iostream>

namespace bungie {
int TraverseMoonStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	controller.DriveUnits('f', 0.5, 8);
	return 0;
}
}