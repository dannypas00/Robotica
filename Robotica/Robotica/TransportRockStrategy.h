#pragma once

#include "MeasureWeightController.h"

class TransportRockStrategy {
private:
	MeasureWeightController measureWeightController;
public:
	int ExecuteStrategy();

	void PickupObject();

	void PlaceObject();

	void NavigateToPosition();
};