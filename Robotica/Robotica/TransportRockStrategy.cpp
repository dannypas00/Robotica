#include "TransportRockStrategy.h"
#include "VisionController.h"
#include <iostream>


TransportRockStrategy::TransportRockStrategy()
{
	//measureWeightController;
}

int TransportRockStrategy::ExecuteStrategy()
{
	//Eerst 0.15 meter naar voren
	//Wacht tot vision steen ziet
	//Geef een seintje aan aansturing om te beginnen met steen oppakken
	VisionController vision;
	vision.Subscribe("Stone");
	RobotController controller = RobotController();
	controller.Move(0.15, 1);
	while (false)	//Check while stone is not detected yet
	{
		std::cout << "I don't see";
	}
	int visionStone = vision.See(); //Temporarily a vector to substitute the vision object struct
	controller.GatherObject(false, 1, visionStone);
	//eerst 0.50 meter naar voren
	//wacht tot vision bakje ziet
	//geef seintje aan aansturing om de steen in die bak te leggen
	vision.Subscribe("Container");
	controller.Move(0.50, 1);
	while (false)
	{
		std::cout << "Where is my container?";
	}
	int visionContainer = vision.See();
	controller.PutStone(visionContainer);
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