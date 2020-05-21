#include "RobotController.h"

RobotController RobotController::GetInstance()
{
	return RobotController();
}

void RobotController::Move(double distance, double speed)
{
	return;
}

void RobotController::GatherObject(bool liquid, double sensitivity, int object_position)	//TODO: Change int object_position to be a Vector3 when working
{
	return;
}

void RobotController::PutStone(int location)	//TODO: Change int object_position to be a Vector3 when working
{
	return;
}

RobotController::RobotController()
{
	//instance = this;
}
