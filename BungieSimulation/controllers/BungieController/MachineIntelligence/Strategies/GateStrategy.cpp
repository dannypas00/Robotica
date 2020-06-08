#include "GateStrategy.h"

namespace bungie {
int GateStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	//Drive 0.45 units forwards
	controller.DriveUnits('f', 0.5, 0.45);
	//Rotate 45 DEG right
	//controller.Drive('r', 0.5);
	//Drive 0.45 units forwards
	controller.DriveUnits('f', 0.5, 0.45);
	return 0;
}
}