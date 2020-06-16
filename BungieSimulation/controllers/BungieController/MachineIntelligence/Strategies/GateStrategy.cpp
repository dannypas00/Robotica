#include "GateStrategy.h"

namespace bungie {
int GateStrategy::ExecuteStrategy()
{
	RobotController& controller = RobotController::getInstance();

	std::cout << "[ACTION] Running GateStrategy!" << std::endl;
	
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