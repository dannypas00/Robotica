#pragma once

#include "MeasureWeightController.h"
#include "MIStrategy.h"
#include "RobotController.h"

class TransportRockStrategy : public MIStrategy{
public:
	MeasureWeightController measureWeightController;
	
	TransportRockStrategy();
	
	int ExecuteStrategy();

	void PickupObject();

	void PlaceObject();

	void NavigateToPosition();
};