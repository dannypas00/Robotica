#pragma once

#include "Vector3.h"

class RobotController {
public:
	static RobotController GetInstance();
	void Move(double distance, double speed);
	void UseBreaks(double strength);
	void GatherObject(bool liquid, double sensitivity, Vector3 object_position);
	void PutStone(Vector3 location);
	void PutFlag(Vector3 location);
	std::string GetQRResult();
	void Dance();
	RobotController();
private:
	
	static RobotController* instance;
};