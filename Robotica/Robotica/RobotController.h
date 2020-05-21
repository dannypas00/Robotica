#pragma once

#include "Vector3.cpp"

class RobotController {
public:
	static RobotController GetInstance();
	void Move(double distance, double speed);
	void UseBreaks(double strength);
	void GatherObject(bool liquid, double sensitivity, int object_position);
	void PutStone(int location);
	void Dance();
	RobotController();
private:
	
	static RobotController* instance;
};