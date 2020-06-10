#include "GateStrategy.h"

namespace bungie {
int GateStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();
	
	// Drive 0.45 units forwards
	controller.DriveUnits('f', 0.5, 0.45);
	
	// Rotate so we can leave
	controller.Rotate(110);
	
	// Drive 0.45 units forwards
	controller.DriveUnits('f', 0.5, 0.45);

	// Done
	return 0;
}
}