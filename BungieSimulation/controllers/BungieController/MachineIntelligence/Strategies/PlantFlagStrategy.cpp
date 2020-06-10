#include "PlantFlagStrategy.h"
#include "..\VisionController.h"
#include <iostream>

namespace bungie {
PlantFlagStrategy::PlantFlagStrategy() {
}

int PlantFlagStrategy::ExecuteStrategy()
{
	VisionController vision;
	RobotController& controller = RobotController::getInstance();

	// Subscribe to vision to get the flag
	// TODO: Implement real vision here and not hardcoded test stuff
	vision.Subscribe("Flag");
	const Vector3 flagPos = vision.See(); // Temporarily a vector to substitute the vision object struct
	
	// After we get the location of the flag, we pick it up
	// TODO: implement when arm is done
	// controller.GatherObject(false, 1, vision_flag);

	// When we are done picking up the flag we start to move towards the centre
	// TODO: Test with real hill model
	// controller.Move(HillTopCentre);

	// Once we reached the top we can plant the flag
	// TODO: Implement real vision here and not hardcoded test stuff
	vision.Subscribe("Hole");
	const Vector3 holePos = vision.See(); // Temporarily a vector to substitute the vision object struct
	
	// Drop the flag in the hole
	// TODO: implement when arm is done
	// controller.PutFlag(HillTopCentre);

	// Done
	return 0;
}
}