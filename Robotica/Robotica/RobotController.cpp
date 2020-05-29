#include "RobotController.h"

RobotController RobotController::GetInstance()
{
	return RobotController();
}

void RobotController::Move(double distance, double speed)
{
	return;
}

void RobotController::GatherObject(bool liquid, double sensitivity, Vector3 object_position)	//TODO: Change int object_position to be a Vector3 when working
{
	return;
}

void RobotController::PutStone(Vector3 location)	//TODO: Change int object_position to be a Vector3 when working
{
	return;
}

void RobotController::PutFlag(Vector3 location)	//TODO: Change int object_position to be a Vector3 when working
{
	return;
}

std::string RobotController::GetQRResult()	//TODO: change this to return actual gotten value from qr scan
{
	return "SCHOPPEN";
}

void RobotController::Dance()
{
	return;
}

RobotController::RobotController()
{
	//instance = this;
}
