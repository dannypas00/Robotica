#include "TransportRockStrategy.h"
#include <iostream>

namespace bungie {
TransportRockStrategy::TransportRockStrategy(MeasureWeightController _measureWeightController)
{
	measureWeightController = _measureWeightController;
}

int TransportRockStrategy::ExecuteStrategy()
{
	VisionController vision;
	RobotController& controller = RobotController::getInstance();

	// TODO: Implement and test this after the arm is done & we have the correct models

	// Subscribe to the vision objects for the stone and the container to put the stone into
	vision.Subscribe("Stone");
	vision.Subscribe("Container");

	// Move 0.15m forwards to reach the rock
	controller.DriveUnits('f', 1.0, 0.15);
	// Wait for the rock to be detected by vision
	const Vector3 vision_stone = vision.See(); //Temporarily a vector to substitute the vision object struct
	// Pick up the rock

	// controller.GatherObject(false, 1, vision_stone);
	
	// Move 0.5m forwards to reach the container
	controller.DriveUnits('f', 1.0, 0.5);
	// Wait for the container to be detected by vision
	const Vector3 vision_container = vision.See();//Temporarily a vector to substitute the vision object struct
	// Put the rock into the container

	// controller.PutStone(vision_container);
	return 0;
}
}