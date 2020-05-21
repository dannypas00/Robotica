#include "TransportRockStrategy.h"
#include <iostream>

TransportRockStrategy::TransportRockStrategy()
{
	//measureWeightController;
}

int TransportRockStrategy::ExecuteStrategy()
{
	MeasureWeightController aapp;
	std::cout << aapp.a;
	return 0;
}

void TransportRockStrategy::PickupObject()
{
}

void TransportRockStrategy::PlaceObject()
{
}

void TransportRockStrategy::NavigateToPosition()
{
}