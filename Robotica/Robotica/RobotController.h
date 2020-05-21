#pragma once

#include "Vector3.cpp"

class RobotController {
private:
	RobotController* instance;

public:
	RobotController GetInstance();
	void Drive(char direction);
	void UseBreaks(double strength);
	void GatherObject(bool liquid, double sensitivity, Vector3 object_position);
	void Dance();
};