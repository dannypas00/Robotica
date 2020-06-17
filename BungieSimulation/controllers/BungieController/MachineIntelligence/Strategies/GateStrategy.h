#ifndef GATE_STRATEGY
#define GATE_STRATEGY

#include "..\MIStrategy.h"
#include "..\..\RobotController\RobotController.hpp"

namespace bungie {
class GateStrategy : public MIStrategy {
public:
	int ExecuteStrategy() override;

private:
	const double toRotate = 467;
	const double toMove = 450;
	bool hasRotatedFully;
	double rotated = 0;
	double distanceMoved = 0;
	double wait = 0;
};
}

#endif