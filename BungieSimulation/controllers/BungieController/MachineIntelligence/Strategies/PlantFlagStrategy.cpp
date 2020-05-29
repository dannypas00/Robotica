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

	// This is the centre of the hilltop that we need to navigate to, this position is set
	Vector3 HillTopCentre = Vector3(1,2,3);

	// Subscribe to the to vision with the result
	vision.Subscribe("Flag");
	const Vector3 vision_flag = vision.See(); // Temporarily a vector to substitute the vision object struct
	// Pick up our flag
	
	//controller.GatherObject(false, 1, vision_flag);

	// When we are done picking up the flag we start to move towards the centre
	// controller.Move(HillTopCentre);

	//Once we reached the top we can plant the flag
	vision.Subscribe("Hole");
	//Drop flag
	
	//controller.PutFlag(HillTopCentre);

	//Done
	return 0;
}
}