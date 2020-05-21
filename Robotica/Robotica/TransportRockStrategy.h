#pragma once

#include "MeasureWeightController.h"

class TransportRockStrategy {
public:
	MeasureWeightController measureWeightController;
	
	TransportRockStrategy();
	
	int ExecuteStrategy();

	void PickupObject();

	void PlaceObject();

	void NavigateToPosition();
};